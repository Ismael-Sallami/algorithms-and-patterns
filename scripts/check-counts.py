#!/usr/bin/env python3
"""Fails if the counters in the README do not match the directory tree.

count.py regenerates the tables; this checks that what is committed says the
same thing. Without it the step that claims the counts still match only printed
them, and the README could drift from the folders it counts.

@author Ismael Sallami Moreno
"""
import subprocess
import sys
from pathlib import Path

BASE = Path(__file__).resolve().parent.parent

generado = subprocess.run(
    [sys.executable, str(BASE / "scripts/count.py")],
    capture_output=True, text=True, check=True).stdout
readme = (BASE / "README.md").read_text(encoding="utf-8")

faltan = [linea for linea in generado.splitlines()
          if linea.startswith("| [") and linea not in readme]

total = next(l for l in generado.splitlines() if l.startswith("Total: "))
n_total = total.split()[1]
n_extraidas = total.split("(")[1].split()[0]
if f"**Total: {n_total} implementations** &mdash; {n_extraidas} extracted" not in readme:
    faltan.append(total)

if faltan:
    print("El README no coincide con el arbol. Falta o esta desfasado:")
    for linea in faltan:
        print("  " + linea)
    print("\nRegenera las tablas con:  python3 scripts/count.py")
    sys.exit(1)

print(f"Los contadores del README coinciden con el arbol ({n_total} implementaciones).")
