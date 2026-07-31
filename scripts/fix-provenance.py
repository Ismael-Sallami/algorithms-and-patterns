#!/usr/bin/env python3
"""Repoints every provenance link at the file it actually came from.

Eight repositories were renamed and reorganised at the same time. GitHub
redirects the name, so the links look alive and then 404 on the path. A rename
of the repository name alone would not fix them: the path moved too, and in
several cases so did the line numbers.

So the mapping is done by content, not by name. The body of each extracted file
is searched for, verbatim, in the working copy of the repository it now lives in;
where it turns up gives the path, the first line and the last line at once. What
cannot be resolved that way — notebooks, which are JSON, and extracts stitched
from non-contiguous slices — is listed in TABLA.

    python3 scripts/fix-provenance.py --dry-run
    python3 scripts/fix-provenance.py

@author Ismael Sallami Moreno
"""
import argparse
import re
import sys
from pathlib import Path

BASE = Path(__file__).resolve().parent.parent

# Old repository name -> new one.
RENOMBRADOS = {
    "Parcherckers": "parchis-ai",
    "Practica2_IA": "rescue-agents",
    "MH-Practices": "metaheuristics",
    "SCD-Concurrency-MPI": "concurrency-mpi",
    "TDA-Imagen": "image-adt",
    "Air-lines-Project": "airline-routes-adt",
    "AA-practices": "machine-learning-practices",
    "DDSI": "oracle-dbms-project",
    "ModeloEconometrico": "econometric-model",
}

# Entries whose new path cannot be found by looking for their content.
#   entry folder -> (new repository, new path, first line)
TABLA = {
    # Notebooks are JSON with the code escaped inside, and these extracts are
    # cells concatenated in reading order, so there is no block to search for.
    "model-selection-with-cross-validation": (
        "machine-learning-practices", "src/practice-1-supervised-learning.ipynb", 1),
    "cluster-count-selection": (
        "machine-learning-practices", "src/practice-2-unsupervised-learning.ipynb", 1),
    "dbscan-epsilon-selection": (
        "machine-learning-practices", "src/practice-2-unsupervised-learning.ipynb", 1),
    "sequence-vectorisation-and-regularisation": (
        "machine-learning-practices", "src/practice-3-deep-learning.ipynb", 1),
    "seq2seq-greedy-decoding": (
        "machine-learning-practices", "src/project-seq2seq-chatbot.ipynb", 1),

    # Stitched from slices that are not contiguous, so there is no single block
    # to search for. The line is the first one of the first slice.
    "move-generation-with-collision-avoidance": (
        "rescue-agents", "src/rescatador.cpp", 528),
    "evaluation-with-dynamic-weights": ("parchis-ai", "src/AIPlayer.cpp", 940),
    "heuristic-evaluation-and-dynamic-weights": ("parchis-ai", "src/AIPlayer.cpp", 940),
    "transactional-write-path": (
        "oracle-dbms-project", "src/usuarios/functions.py", 8),

    # The published file is not the delivered one: the university account was
    # written into it and that is the one thing the source repository changed.
    "connection-lifecycle": ("oracle-dbms-project", "src/db_connection.py", 1),

    # Level 1 and 2 behaviours, which the delivery did not carry. They are kept
    # with the rest of the earlier iterations.
    "goal-directed-reactive-agent": (
        "rescue-agents", "docs/earlier-iterations/vandalo.cpp", 1),
    "minimal-reactive-agent": (
        "rescue-agents", "docs/earlier-iterations/excursionista.cpp", 1),
}

# Where the working copies are.
CLONES = [Path.home() / "tmp", Path.home() / "TEMPORAL"]

# Same file in two places: the delivery and the earlier drafts kept for the
# record. The delivery is the one the catalogue means.
PREFERENCIA = ("src/", "database/")


def raiz(repo):
    for base in CLONES:
        if (base / repo).is_dir():
            return base / repo
    return None


def cuerpo(fichero):
    """The extract without its comment header.

    The header uses the comment marker of each language: // in C++, # in Python
    and -- in SQL.
    """
    lineas = fichero.read_text(encoding="utf-8", errors="ignore").splitlines()
    i = 0
    while i < len(lineas) and (lineas[i].lstrip().startswith(("//", "#", "--")) or not lineas[i].strip()):
        i += 1
    return "\n".join(lineas[i:]).rstrip()


def buscar(bloque, destino):
    """Find the block in the repository. Returns (path, first line, last line)."""
    cabeza = "\n".join([x for x in bloque.splitlines() if x.strip()][:5])
    exactos, parciales = [], []

    for fichero in sorted(destino.rglob("*")):
        if not fichero.is_file() or ".git/" in str(fichero) or fichero.stat().st_size > 3_000_000:
            continue
        try:
            texto = fichero.read_text(encoding="utf-8")
        except (UnicodeDecodeError, OSError):
            continue

        ruta = str(fichero.relative_to(destino))
        posicion = texto.find(bloque)
        if posicion != -1:
            inicio = texto[:posicion].count("\n") + 1
            exactos.append((ruta, inicio, inicio + len(bloque.splitlines()) - 1))
            continue
        posicion = texto.find(cabeza)
        if posicion != -1:
            inicio = texto[:posicion].count("\n") + 1
            parciales.append((ruta, inicio, None))

    candidatos = exactos or parciales
    if not candidatos:
        return None
    candidatos.sort(key=lambda c: (not c[0].startswith(PREFERENCIA), c[0]))
    return candidatos[0]


def reemplazar(texto, viejo_repo, nuevo_repo, ruta, inicio, fin):
    """Rewrite every mention of the old repository and path in a chunk of text."""
    # Source line of a header: "Ismael-Sallami/<repo> -> <ruta> (...)"
    texto = re.sub(
        rf"Ismael-Sallami/{re.escape(viejo_repo)} -> \S+",
        f"Ismael-Sallami/{nuevo_repo} -> {ruta}",
        texto,
    )
    # Any URL into the old repository, with or without a line anchor.
    def url(m):
        ancla = ""
        if inicio:
            ancla = f"#L{inicio}" + (f"-L{fin}" if fin and fin != inicio and m.group(2) else "")
        return f"https://github.com/Ismael-Sallami/{nuevo_repo}/blob/main/{ruta}{ancla}"

    texto = re.sub(
        rf"https://github\.com/Ismael-Sallami/{re.escape(viejo_repo)}/blob/[^)\s\"#]+(#L(\d+)(-L\d+)?)?",
        url,
        texto,
    )
    # Backticked path in the catalogue row and in the entry README.
    texto = re.sub(
        rf"`Ismael-Sallami/{re.escape(viejo_repo)}/\S+?`",
        f"`Ismael-Sallami/{nuevo_repo}/{ruta}`",
        texto,
    )
    texto = re.sub(rf"`{re.escape(viejo_repo)}/\S+?`", f"`{nuevo_repo}/{ruta}`", texto)
    return texto


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("--dry-run", action="store_true")
    args = parser.parse_args()

    catalogo = BASE / "CATALOG.md"
    texto_catalogo = catalogo.read_text(encoding="utf-8")
    resueltas = fallidas = 0

    for entrada in sorted(BASE.glob("patterns/*/*")):
        if not entrada.is_dir():
            continue
        extractos = [f for f in entrada.iterdir() if f.name != "README.md" and f.is_file()]
        if not extractos:
            continue
        extracto = extractos[0]

        cabecera = extracto.read_text(encoding="utf-8", errors="ignore")[:1200]
        m = re.search(r"Ismael-Sallami/([A-Za-z0-9_.-]+) ->", cabecera)
        if not m:
            continue
        viejo = m.group(1)

        if entrada.name in TABLA:
            nuevo, ruta, inicio = TABLA[entrada.name]
            fin = None
        else:
            nuevo = RENOMBRADOS.get(viejo, viejo)
            destino = raiz(nuevo)
            if destino is None:
                print(f"  SIN CLON  {entrada.name} -> {nuevo}")
                fallidas += 1
                continue
            hallazgo = buscar(cuerpo(extracto), destino)
            if hallazgo is None:
                print(f"  SIN ENCAJE {entrada.name} ({viejo})")
                fallidas += 1
                continue
            ruta, inicio, fin = hallazgo

        # The header may already name the new repository while the README still
        # names the old one, so both are tried.
        nombres = {viejo} | {v for v, n in RENOMBRADOS.items() if n == nuevo}

        for fichero in (extracto, entrada / "README.md"):
            if not fichero.exists():
                continue
            antes = fichero.read_text(encoding="utf-8")
            despues = antes
            for nombre in nombres:
                despues = reemplazar(despues, nombre, nuevo, ruta, inicio, fin)
            if despues != antes and not args.dry_run:
                fichero.write_text(despues, encoding="utf-8")

        # The catalogue row. Anchored on the full folder path: matching on the
        # entry name alone would let `minimax` claim the `depth-limited-minimax`
        # row, which comes first.
        ruta_entrada = f"patterns/{entrada.parent.name}/{entrada.name}/)"
        patron_fila = re.compile(rf"^\|[^\n]*{re.escape(ruta_entrada)}[^\n]*$", re.MULTILINE)
        fila = patron_fila.search(texto_catalogo)
        if fila:
            nueva_fila = fila.group(0)
            for nombre in nombres:
                nueva_fila = reemplazar(nueva_fila, nombre, nuevo, ruta, inicio, fin)
            texto_catalogo = texto_catalogo.replace(fila.group(0), nueva_fila)
        else:
            print(f"  AVISO  {entrada.name}: sin fila en CATALOG.md")

        resueltas += 1
        print(f"  ok  {entrada.name:46s} -> {nuevo}/{ruta}  L{inicio}")

    if not args.dry_run:
        catalogo.write_text(texto_catalogo, encoding="utf-8")

    print(f"\nresueltas: {resueltas}   sin resolver: {fallidas}")
    return 1 if fallidas else 0


if __name__ == "__main__":
    sys.exit(main())
