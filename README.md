# DirTool
Programmed in C++ using the Qt libs on Redhat 7.9. Run on Windows at your own risk/extreme
frustration. :D

Based on Directory Opus which was available on the Amiga.

Plan: Make this as configurable as possible. ATM buttons are in a QList though the number is
temporarily fixed. Hoping at some point to find a way to make that more dynamic
so the user can add or remove buttons.

Button function on LMB and MMB atm, RMB may be for a popup menu. Buttons have styles which user
can set in the prefs dialog when its built. Window panes do nothing atm other then show home dir.

Atm it runs, shows the left and right panes and 60 buttons. Initially it will create a default
config file in your home dir /home/<name>/.dtool.cfg in ini format. Running again it will load the
config file to generate the button styles. Left click on any button causes touch to create a file
in your home dir called knight.txt, middle click any button removes that file.

UPDATE:
Changed button layout, delete config before running again.

Name is not fixed in stone.
