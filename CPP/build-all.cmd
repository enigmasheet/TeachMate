@echo off
rem ============================================================
rem  build-all.cmd - compile every lesson and report warnings
rem  Uses %CXX% if set, otherwise "g++" from PATH.
rem ============================================================
setlocal EnableExtensions EnableDelayedExpansion

set "GXX=%CXX%"
if not defined GXX set "GXX=g++"

if exist "%GXX%" goto have_compiler
where "%GXX%" >nul 2>&1
if errorlevel 1 (
  echo [error] C++ compiler not found: %GXX%
  echo Install MinGW-w64 GCC so that "g++ --version" works, or set CXX.
  echo.
  pause
  exit /b 1
)
:have_compiler

set "ROOT=%~dp0"
set "BUILD=%ROOT%build"
if not exist "%BUILD%" mkdir "%BUILD%"

echo Compiler: %GXX%
"%GXX%" --version | findstr /r "."
echo.

set /a TOTAL=0
set /a FAIL=0
set /a WARN=0

for /r "%ROOT%" %%F in (main.cpp) do if exist "%%F" (
  set /a TOTAL+=1
  set "PDIR=%%~dpF"
  set "PDIR=!PDIR:~0,-1!"
  for %%D in ("!PDIR!") do set "NAME=%%~nxD"

  >"!BUILD!\_log.txt" 2>&1 "%GXX%" -std=c++17 -Wall -Wextra -Wpedantic "%%F" -o "!BUILD!\!NAME!.exe"
  if errorlevel 1 (
    set /a FAIL+=1
    echo FAIL  !NAME!
    type "!BUILD!\_log.txt"
  ) else (
    findstr /i "warning" "!BUILD!\_log.txt" >nul 2>&1
    if !errorlevel! equ 0 (
      set /a WARN+=1
      echo WARN  !NAME!
      findstr /i "warning" "!BUILD!\_log.txt"
    ) else (
      echo pass  !NAME!
    )
  )
)

echo.
echo ============================================
echo Programs: !TOTAL!   Failures: !FAIL!   With warnings: !WARN!
echo ============================================
del "!BUILD!\_log.txt" 2>nul

if !FAIL! gtr 0 ( exit /b !FAIL! ) else ( exit /b 0 )
