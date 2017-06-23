=================================================
Install python packages
=================================================
easy_install pillow
easy_install blockdiag
easy_install sphinx (pip install sphinx)
pip install sphinxcontrib-actdiag sphinxcontrib-blockdiag sphinxcontrib-nwdiag sphinxcontrib-seqdiag
pip install sphinx_rtd_theme
easy_install pandas
or (https://pypi.python.org/pypi/pandas/0.15.2/#downloads pandas-0.15.2.win32-py2.7.exe)



=================================================
SPHINX
=================================================
-------------------------------
Create sphinx project
sphinx-quickstart
> Separate source and build directories (y/n) [n]: y
> Project name: Functional Process Specification
> Author name(s): Miki Sato
> Project version []: 0.1



=================================================
CONFIG
=================================================
Edit "conf.py"
------ Theme ------
html_theme = 'sphinx_rtd_theme'

#html_theme = 'classic'
#html_theme_options = {
#    "rightsidebar": "True",
#    "relbarbgcolor": "black"
#}

#html_theme = 'scrolls'
#html_theme_options = {
#    "headerbordercolor": ""
#    "subheadlinecolor": ""
#    "linkcolor": "blue"
#    "visitedlinkcolor": ""
#    "admonitioncolor": ""
#}

html_static_path = ['_static']
html_style = 'css/my_theme.css'


------ blockdiag ------
extensions = [
    'sphinxcontrib.blockdiag',
    'sphinxcontrib.seqdiag',
    'sphinxcontrib.actdiag',
    'sphinxcontrib.nwdiag',
    'sphinxcontrib.rackdiag',
    'sphinxcontrib.packetdiag',
]

blockdiag_html_image_format = 'PNG'
seqdiag_html_image_format = 'PNG'
actdiag_html_image_format = 'PNG'
nwdiag_html_image_format = 'PNG'
rackiag_html_image_format = 'PNG'
packetdiag_html_image_format = 'PNG'


------ latex ------
latex_docclass = {'manual': 'jsbook'}

latex_elements = {
    # The paper size ('letterpaper' or 'a4paper').
    #
    'papersize': 'letterpaper',

    # The font size ('10pt', '11pt' or '12pt').
    #
    'pointsize': '10pt',

    # Additional stuff for the LaTeX preamble.
    #
    # 'preamble': '',

    # Latex figure (float) alignment
    #
    # 'figure_align': 'htbp',

    'transition': '',
    'extraclassoptions': ',openany,oneside',
    'classoptions': ',dvipdfmx',
    'babel': '\usepackage[japanese]{babel}'
}


=================================================
INDEX
=================================================
Edit "index.rst"

ex)
Functional Process Detail Specification
=================================================

.. toctree::
   :maxdepth: 1

   debug/index <- add index
-------------------------------



make html





=================================================
TEXLIVE for PDF
=================================================
- Install texlive
https://www.tug.org/texlive/acquire-netinstall.html

https://medemanabu.net/latex/windows-tex-live-download-install/

- Set Environment Variables
TEXLIVE_ROOT : C:\miki\applications\texlive\2017\bin\win32
PATH : + %TEXLIVE_ROOT%

- Command
make latexpdf
cd build/latex
pLatex ***.tex
dvipdfmx ***.dvi

(or Open tex file by TeXworks editor -> Run)

If pdf is not vreated, try:










