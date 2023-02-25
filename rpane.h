/*
 * File: rpane.h
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on 19 February 2023, 12:45
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
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

