/*
 * File: rprefs.cpp
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 11:06
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include "rprefs.h"

using std::cout;
using std::endl;

RPrefs::RPrefs() {
    fileName = new QString(HOME_PATH);
    fileName->append(FILE_NAME);

    // Create button list
    createButtons();
    createCommands();

    loadPrefs();
}

RPrefs::~RPrefs() {
}

// Create the command list
void RPrefs::createCommands(void) {
    int i;
    for (i = 0; i < BUILT_IN_COMMS; i++) {
        
    }
    
}

// Create the button list
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
            rButtonList.at(i)->rmbCommand = new QString(settings.value("RmbCommand").toString());
            rButtonList.at(i)->rmbArgs = new QString(settings.value("RmbArgs").toString());
            rButtonList.at(i)->rmbTxtColor = new QString(settings.value("RmbTxtColor").toString());
            rButtonList.at(i)->rmbTxtStyle = new QString(settings.value("RmbTxtStyle").toString());
            rButtonList.at(i)->rmbTxtDecoration = new QString(settings.value("RmbTxtDecoration").toString());
            rButtonList.at(i)->rmbBkColor = new QString(settings.value("RmbBkColor").toString());
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
        settings.setValue("RmbCommand", *rButtonList.at(i)->rmbCommand);
        settings.setValue("RmbArgs", *rButtonList.at(i)->rmbArgs);
        settings.setValue("RmbTxtColor", *rButtonList.at(i)->rmbTxtColor);
        settings.setValue("RmbTxtStyle", *rButtonList.at(i)->rmbTxtStyle);
        settings.setValue("RmbTxtDecoration", *rButtonList.at(i)->rmbTxtDecoration);
        settings.setValue("RmbBkColor", *rButtonList.at(i)->rmbBkColor);
    }
    settings.endArray();
    settings.endGroup();
}

void RPrefs::setDefaultPrefs(void) {
    int i;

    for (i = 0; i < NUM_OF_BUTTONS; i++) {
        if (i == (NUM_OF_BUTTONS - 6)) {
            rButtonList.at(i)->lmbName = new QString("Delete");
            rButtonList.at(i)->lmbCommand = new QString();
            rButtonList.at(i)->lmbArgs = new QString();
            rButtonList.at(i)->lmbTxtColor = new QString("white");
            rButtonList.at(i)->lmbTxtStyle = new QString("bold");
            rButtonList.at(i)->lmbTxtDecoration = new QString("normal");
            rButtonList.at(i)->lmbBkColor = new QString("red");
        } else if ((i >= 30) && (i <= 35)) {
            rButtonList.at(i)->lmbName = new QString(QString("T %1 ").arg(i));
            rButtonList.at(i)->lmbCommand = new QString();
            rButtonList.at(i)->lmbArgs = new QString();
            rButtonList.at(i)->lmbTxtColor = new QString("black");
            rButtonList.at(i)->lmbTxtStyle = new QString("normal");
            rButtonList.at(i)->lmbTxtDecoration = new QString("normal");
            rButtonList.at(i)->lmbBkColor = new QString("orange");
        } else {
            rButtonList.at(i)->lmbName = new QString(QString("T %1 ").arg(i));
            rButtonList.at(i)->lmbCommand = new QString();
            rButtonList.at(i)->lmbArgs = new QString();
            rButtonList.at(i)->lmbTxtColor = new QString("black");
            rButtonList.at(i)->lmbTxtStyle = new QString("normal");
            rButtonList.at(i)->lmbTxtDecoration = new QString("normal");
            rButtonList.at(i)->lmbBkColor = new QString();
        }

        rButtonList.at(i)->mmbName = new QString(QString("M %1 ").arg(i));
        rButtonList.at(i)->mmbCommand = new QString();
        rButtonList.at(i)->mmbArgs = new QString();
        rButtonList.at(i)->mmbTxtColor = new QString("black");
        rButtonList.at(i)->mmbTxtStyle = new QString("normal");
        rButtonList.at(i)->mmbTxtDecoration = new QString("normal");
        rButtonList.at(i)->mmbBkColor = new QString();

        // Need to set the name for rmb press. Plan is to have a popup menu
        rButtonList.at(i)->rmbName = new QString(QString("B %1 ").arg(i));
        rButtonList.at(i)->rmbCommand = new QString();
        rButtonList.at(i)->rmbArgs = new QString();
        rButtonList.at(i)->rmbTxtColor = new QString("black");
        rButtonList.at(i)->rmbTxtStyle = new QString("normal");
        rButtonList.at(i)->rmbTxtDecoration = new QString("normal");
        rButtonList.at(i)->rmbBkColor = new QString();
        // Set the main button(lmb) text
        rButtonList.at(i)->configButton();
    }
}