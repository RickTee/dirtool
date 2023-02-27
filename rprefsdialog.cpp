/*
 * File: prefsdialog.cpp
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 23 February 2023, 14:35
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include "rprefsdialog.h"

RPrefsDialog::RPrefsDialog(RPrefs *prefs, QWidget *parent) : QDialog(parent) {

    vbox = new QVBoxLayout();
    hbox = new QHBoxLayout;
    hbox_1 = new QHBoxLayout;
    dirPaneLabel = new QLabel("Window config:");
    buttonGroupLabel = new QLabel("Button config:");
    //data->buttonGrp = new RButtonGroup();
    ok = new QPushButton("Ok");
    save = new QPushButton("Save");
    cancel = new QPushButton("Cancel");

    hbox->addWidget(dirPaneLabel);
    vbox->addLayout(hbox);
    // the button group
    vbox->addWidget(buttonGroupLabel);
    //vbox->addWidget(data->buttonGrp);
    vbox->addLayout(hbox_1);
    hbox_1->addWidget(ok);
    hbox_1->addWidget(save);
    hbox_1->addWidget(cancel);
    this->setLayout(vbox);

    connect(cancel, SIGNAL(clicked()), SLOT(slot_exit()));
}

//PrefsDialog::PrefsDialog(const PrefsDialog& orig) {
//}

RPrefsDialog::~RPrefsDialog() {
}

void RPrefsDialog::slot_exit(void) {
    emit sig_dialog_done();
}

// Override closeEvent to quit cleanly when user presses the X
//void RPrefsDialog::closeEvent(QCloseEvent *event) {
//    emit exit(0);
//    event->accept();
//}