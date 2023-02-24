/*
 * File: rbuttongroup.h
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef RBUTTONGROUP_H
#define RBUTTONGROUP_H

#include <iostream>
#include <QWidget>
#include <QBoxLayout>
#include <QGridLayout>
#include "rbutton.h"

class RButtonGroup : public QWidget {
    Q_OBJECT
public:
    RButtonGroup(QWidget *parent = 0);
    virtual ~RButtonGroup();
    
private:
    void createButtons(void);
    QVBoxLayout *vbox;
    QGridLayout *gbox;
    RButton     *buttons[36];
    
private slots:
  
};

#endif /* RBUTTONGROUP_H */

