@echo off
g++ -o hospital main.cpp
if %errorlevel% equ 0 (
    echo Compilation successful!
    hospital.exe
) else (
    echo Compilation failed!
)
pause 