/*
 * File: rdtool.cpp
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include "rpane.h"

RPane::RPane(QWidget *parent) : QWidget(parent) {

    vbox = new QVBoxLayout();
    rlabel = new QLabel();
    rlineedit = new QLineEdit();
    rtreeview = new QTreeView();
    rtreeview->setMinimumSize(600, 300);

    vbox->addWidget(rtreeview);
    vbox->addWidget(rlineedit);
    this->setLayout(vbox);

    rmodel = new QFileSystemModel();
    // Default to / (root)
    rmodel->setRootPath(QDir::currentPath());
    rtreeview->setModel(rmodel);
    rlineedit->setText(QDir::currentPath());
    // Change to users home dir
    rtreeview->setRootIndex(rmodel->index(QDir::homePath()));
    rlabel->setText(QDir::homePath());
}
//RPane::RPane(const RPane& orig) {
//}

RPane::~RPane() {
}

void RPane::slot_run(void) {

}
