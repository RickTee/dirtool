/*
 * File: rbutton.h
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef RBUTTON_H
#define RBUTTON_H

#include <iostream>
#include <QWidget>
#include <QBoxLayout>
#include <QPushButton>
#include <QProcess>
#include <QString>
#include <QMouseEvent>
#include <QAction>

typedef struct _ButtonData ButtonData;

struct _ButtonData {
    QString *lmbName;
    QString *lmbCommand;
    QString *lmbArgs;
    QString *lmbTxtColor;
    QString *lmbTxtStyle;
    QString *lmbTxtDecoration;
    QString *lmbBkColor;
    QString *mmbName;
    QString *mmbCommand;
    QString *mmbArgs;
    QString *mmbTxtColor;
    QString *mmbTxtStyle;
    QString *mmbTxtDecoration;
    QString *mmbBkColor;
    QString *rmbName;
    QString *rmbCommand;
    QString *rmbArgs;
    QString *rmbTxtColor;
    QString *rmbTxtStyle;
    QString *rmbTxtDecoration;
    QString *rmbBkColor;
};

class RButton : public QPushButton {
    Q_OBJECT
public:
    RButton(ButtonData *data, QWidget *parent = 0);
    RButton(const RButton& orig);
    virtual ~RButton();
    
private:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QAction *mouseAction;
    QProcess process;
    QString *lmbName;
    QString *lmbCommand;
    QString *lmbArgs;
    QString *lmbTxtColor;
    QString *lmbTxtStyle;
    QString *lmbTxtDecoration;
    QString *lmbBkColor;
    QString *mmbName;
    QString *mmbCommand;
    QString *mmbArgs;
    QString *mmbTxtColor;
    QString *mmbTxtStyle;
    QString *mmbTxtDecoration;
    QString *mmbBkColor;
    QString *rmbName;
    QString *rmbCommand;
    QString *rmbArgs;
    QString *rmbTxtColor;
    QString *rmbTxtStyle;
    QString *rmbTxtDecoration;
    QString *rmbBkColor;
    
public slots:
    void slotPress(void);
};

#endif /* RBUTTON_H */

