@echo off
set "outputFile=all_project_code.txt"

echo Сборка кода началась...

powershell -Command "Get-ChildItem -Recurse -Include *.cpp, *.h, *.hpp | ForEach-Object { '--- START FILE: ' + $_.FullName + ' ---'; Get-Content $_; '--- END FILE ---' + [Environment]::NewLine } | Set-Content '%outputFile%' -Encoding utf8"

echo Готово! Весь код собран в файл %outputFile%
pause