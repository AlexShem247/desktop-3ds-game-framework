@echo off

REM Check if the "build" directory exists
IF NOT EXIST "build" (
    REM Create the "build" directory
    mkdir "build"
) 

REM Run bannertool to create banner
buildtools\bannertool.exe makebanner ^
  -i assets\cia\banner.png ^
  -a assets\cia\audio.wav ^
  -o build\cia_banner.bnr

REM Run bannertool to create icon
buildtools\bannertool.exe makesmdh ^
  -s "GAME-TITLE" ^
  -l "GAME-TITLE" ^
  -p "Publisher" ^
  -i assets\cia\icon.png ^
  -o build\cia_icon.icn ^
  -r regionfree -f visible, nosavebackups, allow3d

REM Run makerom to create CIA file
buildtools\makerom.exe -f cia ^
  -o game.cia ^
  -rsf assets\cia\template.rsf ^
  -elf desktop-3ds-game-framework.elf ^
  -icon build\cia_icon.icn ^
  -banner build\cia_banner.bnr

echo Done creating game.cia
pause
