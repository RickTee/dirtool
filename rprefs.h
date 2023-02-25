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
#include <QPushButton>
#include <QList>
#include "rbuttongroup.h"

#define FILE_NAME   "rdtool.cfg"
#define FILE_PATH   "/.config/QtDirTool/"

#ifdef  __linux__
#define HOME_PATH   qgetenv("HOME")
#endif
#ifdef _WIN64  
#define HOME_PATH   g_getenv("APPDATA")
#endif

class RPrefs {
public:
    RPrefs();
    virtual ~RPrefs();
    
private:
    void savePrefs(void);
    void loadPrefs(void);
    void setDefaultPrefs(void);
    QString *fileName;
    int numOfButtons;
    QString *lmbName;
    QString *lmbCommand;
    QString *lmbArgs;
    QString *lmbTxtColor;
    QString *lmbTxtStyle;
    QString *lmbTxtDecoration;
    QString *lmbBkColor;
    QString *mmbName;
    QString *mmbCommand;
    QString *mmbArgs;
    QString *mmbTxtColor;
    QString *mmbTxtStyle;
    QString *mmbTxtDecoration;
    QString *mmbBkColor;
    QList<QString> rlist;
    //QMenu *rmbMenu;
    RButtonGroup *buttonGrp;
};

#endif /* RPREFS_H */

