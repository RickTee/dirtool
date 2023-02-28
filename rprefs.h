/*
 * File: rprefs.cpp
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 11:06
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef RPREFS_H
#define RPREFS_H

#include <iostream>
#include <fstream>
#include <QString>
#include <QSettings>
#include <QVariant>
#include <QFile>
#include <QPushButton>
#include <QList>
#include "rbutton.h"

#define FILE_NAME   "/.dtool.cfg"

#ifdef  __linux__
#define HOME_PATH   qgetenv("HOME")
#endif
#ifdef _WIN64  
#define HOME_PATH   g_getenv("APPDATA")
#endif

#define NUM_OF_BUTTONS 60
#define BUILT_IN_COMMS 20

class RPrefs {
public:
    RPrefs();
    virtual ~RPrefs();

private:
    void savePrefs(void);
    void loadPrefs(void);
    void setDefaultPrefs(void);
    void createButtons(void);
    void createCommands(void);
    QString *fileName;
public:
    int numOfButtons;
    QList<RButton*> rButtonList;
    QList<QString*> rCommands;
    QList<QString*> rArgs;
    QString defaultComms[BUILT_IN_COMMS];
    QString defaultArgs[BUILT_IN_COMMS];
    //QMenu *rmbMenu;
};

#endif /* RPREFS_H */

