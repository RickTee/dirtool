/* 
 * File:   rpane.cpp
 * Author: rick
 * 
 * Created on 19 February 2023, 12:45
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
