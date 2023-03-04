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
    rmodel = new QFileSystemModel();
    rtreeview = new RgtTreeView();
    rtreeview->setMinimumSize(600, 300);
    // Does nothing
    //rtreeview->resizeColumnToContents(0);
    //rtreeview->setColumnWidth(0, 200);
    //rtreeview->resizeColumnToContents(0);
    //rtreeview->setIndentation(20);
    //rtreeview->setColumnWidth(0, rtreeview->width() / 3);

    vbox->addWidget(rtreeview);
    vbox->addWidget(rlineedit);
    this->setLayout(vbox);

    // Default to / (root)
    rmodel->setRootPath(QDir::currentPath());
    rtreeview->setModel(rmodel);
    rlineedit->setText(QDir::currentPath());
    // Change to users home dir
    rtreeview->setRootIndex(rmodel->index(QDir::homePath()));
    rlabel->setText(QDir::homePath());
    
    connect(rlineedit, SIGNAL( editingFinished()), SLOT(slotChangeDir()));
}
//RPane::RPane(const RPane& orig) {
//}

RPane::~RPane() {
}

void RPane::slotChangeDir(void) {
    rtreeview->setRootIndex(rmodel->setRootPath(rlineedit->text()));
}
