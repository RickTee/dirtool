/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rtreeview.h
 * Author: rick
 *
 * Created on 19 February 2023, 12:45
 */

#ifndef RPANE_H
#define RPANE_H

#include <iostream>
#include <QWidget>
#include <QCloseEvent>
#include <QTreeView>
#include <QStandardItemModel>
#include <QFileSystemModel>
#include <QHeaderView>
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QLineEdit>
#include <QList>

class RPane : public QWidget {
    Q_OBJECT
public:
    RPane(QWidget *parent = 0);
    RPane(const RPane& orig);
    virtual ~RPane();
private:
    QVBoxLayout *vbox;
    QTreeView   *rtreeview;
    QFileSystemModel *rmodel;
    QLineEdit *rlineedit;
    QLabel *rlabel;
    
private slots:
    void slot_run(void);
};

#endif /* RPANE_H */

