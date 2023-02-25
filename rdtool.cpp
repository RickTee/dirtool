/*
 * File: rdtool.cpp
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */
#include "version.h"
#include "rdtool.h"

RdTool::RdTool(QWidget *parent) : QWidget(parent) {
    
    prefs = new RPrefs();
    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout();
    gbox = new QGridLayout();
    gbox->setSpacing(0);
    makeMenu();
    // The left and right panes
    vbox->addWidget(menuBar);
    vbox->addLayout(hbox);
    leftPane = new RPane();
    rightPane = new RPane();
    hbox->addWidget(leftPane);
    hbox->addWidget(rightPane);
    // The button group loaded from prefs
    createButtonLayout();
    vbox->addLayout(gbox);
    this->setLayout(vbox);
    
    connect(quitAction, SIGNAL(triggered()), SLOT(close()));
}
RdTool::~RdTool() {
}

void RdTool::createButtonLayout(void) {
    int i, j, k=0;

    for(i = 0; i < sqrt(NUM_OF_BUTTONS); i++) {
        for(j = 0; j < sqrt(NUM_OF_BUTTONS); j++) {
            gbox->addWidget(prefs->rButtonList.at(k), i, j);
            k++;
        }
    }
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
    connect(prefdialog, SIGNAL(sig_dialog_done()), this, SLOT(slot_close_dialog()));
    prefdialog->show();
}
void RdTool::slot_close_dialog(void) {
    prefdialog->close();
}

void RdTool::slotExit(void) {
    emit exit(0);
}

// Override closeEvent to quit cleanly when user presses the X
void RdTool::closeEvent(QCloseEvent *event) {
    emit exit(0);
    event->accept();
}