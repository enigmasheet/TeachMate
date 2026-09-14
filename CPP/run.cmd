@echo off
rem ============================================================
rem  run.cmd - build and run one lesson
rem  Usage:  run.cmd week1\lesson01_hello
rem
rem  Uses the C++ compiler named by %CXX% (full path or name),
rem  otherwise "g++" from PATH.
rem ============================================================
setlocal EnableExtensions EnableDelayedExpansion

set "GXX=%CXX%"
if not defined GXX set "GXX=g++"

rem ---- make sure a compiler is actually available ----
if exist "%GXX%" goto have_compiler
where "%GXX%" >nul 2>&1
if errorlevel 1 (
  echo [error] C++ compiler not found: %GXX%
  echo.
  echo Install MinGW-w64 GCC so that "g++ --version" works in a terminal,
  echo or set CXX to the full path of your g++.exe, then try again.
  echo.
  pause
  exit /b 1
)
:have_compiler

rem Put the compiler's folder first on PATH so the built .exe finds its DLLs.
for %%I in ("%GXX%") do set "GXXDIR=%%~dpI"
if defined GXXDIR if exist "%GXXDIR%" set "PATH=%GXXDIR%;%PATH%"

set "ROOT=%~dp0"

if "%~1"=="" (
  echo Usage: run.cmd ^<lesson-folder^>
  echo   e.g.  run.cmd week1\lesson01_hello
  echo.
  pause
  exit /b 1
)

set "SRC=%~1"
if exist "%~1\" set "SRC=%~1\main.cpp"

if not exist "%SRC%" (
  echo [error] Cannot find "%SRC%".
  echo         Pass a lesson folder, for example: run.cmd week1\lesson01_hello
  echo.
  pause
  exit /b 1
)

rem ---- name the executable after the lesson folder ----
for %%F in ("%SRC%") do set "SRCDIR=%%~dpF"
set "SRCDIR=!SRCDIR:~0,-1!"
for %%G in ("!SRCDIR!") do set "NAME=%%~nxG"

set "BUILD=%ROOT%build"
if not exist "%BUILD%" mkdir "%BUILD%"
set "EXE=%BUILD%\%NAME%.exe"

echo Compiler: %GXX%
echo Building %NAME% ...
"%GXX%" -std=c++17 -Wall -Wextra -Wpedantic -g "%SRC%" -o "%EXE%"
if errorlevel 1 (
  echo.
  echo [build failed]
  echo.
  pause
  exit /b 1
)

echo.
echo Running %NAME% ...
echo ------------------------------------------------------------
"%EXE%" %2 %3 %4 %5 %6 %7 %8 %9
set "RC=%errorlevel%"
echo ------------------------------------------------------------
exit /b %RC%
