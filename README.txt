Windows blink led setup

----Installation----

In order to make this project work you need to setup following.

ST-link drivers
Download and install:
https://developer.mbed.org/teams/ST/wiki/ST-Link-Driver

GCC-ARM
Download *-win32.zip and unpack in root folder

----Building and compiling

1. Connect the board
2. Open cmd in the root folder
3. Type command "make.exe" 
4. Run the "ocd.bat"
5. Go to control panel->programs->Turn Windows features on or off
6. Select "Telnet client"
7. Proceed and activate it
8. Open cmd anyhwere
9. Type "telnet localhost 4444"
10. Type "reset halt"
11. Type "flash write_image erase <path-to-the-root>/build/blinkled.elf"
Example: flash write_image erase C:/Multirotor/blinkRepo/Multirotor/build/blinkled.elf
12. Type "reset run"
13. Now the green led should blink! 

Notes:
make clean does not function yet. Make sure to delete the build folder manually
if you want to rebuild. Hope this works for you!