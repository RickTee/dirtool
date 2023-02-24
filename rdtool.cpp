/*
 * File: rdtool.cpp
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */
#include "version.h"
#include "rdtool.h"

RdTool::RdTool(QWidget *parent) : QWidget(parent) {
    
    prefs = new RPrefs();
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout();
    makeMenu();
    // The left and right panes
    vbox->addWidget(menuBar);
    vbox->addLayout(hbox);
    leftPane = new RPane();
    rightPane = new RPane();
    hbox->addWidget(leftPane);
    hbox->addWidget(rightPane);
    // The button group loaded from prefs
    buttonGrp = prefs->data.buttonGrp;
    vbox->addWidget(buttonGrp);
    this->setLayout(vbox);
    
    
    connect(quitAction, SIGNAL(triggered()), SLOT(close()));
}
RdTool::~RdTool() {
}

// Create a menu bar and add a File menu and Help menu'
void RdTool::makeMenu(void) {
    menuBar = new QMenuBar();
    // File menu
    fileMenu = new QMenu("&File");
    loadAction = new QAction(QIcon::fromTheme("fileopen",
    QIcon("/usr/share/icons/gnome/16x16/actions/fileopen.png")), "&Import");
    fileMenu->addAction(loadAction);
    fileMenu->addSeparator();
    quitAction = new QAction(QIcon::fromTheme("exit",
    QIcon("/usr/share/icons/gnome/16x16/actions/exit.png")), "&Quit");
    fileMenu->addAction(quitAction);
    menuBar->addMenu(fileMenu);
    // Prefs menu
    prefsMenu = new QMenu("&Edit");
    prefsAction = new QAction(QIcon::fromTheme("edit",
    QIcon("/usr/share/icons/gnome/16x16/actions/edit.png")), "&Preferences");
    prefsMenu->addAction(prefsAction);
    menuBar->addMenu(prefsMenu);
    // Help menu
    helpMenu = new QMenu("&Help");
    aboutAction = new QAction(QIcon::fromTheme("help-about",
    QIcon("/usr/share/icons/gnome/16x16/actions/help-about.png")), "&About");
    helpMenu->addAction(aboutAction);
    menuBar->addMenu(helpMenu);
    
    connect(quitAction, SIGNAL(triggered()), SLOT(close()));
    connect(prefsAction, SIGNAL(triggered()), SLOT(slotPrefs()));
    connect(aboutAction, SIGNAL(triggered()), SLOT(slotAboutDialog()));
}

void RdTool::slotAboutDialog(void) {
    QDialog * helpAbout = new QDialog(this);
    helpAbout->setModal(true);
    helpAbout->setWindowTitle("About");
    QVBoxLayout *dvbox = new QVBoxLayout;
    
    QString aboutString(APPLICATION"\n" DESCRIPTION"\n" "Author: " AUTHOR"\n" EMAIL);
    QLabel *progName = new QLabel(aboutString);
    progName->setAlignment(Qt::AlignCenter);
    dvbox->addWidget(progName);
    QPushButton *btn = new QPushButton("Close");
    dvbox->addWidget(btn);
    helpAbout->setLayout(dvbox);
    
    connect(btn, SIGNAL(clicked()), helpAbout, SLOT(close()));
    helpAbout->show();
}

void RdTool::slotPrefs(void) {
    prefdialog = new RPrefsDialog(prefs);
    prefdialog->show();
}

void RdTool::slotExit(void) {
    emit exit(0);
}

// Override closeEvent to quit cleanly when user presses the X
void RdTool::closeEvent(QCloseEvent *event) {
    emit exit(0);
    event->accept();
}