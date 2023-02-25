/*
 * File: rbutton.cpp
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include "rbutton.h"

RButton::RButton(QWidget *parent) : QPushButton(parent) {
    
    connect(this, SIGNAL(clicked()), SLOT(slotPress()));
}
//RButton::RButton(const RButton& orig) {
//}
RButton::~RButton() {
}

void RButton::configButton(void) {
    
    style[lmb] = "QPushButton { background-color: ";
    style[lmb].append(lmbBkColor);
    style[lmb].append("; color: ");
    style[lmb].append(lmbTxtColor);
    style[lmb].append("; font: ");
    style[lmb].append(lmbTxtStyle);
    style[lmb].append("; text-decoration: ");
    style[lmb].append(lmbTxtDecoration);
    style[lmb].append("}");
    
    style[mmb] = "QPushButton { background-color: ";
    style[mmb].append(mmbBkColor);
    style[mmb].append("; color: ");
    style[mmb].append(mmbTxtColor);
    style[mmb].append("; font: ");
    style[mmb].append(mmbTxtStyle);
    style[mmb].append("; text-decoration: ");
    style[mmb].append(mmbTxtDecoration);
    style[mmb].append("}");
    
    setStyleSheet(style[lmb]);
    setText(*lmbName);
    
    //std::cout << "style" << style[0].toStdString() << std::endl;
}

void RButton::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        this->setDown(true);
        process.start("touch", QStringList() << (HOME_PATH + TMP_FILE));
    }
    if (event->button() == Qt::MiddleButton) {
        this->setDown(true);
        setText(*mmbName);
        setStyleSheet(style[mmb]);
        process.start("rm", QStringList() << (HOME_PATH + TMP_FILE));
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
    setStyleSheet(style[lmb]);
    setText(*lmbName);
    // Pass event to base class
    //QPushButton::mouseReleaseEvent(event);
}

void RButton::slotPress(void) {

}
