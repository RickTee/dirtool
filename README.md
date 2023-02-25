# DirTool
Programmed in C++ using the Qt libs.

Copy of Directory Opus which was avalable on the Amiga.

Plan: Make this as configurable as possible. ATM buttons are in a QList though the number is
temporaraly fixed by a #define. Hoping at some point to find a way to make that more dymanic
so the user can add or remove buttons.

Button function on LMB and MMB atm, RMB will be for a popup menu. Buttons have styles which user
can set in the prefs when its built. Window panes do nothing atm other then show home dir.

Looking for some input on this.

Atm it runs, shows the left and right panes and 64 buttons. Initially it will create a default
config file in your home dir /home/<name>/.dtool.cfg in ini format produced by QSettings. Running 
again it will load the config file to generate the buttons. Lef click on any button causes touch
to create a file in your home dir called knight.txt, middle click any button removes that file.

Name is not fixed in stone atm.
