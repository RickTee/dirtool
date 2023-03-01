/*
 * File: rdtool.h
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef RDTOOL_H
#define RDTOOL_H

#include <iostream>
#include <cmath>
#include <QWidget>
#include <QCloseEvent>
#include <QBoxLayout>
#include <QGridLayout>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QLabel>
#include <QDialog>
#include "rpane.h"
#include "rprefsdialog.h"
#include "rprefs.h"

class RDirMan : public QWidget {
    Q_OBJECT
public:
    RDirMan(QWidget *parent = 0);
    RDirMan(const RDirMan& orig);
    virtual ~RDirMan();

private:
    void closeEvent(QCloseEvent *event);
    void makeMenu(void);
    void createButtonLayout(void);

    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QGridLayout *gbox;
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
    RPrefs *prefs;
    RPrefsDialog *prefdialog;

private slots:
    void slotExit(void);
    void slotAboutDialog(void);
    void slotPrefs(void);
    void slot_close_dialog(void);
};

#endif /* RDRTOOL_H */

