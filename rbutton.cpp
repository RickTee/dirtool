/*
 * File: rbutton.cpp
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include "rbutton.h"
RButton::RButton(ButtonData *data, QWidget *parent) : QPushButton(parent) {
    lmbName = data->lmbName;
    mmbName = data->mmbName;
    rmbName = data->rmbName;
    lmbCommand = data->lmbCommand;
    lmbArgs = data->lmbArgs;
    mmbCommand = data->mmbCommand;
    mmbArgs = data->mmbArgs;
    rmbCommand = data->rmbCommand;
    rmbArgs = data->rmbArgs;
    bdata = data;

    setText(*lmbName);

    connect(this, SIGNAL(clicked()), SLOT(slotPress()));
}

RButton::RButton(QWidget *parent) : QPushButton(parent) {
    
    //setText(*lmbName);
    connect(this, SIGNAL(clicked()), SLOT(slotPress()));
}
//RButton::RButton(const RButton& orig) {
//}
RButton::~RButton() {
}

void RButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        this->setDown(true);
        process.start("touch", QStringList() << "/home/rick/tmp/knight.txt");
    }
    if (event->button() == Qt::MiddleButton) {
        this->setDown(true);
        setText(*mmbName);
        process.start("rm", QStringList() << "/home/rick/tmp/knight.txt");
    }
    if (event->button() == Qt::RightButton) {
        this->setDown(true);
        setText(*rmbName);
    }
    // Pass event to base class
    //QPushButton::mousePressEvent(event);
}
void RButton::mouseReleaseEvent(QMouseEvent *event) {
    this->setDown(false);
    setText(*lmbName);
    // Pass event to base class
    //QPushButton::mouseReleaseEvent(event);
}

void RButton::slotPress(void) {

}
