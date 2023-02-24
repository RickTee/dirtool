/*
 * File: prefsdialog.h
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 23 February 2023, 14:35
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef RPREFSDIALOG_H
#define RPREFSDIALOG_H

#include <iostream>
#include <QWidget>
#include <QCloseEvent>
#include <QBoxLayout>
#include <QLineEdit>
#include <QDialog>
#include <QLabel>
#include "rprefs.h"

class RPrefsDialog : public QDialog {
    Q_OBJECT
public:
    RPrefsDialog(PrefsData *data, QWidget *parent = 0);
    RPrefsDialog(const RPrefsDialog& orig);
    virtual ~RPrefsDialog();
    
private:
    void closeEvent(QCloseEvent *event);
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QHBoxLayout *hbox_1;
    QLineEdit *rlineedit;
    QLabel *rlabel;
    QPushButton *ok;
    QPushButton *save;
    QPushButton *cancel;
    QString *fileName;
    QLabel *dirPaneLabel;
    QLabel *buttonGroupLabel;
private slots:
    void slot_exit(void);    
};

#endif /* RPREFSDIALOG_H */

