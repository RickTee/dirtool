/*
 * File: rbutton.h
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
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

#ifdef  __linux__
#define HOME_PATH   qgetenv("HOME")
#endif
#ifdef _WIN64  
#define HOME_PATH   qgetenv("APPDATA")
#endif
#define TMP_FILE   "/knight.txt"

class RButton : public QPushButton {
    Q_OBJECT
public:
    RButton(QWidget *parent = 0);
    RButton(const RButton& orig);
    virtual ~RButton();
    void configButton(void);
private:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    QVBoxLayout *vbox;
    QHBoxLayout *hbox;
    QAction *mouseAction;
    QProcess process;
    QString style[3];
    int lmb = 0;
    int mmb = 1;
    int rmb = 2;
public:
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

