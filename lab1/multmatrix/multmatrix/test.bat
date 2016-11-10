echo Start program testing

set PROGRAM="%~1"

%PROGRAM% matrix-file-1.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-input-file-is-missing.txt
if ERRORLEVEL 1 goto err 

%PROGRAM% matrix-file-1.txt matrix.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-failed-to-open-file.txt
if ERRORLEVEL 1 goto err

%PROGRAM% matrix-file-1.txt matrix-file-2.txt > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt multmatrix-file.txt
if ERRORLEVEL 1 goto err

%PROGRAM% matrix-file-1.txt error-file-count-rows.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-error-file-count-rows.txt
if ERRORLEVEL 1 goto err

%PROGRAM% matrix-file-1.txt error-file-count-cols.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-error-file-count-cols.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1