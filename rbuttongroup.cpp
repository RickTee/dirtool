/*
 * File: rbuttongroup.cpp
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include "rbuttongroup.h"

RButtonGroup::RButtonGroup(QWidget *parent) : QWidget(parent) {

    gbox = new QGridLayout();
    createButtons();
    this->setLayout(gbox);
}

RButtonGroup::~RButtonGroup() {
}

void RButtonGroup::createButtons(void) {
    int i, j, k=0;
    ButtonData data[36];

    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            data[k].topName =  new QString(QString("T %1 ").arg(k));
            data[k].middleName =  new QString(QString("M %1 ").arg(k));
            data[k].bottomName =  new QString(QString("B %1 ").arg(k));
            buttons[k] = new RButton(&data[k]);
            gbox->addWidget(buttons[k], i, j);
            k++;
        }
    }
    std::cout << "k " << k << std::endl;
}