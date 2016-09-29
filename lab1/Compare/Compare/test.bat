set PROGRAM="%~1"

%PROGRAM% empty1.txt empty2.txt
if ERRORLEVEL 1 goto err
fc.exe empty1.txt empty2.txt
if ERRORLEVEL 1 goto err

%PROGRAM% file1.txt file2.txt
if ERRORLEVEL 1 goto err
fc.exe file1.txt file2.txt
if ERRORLEVEL 1 goto err

%PROGRAM% non-existing-file-name.txt file2.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe "%TEMP%\output.txt" expected-output-when-input-file-is-missing.txt
if ERRORLEVEL 1 goto err

%PROGRAM% file1.txt file3.txt > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt different-files-in-line-3.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1