echo off
set dest=%1

robocopy dlls %dest%\dlls /E
robocopy Release_win64 %dest%\Release_win64 *.exe
copy release_win64.bat %dest%\start_game.bat
robocopy resources %dest%\resources /E
robocopy script %dest%\script /E

echo done