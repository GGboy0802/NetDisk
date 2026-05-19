@echo off
echo Copying FFmpeg and SDL2 DLLs to build output...
echo.

if not exist "build-debug\debug" (
    echo Error: build-debug\debug directory not found. Please build first.
    pause
    exit /b 1
)

copy /Y "mediaplayer\ffmpeg-4.2.2\bin\*.dll" "build-debug\debug\"
copy /Y "mediaplayer\SDL2-2.0.10\lib\x86\SDL2.dll" "build-debug\debug\"

echo.
echo Done! 9 DLLs copied to build-debug\debug\
pause
