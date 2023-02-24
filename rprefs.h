/*
 * File: rprefs.cpp
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 11:06
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef RPREFS_H
#define RPREFS_H

#include <iostream>
#include <fstream>
#include <string>
#include <QString>
#include <QSettings>
#include <QVariant>
#include <QFile>
#include "rbuttongroup.h"

#define FILE_NAME   "rdtool.cfg"
#define FILE_PATH   "/.config/QtDirTool/"

#ifdef  __linux__
#define HOME_PATH   qgetenv("HOME")
#endif
#ifdef _WIN64  
#define HOME_PATH   g_getenv("APPDATA")
#endif

// Forward declarations
typedef struct _PrefsData PrefsData;

struct _PrefsData {
    int numOfButtons;
    QString *lmbCommand;
    QString *lmbArgs;
    QString *lmbtxtcolor;
    QString *lmbtxtstyle;
    QString *lmbtxtdecoration;
    QString *mmbCommand;
    QString *mmbArgs;
    QString *mmbtxtcolor;
    QString *mmbtxtstyle;
    QString *mmbtxtdecoration;
    QMenu *rmbMenu;
    RButtonGroup *buttonGrp;
};

class RPrefs {
public:
    RPrefs();
    virtual ~RPrefs();
    PrefsData data;
private:
    void savePrefs(void);
    void loadPrefs(void);
    QString *fileName;
};

#endif /* RPREFS_H */

