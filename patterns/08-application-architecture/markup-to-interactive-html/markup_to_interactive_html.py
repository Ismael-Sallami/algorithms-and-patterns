# Pattern: Transforming a markup document into interactive HTML
# Author:  Ismael Sallami Moreno
# Source:  Ismael-Sallami/md2html-testGenerator -> src/md2html/core.py (complete file)
#          https://github.com/Ismael-Sallami/md2html-testGenerator/blob/main/src/md2html/core.py#L1-L228
# Extract: verbatim, complete file. What was handed in was one 818-line script; it was later
#          split, and this is the half that does the conversion.
#          Not a standalone build. See the source repository for the
#          full build context.

"""Markdown to HTML quiz: parsing and rendering.

No tkinter here on purpose. The window lives in gui.py, so this half can be
imported and tested without a display.

@author Ismael Sallami Moreno
"""
import html
import os
import random
import re

import markdown

TEMPLATES_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "templates")

# Theme name as shown in the window -> file in templates/. The names stay in
# Spanish because they are what the user reads in the window, and the quizzes
# this tool builds are Spanish too.
TEMAS = {
    "PRO (Azul clásico)": "pro.html",
    "Navy (azul marino)": "navy.html",
    "Burdeos académico": "burgundy.html",
    "Verde pizarra": "green.html",
    "Índigo": "indigo.html",
    "Grafito": "graphite.html",
    "Ámbar": "amber.html",
    "Académico (paper)": "academic.html",
    "Terminal oscuro": "terminal.html",
    "Minimal mono": "mono.html",
    "Teal / menta": "teal.html",
    "Rosa / magenta": "pink.html",
}


def ruta_plantilla(nombre_tema):
    """Devuelve la ruta del fichero de plantilla de un tema, o None si no existe."""
    fichero = TEMAS.get(nombre_tema)
    return os.path.join(TEMPLATES_DIR, fichero) if fichero else None

# =======================================================
# 2. LÓGICA DE PROCESAMIENTO (BACKEND)
# =======================================================

def procesar_texto_md(texto_md):
    """Convierte Markdown a HTML básico usando la librería markdown"""
    try:
        html_out = markdown.markdown(texto_md, extensions=['extra'])
    except:
        html_out = texto_md
    
    if html_out.startswith('<p>') and html_out.endswith('</p>') and html_out.count('<p>') == 1:
        html_out = html_out[3:-4]
        
    return html_out

def parsear_preguntas(bloque_texto):
    """Busca preguntas formato: 1. Pregunta... - (x) Opción correcta"""
    regex_pregunta = re.compile(r'(?m)^(\d+)\.\s+(.*?)\n(?=^\d+\.|\Z)', re.DOTALL)
    regex_opcion = re.compile(r'^\s*-\s*\((x|X|\s|)\)\s*(.*)', re.MULTILINE)
    regex_explicacion = re.compile(r'^\s*>\s?(.*)')

    preguntas = []
    matches = list(regex_pregunta.finditer(bloque_texto))

    for match in matches:
        contenido_completo = match.group(2)
        lines = contenido_completo.split('\n')
        enunciado_lines = []
        opciones_raw = []
        explicacion_lines = []
        buscando_opciones = False

        for line in lines:
            m_exp = regex_explicacion.match(line)
            m_opt = regex_opcion.match(line)
            if m_exp:
                # Línea de explicación (blockquote ">"): se acumula aparte para no
                # contaminar el texto de la última opción.
                explicacion_lines.append(m_exp.group(1).strip())
            elif m_opt:
                buscando_opciones = True
                marca = m_opt.group(1).strip().lower()
                texto = m_opt.group(2).strip()
                opciones_raw.append({'marca': marca, 'texto': texto})
            else:
                if not buscando_opciones:
                    if line.strip():
                        enunciado_lines.append(line)
                else:
                    if opciones_raw and line.strip():
                        opciones_raw[-1]['texto'] += " " + line.strip()

        enunciado_final = "\n".join(enunciado_lines).strip()
        explicacion_final = " ".join(explicacion_lines).strip()
        correctas = [i for i, opt in enumerate(opciones_raw) if opt['marca'] == 'x']

        if enunciado_final and opciones_raw:
            preguntas.append({
                'enunciado': enunciado_final,
                'opciones': opciones_raw,
                'correctas': correctas,
                'explicacion': explicacion_final
            })
            
    return preguntas

def renderizar_bloque_preguntas(lista_preguntas, contador_inicial=1):
    html_acumulado = ""
    idx = contador_inicial
    
    for p in lista_preguntas:
        enunciado_html = procesar_texto_md(p['enunciado'])
        str_correctas = ",".join(map(str, p['correctas']))
        
        html_acumulado += f'<div class="question" id="q{idx}" data-correct="{str_correctas}">\n'
        html_acumulado += f'  <div class="enunciado"><strong>{idx}.</strong> {enunciado_html}</div>\n'
        html_acumulado += '  <ol type="a">\n'
        
        for i, opt in enumerate(p['opciones']):
            texto_opt_html = procesar_texto_md(opt['texto'])
            html_acumulado += f'    <li><label class="opcion-linea"><input type="checkbox" name="q{idx}" value="{i}"> {texto_opt_html}</label></li>\n'

        html_acumulado += '  </ol>\n'

        explicacion = p.get('explicacion', '')
        if explicacion:
            explicacion_html = procesar_texto_md(explicacion)
            html_acumulado += f'  <button class="btn-explicacion" onclick="toggleExplicacion(\'q{idx}\')">Ver explicación</button>\n'
            html_acumulado += f'  <div class="explicacion" id="exp-q{idx}" style="display:none">{explicacion_html}</div>\n'

        html_acumulado += '</div>\n'
        idx += 1
        
    return html_acumulado, idx

def generar_html_final(archivo_md, archivo_html, extra_info_md, usar_secciones, shuffle, plantilla_custom=None):
    with open(archivo_md, 'r', encoding='utf-8') as f:
        contenido = f.read()
        
    html_instrucciones = ""
    if extra_info_md and os.path.exists(extra_info_md):
        with open(extra_info_md, 'r', encoding='utf-8') as f:
            contenido_extra = f.read()
            html_instrucciones = markdown.markdown(contenido_extra, extensions=['extra'])

    def get_meta(key, default):
        m = re.search(rf'-\s*\*\*{key}:\*\*\s*(.+)', contenido)
        if not m: 
            m = re.search(rf'\*\s*\*\*{key}:\*\*\s*(.+)', contenido)
        return m.group(1).strip() if m else default

    titulo_doc = "Test Generado"
    m_tit = re.search(r'^#\s*(.+)', contenido, re.MULTILINE)
    if m_tit: 
        titulo_doc = m_tit.group(1).strip()
    
    autor = get_meta("Autor", "Desconocido")
    desc = get_meta("Descripción", "")
    titulacion = get_meta("Titulación", "")

    html_cuerpo = ""
    contador = 1
    
    if usar_secciones:
        # CORRECCIÓN: Patrón regex correcto para comentarios HTML
        partes = re.split(r'<!--\s*(.+?)\s*-->', contenido, flags=re.DOTALL)
        
        # partes[0] es el contenido antes del primer comentario
        if len(partes) > 0 and partes[0].strip():
            preguntas = parsear_preguntas(partes[0])
            if preguntas:
                if shuffle: 
                    random.shuffle(preguntas)
                bloque, contador = renderizar_bloque_preguntas(preguntas, contador)
                html_cuerpo += bloque
        
        # Procesar pares: [título_comentario, contenido_siguiente]
        i = 1
        while i < len(partes):
            if i >= len(partes):
                break
                
            titulo_secc = partes[i].strip() if i < len(partes) else ""
            contenido_secc = partes[i + 1] if (i + 1) < len(partes) else ""
            
            if titulo_secc:
                html_cuerpo += f'<h2>{titulo_secc}</h2>\n'
            
            if contenido_secc.strip():
                preguntas = parsear_preguntas(contenido_secc)
                if preguntas:
                    if shuffle: 
                        random.shuffle(preguntas)
                    bloque, contador = renderizar_bloque_preguntas(preguntas, contador)
                    html_cuerpo += bloque
            
            i += 2
                
    else:
        contenido_limpio = re.sub(r'<!--.*?-->', '', contenido, flags=re.DOTALL)
        preguntas = parsear_preguntas(contenido_limpio)
        if shuffle: 
            random.shuffle(preguntas)
        bloque, contador = renderizar_bloque_preguntas(preguntas, contador)
        html_cuerpo += bloque

    if plantilla_custom and os.path.exists(plantilla_custom):
        # Plantilla personalizada elegida por el usuario.
        plantilla_path = plantilla_custom
    else:
        # La plantilla PRO por defecto. Antes se reescribia en cada ejecucion
        # desde una constante de 450 lineas dentro del codigo; ahora vive en
        # templates/pro.html, que es el mismo fichero que exporta la version web.
        plantilla_path = os.path.join(TEMPLATES_DIR, "pro.html")

    with open(plantilla_path, "r", encoding="utf-8") as f:
        template_str = f.read()
        
    final_html = template_str.replace("{{TITULO}}", titulo_doc)
    final_html = final_html.replace("{{AUTOR}}", autor)
    final_html = final_html.replace("{{TITULACION}}", titulacion)
    final_html = final_html.replace("{{DESCRIPCION}}", desc)
    final_html = final_html.replace("{{LISTA_INFO}}", html_instrucciones)
    final_html = final_html.replace("{{PREGUNTAS_HTML}}", html_cuerpo)
    
    with open(archivo_html, "w", encoding="utf-8") as f:
        f.write(final_html)
