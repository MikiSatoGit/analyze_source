
pyinstaller -F analyze_source_c.py
::rd /s /q .\build
::del /s /q *.pyc
::del /s /q *.spec
::ren dist exe
