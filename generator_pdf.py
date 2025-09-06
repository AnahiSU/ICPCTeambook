import subprocess
import os

def get_sections():
    sections = []
    section_name = None 
    with open('contents.txt', 'r') as f:
        for line in f:
            if '#' in line: line = line[:line.find('#')]
            line = line.strip()
            if len(line) == 0: continue
            if line[0] == '[':
                if section_name is not None:
                    sections.append((section_name, subsections))
                section_name = line[1:-1]
                subsections = []
            else:
                tmp = line.split('\t', 1)
                if len(tmp) == 1:
                    raise ValueError('Subsection parse error: %s' % line)
                filename = tmp[0]
                subsection_name = tmp[1]
                if subsection_name is None:
                    raise ValueError('Subsection given without section')
                subsections.append((filename, subsection_name))
    return sections

def get_style(filename):
    ext = filename.lower().split('.')[-1]
    if ext in ['c', 'cc', 'cpp', 'h']:
        return 'cpp'
    elif ext in ['java']:
        return 'java'
    elif ext in ['py']:
        return 'py'
    else:   
        return 'txt'

def texify(s):
    return s

def get_tex(sections, titulo="Deja de dudar Leonel *grosería*", autor="Universidad Mayor de San Simón", fecha="\\today"):
    tex = ''
    # ----------------- Preambulo -----------------
    tex += '\\documentclass[twocolumn]{article}\n'
    tex += '\\usepackage[utf8]{inputenc}\n'
    tex += '\\usepackage[T1]{fontenc}\n'
    tex += '\\usepackage{xcolor}\n'
    tex += '\\usepackage{listings}\n'
    tex += '\\usepackage[a4paper,landscape,margin=1in]{geometry}\n\n'
    tex += '\\setlength{\\columnsep}{20pt}\n'
    tex += '\\setlength{\\columnseprule}{0.4pt}\n\n'

    # ----------------- Definicion de estilos -----------------
    tex += r'''
\lstdefinestyle{cpp}{
    language=C++,
    basicstyle=\ttfamily\small,
    keywordstyle=\color{blue}\bfseries,
    commentstyle=\color{green!50!black},
    stringstyle=\color{orange},
    showstringspaces=false,
    breaklines=true
}

\lstdefinestyle{java}{
    language=Java,
    basicstyle=\ttfamily\small,
    keywordstyle=\color{purple}\bfseries,
    commentstyle=\color{gray},
    stringstyle=\color{orange},
    showstringspaces=false,
    breaklines=true
}

\lstdefinestyle{py}{
    language=Python,
    basicstyle=\ttfamily\small,
    keywordstyle=\color{blue}\bfseries,
    commentstyle=\color{green!50!black},
    stringstyle=\color{orange},
    showstringspaces=false,
    breaklines=true
}
''' + '\n'

    # ----------------- Comienzo del documento -----------------
    tex += '\\begin{document}\n\n'

    # ----------------- Titulo y fecha -----------------
    tex += '\\title{%s}\n' % titulo
    tex += '\\author{%s}\n' % autor
    tex += '\\date{%s}\n' % fecha
    tex += '\\maketitle\n\n'

    # ----------------- Tabla de contenidos -----------------
    tex += '\\tableofcontents\n'
    tex += '\\newpage\n\n'

    # ----------------- Secciones y subsecciones -----------------
    for (section_name, subsections) in sections:
        tex += '\\section{%s}\n' % section_name
        for (filename, subsection_name) in subsections:
            tex += '\\subsection{%s}\n' % subsection_name
            tex += '\\raggedbottom\\lstinputlisting[style=%s]{%s}\n' % (get_style(filename), filename)
            tex += '\\hrulefill\n'
        tex += '\n'

    # ----------------- Fin del documento -----------------
    tex += '\\end{document}\n'
    return tex

if __name__ == "__main__":
    sections = get_sections()
    tex = get_tex(sections)
    with open('contents.tex', 'w') as f:
        f.write(tex)
    with open('notebook.tex', 'w') as f:
        f.write(tex)
    latexmk_options = ["latexmk","-pdf", "notebook.tex"]
    subprocess.call(latexmk_options)
    remove_files = ["notebook.fls", "notebook.aux", "notebook.fdb_latexmk", 
    "notebook.log", "notebook.out", "notebook.toc"]
    for file in remove_files:
        if os.path.exists(file):
            os.remove(file)

