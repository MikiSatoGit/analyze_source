# Spec Document Generator

last update:07/25/2018

---
Generate Sphinx document codes from C source file.
- Create description page of  each function defined in the C source file.
- Each page includes:
    - Interface (Arguments, Return Value)
    - Main Process Flowchart
    - Processes in process blocks of Flowchart
    - Processes in condition blocks of Flowchart
    - Link to Subprocess page

---
### Install python packages (pillow, blockdiag, sphinx, pandas)
Python 2.7
- pip install pillow
- pip install blockdiag
- pip install sphinx
- pip install sphinxcontrib-actdiag sphinxcontrib-blockdiag sphinxcontrib-nwdiag sphinxcontrib-seqdiag
- pip install sphinx_rtd_theme
- pip install pandas    
or (https://pypi.python.org/pypi/pandas/0.15.2/#downloads pandas-0.15.2.win32-py2.7.exe)


### Run analyze_source_c.py
Enter the following command from the command line to create Sphinx sorce files (rst file).    
```
> python analyze_source_c.py [c source file path]
```

#### result
Three folders are created at the same path.
- analyze_(source file name).txt -> can be erased
- csv : Process and Condition table -> can be erased
- fig : blockdiag source code -> can be erased
- doc\source : rst files (Sphinx source file )

#### Note:
- definition for #ifdef   
Add Valid Preprocessor word to "valid_preprocessor_code" in func_source_analyze.py

```py
valid_preprocessor_code.append('PREPROCESSOR WORD')
```


---
### Create SPHINX file
#### (1) change working directory to the doc folder above.
- enter the following comonad and change current dir.    
```
> cd [c source folder path]\doc" )
```
#### (2) create sphinx project
- enter the following command to create sphinx project.   
```
> sphinx-quickstart
```

- enter following options (Other option can be default (just push Enter))    
```
> Separate source and build directories (y/n) [n]: y
> Project name: (PROJECT NAME)
> Author name(s): (AUTHOR NAME)
> Project version []: (VERSION)
```

#### (3) edit config file (doc\source\conf.py)
##### (i) add extentions for blockdiag

```
	extensions = [
	    'sphinxcontrib.blockdiag',
	    'sphinxcontrib.seqdiag',
	    'sphinxcontrib.actdiag',
	    'sphinxcontrib.nwdiag',
	    'sphinxcontrib.rackdiag',
	    'sphinxcontrib.packetdiag',
	]
```

##### (ii) add blockdiag setting at the end of conf.py

```
	blockdiag_html_image_format = 'SVG'
	seqdiag_html_image_format = 'SVG'
	actdiag_html_image_format = 'SVG'
	nwdiag_html_image_format = 'SVG'
	rackiag_html_image_format = 'SVG'
	packetdiag_html_image_format = 'SVG'
```
※ change SVG -> PNG if you want to use PNG for Fig.

##### (iii) set theme. (preferred theme is "sphinx_rtd_theme")

```
	html_theme = 'sphinx_rtd_theme'
	(default : html_theme = 'alabaster')
```
※please see the following page about available theme    
	http://www.sphinx-doc.org/en/stable/theming.html

※default available theme

```
	#html_theme = 'agogo'
	#html_theme = 'scrolls'
	#html_theme = 'alabaster'
	#html_theme = 'classic'
	#html_theme = 'sphinxdoc'
	#html_theme = 'traditional'
	#html_theme = 'nature'
	#html_theme = 'haiku'
	#html_theme = 'pyramid'
	#html_theme = 'bizstyle'
```

##### (iv)  set html style    
- set html_style as below.

```
	html_style = 'css/my_theme.css'
```

- create doc\source\\_static\css\my_theme.css

_my_theme.css_
```
@import url("theme.css");
 
.wy-nav-content {
    max-width: none;
}

h1,h2,h3,h4,h5,h6 {
    border-bottom: 1px solid #ccc;
}

.wy-table-responsive table td, .wy-table-responsive table th {
    white-space: normal;
}

colgroup {
    display: none;
}
```

##### (v) add latex setting (TBD)

```
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
```

#### (4) edit index file (doc\source\index.rst)
##### (i) change title of top page
(default)
```
	Welcome to Sample's documentation!
	=================================================
```
↓
(example) change title to "Sample Specification"
```
	Samplel Specification
	=================================================
```

##### (ii) change tree level

_index.rst_
```
BTT logic Specification
=====================================
.. toctree::
   :maxdepth: 1 //← chnage level as you want (preferred level is 2)

	(c source file name #1)/index
	(c source file name #2)/index
	.
	.
	.
```

#### Note:    
add index below ":maxdepth".
(example) for sample1.c and sample2.c
```
.. toctree::
   :maxdepth: 1 //← chnage level as you want (preferred level is 2)

   sample/index
   sample2/index
```
※need to add 3 spaces before 
※ Level defines table of contents shown in top page
1: filename
2: function name in each file
3: sub section of each function (Interface, Main Process Flow, Prcess Table, Condition Table, Subprocesses )
4: Subprocesses  of each function


#### Note:    
※The following lines in the generated file can be erased.
```
	:caption: Contents:

	Indices and tables
	==================
	
	* :ref:`genindex`
	* :ref:`modindex`
	* :ref:`search`
```

#### (5) create html 
- enter "make html"

#### result
- HTML files are created in "doc\build\html"
- Top page is "doc\build\html\index.html"






---
### TEXLIVE for PDF
- Install texlive    
	- Installer : https://www.tug.org/texlive/acquire-netinstall.html    
	- Installation manual(Japanese): https://www.tug.org/texlive/acquire-netinstall.html

- Set Environment Variables    
	- TEXLIVE_ROOT : C:\texlive\2018\bin\win32 (your texlive install folder)    
	- PATH : add %TEXLIVE_ROOT%    

- Command

```
make latexpdf
cd build/latex
pLatex ***.tex
dvipdfmx ***.dvi
(or Open tex file by TeXworks editor -> Run)
```









