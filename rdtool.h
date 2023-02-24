/*
 * File: rdtool.h
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef RDTOOL_H
#define RDTOOL_H

#include <iostream>
#include <QWidget>
#include <QCloseEvent>
#include <QBoxLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QLabel>
#include <QDialog>
#include "rpane.h"
#include "rbuttongroup.h"
#include "rprefsdialog.h"
#include "rprefs.h"

class RdTool : public QWidget {
    Q_OBJECT
public:
    RdTool(QWidget *parent = 0);
    RdTool(const RdTool& orig);
    virtual ~RdTool();

private:
    void closeEvent(QCloseEvent *event);
    void makeMenu(void);

    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *helpMenu;
    QMenu *prefsMenu;
    QAction *loadAction;
    QAction *quitAction;
    QAction *aboutAction;
    QAction *prefsAction;
    RPane *leftPane;
    RPane *rightPane;
    RButtonGroup *buttonGrp;
    RPrefs *prefs;
    RPrefsDialog *prefdialog;

private slots:
    void slotExit(void);
    void slotAboutDialog(void);
    void slotPrefs(void);
};

#endif /* RDRTOOL_H */

