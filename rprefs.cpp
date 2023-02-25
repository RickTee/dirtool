/*
 * File: rprefs.cpp
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 11:06
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include <qt5/QtCore/qlist.h>

#include "rprefs.h"

using std::cout;
using std::endl;
RPrefs::RPrefs() {
    fileName = new QString(HOME_PATH);
    fileName->append(FILE_NAME);

    // Create button list
    createButtons();

    loadPrefs();
}
RPrefs::~RPrefs() {
}
void RPrefs::createButtons(void) {
    int i;
    RButton *temp;

    for (i = 0; i < NUM_OF_BUTTONS; i++) {
        temp = new RButton();
        rButtonList.append(temp);
        temp = NULL;
    }
}
void RPrefs::loadPrefs(void) {
    int i;
    int size;
    if (QFile(*this->fileName).exists()) {
        QSettings settings(*this->fileName, QSettings::NativeFormat);
        settings.beginGroup("Buttons");
        size = settings.beginReadArray("ButtonData");
        for (i = 0; i < size; i++) {
            settings.setArrayIndex(i);
            rButtonList.at(i)->lmbName = new QString(settings.value("LmbName").toString());
            // Set the main button (lmb) text
            rButtonList.at(i)->setText(*rButtonList.at(i)->lmbName);
            rButtonList.at(i)->lmbCommand = new QString(settings.value("LmbCommand").toString());
            rButtonList.at(i)->lmbArgs = new QString(settings.value("LmbArgs").toString());
            rButtonList.at(i)->lmbTxtColor = new QString(settings.value("LmbTxtColor").toString());
            rButtonList.at(i)->lmbTxtStyle = new QString(settings.value("LmbTxtStyle").toString());
            rButtonList.at(i)->lmbTxtDecoration = new QString(settings.value("LmbTxtDecoration").toString());
            rButtonList.at(i)->lmbBkColor = new QString(settings.value("LmbBkColor").toString());

            rButtonList.at(i)->mmbName = new QString(settings.value("MmbName").toString());
            rButtonList.at(i)->mmbCommand = new QString(settings.value("MmbCommand").toString());
            rButtonList.at(i)->mmbArgs = new QString(settings.value("MmbArgs").toString());
            rButtonList.at(i)->mmbTxtColor = new QString(settings.value("MmbTxtColor").toString());
            rButtonList.at(i)->mmbTxtStyle = new QString(settings.value("MmbTxtStyle").toString());
            rButtonList.at(i)->mmbTxtDecoration = new QString(settings.value("MmbTxtDecoration").toString());
            rButtonList.at(i)->mmbBkColor = new QString(settings.value("MmbBkColor").toString());

            rButtonList.at(i)->rmbName = new QString(settings.value("RmbName").toString());
            rButtonList.at(i)->configButton();
        }
        settings.endArray();
        settings.endGroup();
    } else {
        // Set defaults and save
        setDefaultPrefs();
        savePrefs();
    }
}
void RPrefs::savePrefs(void) {
    int i;
    QSettings settings(*this->fileName, QSettings::NativeFormat);
    settings.beginGroup("Buttons");
    settings.beginWriteArray("ButtonData");
    for (i = 0; i < rButtonList.count(); i++) {
        settings.setArrayIndex(i);
        settings.setValue("LmbName", *rButtonList.at(i)->lmbName);
        settings.setValue("LmbCommand", *rButtonList.at(i)->lmbCommand);
        settings.setValue("LmbArgs", *rButtonList.at(i)->lmbArgs);
        settings.setValue("LmbTxtColor", *rButtonList.at(i)->lmbTxtColor);
        settings.setValue("LmbTxtStyle", *rButtonList.at(i)->lmbTxtStyle);
        settings.setValue("LmbTxtDecoration", *rButtonList.at(i)->lmbTxtDecoration);
        settings.setValue("LmbBkColor", *rButtonList.at(i)->lmbBkColor);
        settings.setValue("MmbName", *rButtonList.at(i)->mmbName);
        settings.setValue("MmbCommand", *rButtonList.at(i)->mmbCommand);
        settings.setValue("MmbArgs", *rButtonList.at(i)->mmbArgs);
        settings.setValue("MmbTxtColor", *rButtonList.at(i)->mmbTxtColor);
        settings.setValue("MmbTxtStyle", *rButtonList.at(i)->mmbTxtStyle);
        settings.setValue("MmbTxtDecoration", *rButtonList.at(i)->mmbTxtDecoration);
        settings.setValue("MmbBkColor", *rButtonList.at(i)->mmbBkColor);
        settings.setValue("RmbName", *rButtonList.at(i)->rmbName);
    }
    settings.endArray();
    settings.endGroup();
}
void RPrefs::setDefaultPrefs(void) {
    int i;

    for (i = 0; i < NUM_OF_BUTTONS; i++) {
        if(i != NUM_OF_BUTTONS - 1) {
        rButtonList.at(i)->lmbName = new QString(QString("T %1 ").arg(i));
        rButtonList.at(i)->lmbCommand = new QString(QString());
        rButtonList.at(i)->lmbArgs = new QString(QString());
        rButtonList.at(i)->lmbTxtColor = new QString(QString("black"));
        rButtonList.at(i)->lmbTxtStyle = new QString(QString("normal"));
        rButtonList.at(i)->lmbTxtDecoration = new QString(QString("normal"));
        rButtonList.at(i)->lmbBkColor = new QString(QString(" "));
        } else {
            rButtonList.at(i)->lmbName = new QString(QString("Delete"));
            rButtonList.at(i)->lmbCommand = new QString(QString());
            rButtonList.at(i)->lmbArgs = new QString(QString());
            rButtonList.at(i)->lmbTxtColor = new QString(QString("white"));
            rButtonList.at(i)->lmbTxtStyle = new QString(QString("bold"));
            rButtonList.at(i)->lmbTxtDecoration = new QString(QString("normal"));
            rButtonList.at(i)->lmbBkColor = new QString(QString("red"));
            // Set the main button (lmb) text
            rButtonList.at(i)->setText(*rButtonList.at(i)->lmbName);
        }

        rButtonList.at(i)->mmbName = new QString(QString("M %1 ").arg(i));
        rButtonList.at(i)->mmbCommand = new QString(QString());
        rButtonList.at(i)->mmbArgs = new QString(QString());
        rButtonList.at(i)->mmbTxtColor = new QString(QString("black"));
        rButtonList.at(i)->mmbTxtStyle = new QString(QString("normal"));
        rButtonList.at(i)->mmbTxtDecoration = new QString(QString("normal"));
        rButtonList.at(i)->mmbBkColor = new QString(QString(" "));
        
        // Need to set the name for rmb press. Plan is to have a popup menu
        rButtonList.at(i)->rmbName = new QString(QString("B %1 ").arg(i));
        //            data[i].rmbCommand =  new QString(QString());
        //            data[i].rmbArgs =  new QString(QString());
        //            data[i].rmbTxtColor =  new QString(QString("black"));
        //            data[i].rmbTxtStyle =  new QString(QString("normal"));
        //            data[i].rmbTxtDecoration =  new QString(QString("normal"));
        //            data[i].rmbBkColor =  new QString(QString("transparent"));
        // Set the main button (lmb) text
        rButtonList.at(i)->configButton();
    }
}