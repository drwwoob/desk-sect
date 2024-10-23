@echo off
setlocal

cd "C:\Users\14631\Desktop\DT\desk_sect"

if exist "build" (
    rmdir /s /q "build"
)
mkdir "build"
cd "build"

cmake .. -G "MinGW Makefiles"
cmake --build .

endlocal
