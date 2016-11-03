echo Start program testing

set PROGRAM="%~1"

%PROGRAM% 17 2 R 100> %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-count-parameters-not-equal-4.txt
if ERRORLEVEL 1 goto err

%PROGRAM% N 2 R > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-byte-paramenter-not-number.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 17 99 R > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-number-of-bits-outside-between-0-and-8.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 17 2 P > %TEMP%\output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-rotation-direction-not-l-or-r.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 17 2 R > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-parameters-are-17-2-r.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 17 0 R > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-parameters-are-17-0-r.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 17 8 R > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-parameters-are-17-8-r.txt
if ERRORLEVEL 1 goto err

%PROGRAM% 128 1 L > %TEMP%\output.txt
if ERRORLEVEL 1 goto err
fc.exe %TEMP%\output.txt expected-output-when-parameters-are-128-1-l.txt
if ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1