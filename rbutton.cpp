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

    setStyleSheet(style[LMB]);
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
        setStyleSheet(style[MMB]);
        process.start("rm", QStringList() << (HOME_PATH + TMP_FILE));
    }
    if (event->button() == Qt::RightButton) {
        this->setDown(true);
        setText(*rmbName);
        setStyleSheet(style[RMB]);
    }
    // Pass event to base class
    //QPushButton::mousePressEvent(event);
    event->accept();
}

void RButton::mouseReleaseEvent(QMouseEvent *event) {
    this->setDown(false);
    setStyleSheet(style[LMB]);
    setText(*lmbName);
    // Pass event to base class
    //QPushButton::mouseReleaseEvent(event);
    event->accept();
}

void RButton::slotPress(void) {

}
