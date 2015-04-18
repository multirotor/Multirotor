Windows blink led setup

1. Install STLINK driver
2. Connect the board
3. Open cmd in the root folder
4. Type command "make.exe" 
5. Run the "ocd.bat"
6. Go to control panel->programs->Turn Windows features on or off
7. Select "Telnet client"
8. Proceed and activate it
9. Open cmd anyhwere
10. Type "telnet localhost 4444"
11. Type "reset halt"
12. Type "flash write_image erase <path-to-the-root>/build/blinkled.elf"
Example: flash write_image erase C:/Multirotor/blinkRepo/Multirotor/build/blinkled.elf
13. Type "reset run"
14. Now the green led should blink! 

Notes:
make clean does not function yet. Make sure to delete the build folder manually
if you want to rebuild. Hope this works for you!