/*
 * File: rgttreeview.cpp
 * Program: Class
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 10 February 2023, 14:32
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include "rgttreeview.h"
RgtTreeView::RgtTreeView(QWidget *parent) : QTreeView(parent) {

}

//RgtTreeView::RgtTreeView(const RgtTreeView& orig) {
//}
RgtTreeView::~RgtTreeView() {
}

void RgtTreeView::mouseDoubleClickEvent(QMouseEvent *event) {
    resizeColumnToContents(0);
    //std::cout << "yup dun it" << std::endl;
    QTreeView::mouseDoubleClickEvent(event);
}
