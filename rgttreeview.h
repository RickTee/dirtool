/*
 * File: rgttreeview.h
 * Program: Class
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 10 February 2023, 14:32
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef RGTTREEVIEW_H
#define RGTTREEVIEW_H

#include <iostream>
#include <QWidget>
#include <QTreeView>
#include <QMouseEvent>

class RgtTreeView : public QTreeView {
    Q_OBJECT
public:
    RgtTreeView(QWidget *parent = 0);
    RgtTreeView(const RgtTreeView& orig);
    virtual ~RgtTreeView();
    
private:
    void mouseDoubleClickEvent(QMouseEvent *event);
    
private slots:

};

#endif /* RGTTREEVIEW_H */

