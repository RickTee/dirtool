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
    //createCommands();
    // Load prefs if they exist else create new file with defaults
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
            rButtonList.at(i)->lmbCommand = new QString(settings.value("LmbCommand").toString());
            rButtonList.at(i)->lmbArgs = new QString(settings.value("LmbArgs").toString());
            rButtonList.at(i)->style[LMB] = (settings.value("LmbStyle").toString());

            rButtonList.at(i)->mmbName = new QString(settings.value("MmbName").toString());
            rButtonList.at(i)->mmbCommand = new QString(settings.value("MmbCommand").toString());
            rButtonList.at(i)->mmbArgs = new QString(settings.value("MmbArgs").toString());
            rButtonList.at(i)->style[MMB] = (settings.value("MmbStyle").toString());

            rButtonList.at(i)->rmbName = new QString(settings.value("RmbName").toString());
            rButtonList.at(i)->rmbCommand = new QString(settings.value("RmbCommand").toString());
            rButtonList.at(i)->rmbArgs = new QString(settings.value("RmbArgs").toString());
            rButtonList.at(i)->style[RMB] = (settings.value("RmbStyle").toString());
            
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
        settings.setValue("LmbStyle", rButtonList.at(i)->style[LMB]);

        settings.setValue("MmbName", *rButtonList.at(i)->mmbName);
        settings.setValue("MmbCommand", *rButtonList.at(i)->mmbCommand);
        settings.setValue("MmbArgs", *rButtonList.at(i)->mmbArgs);
        settings.setValue("MmbStyle", rButtonList.at(i)->style[MMB]);
        
        settings.setValue("RmbName", *rButtonList.at(i)->rmbName);
        settings.setValue("RmbCommand", *rButtonList.at(i)->rmbCommand);
        settings.setValue("RmbArgs", *rButtonList.at(i)->rmbArgs);
        settings.setValue("RmbStyle", rButtonList.at(i)->style[RMB]);
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
            TxtColor = "white";
            TxtStyle = "bold";
            TxtDecoration = "normal";
            BkColor = "red";
            HoverColor = "blue";
            rButtonList.at(i)->style[LMB] = (assembleStyle());
            
        } else if ((i >= 30) && (i <= 35)) {
            rButtonList.at(i)->lmbName = new QString(QString("T %1 ").arg(i));
            rButtonList.at(i)->lmbCommand = new QString();
            rButtonList.at(i)->lmbArgs = new QString();
            TxtColor = "black";
            TxtStyle = "normal";
            TxtDecoration = "normal";
            BkColor = "orange";
            HoverColor = "white";
            rButtonList.at(i)->style[LMB] = (assembleStyle());
        } else {
            rButtonList.at(i)->lmbName = new QString(QString("T %1 ").arg(i));
            rButtonList.at(i)->lmbCommand = new QString();
            rButtonList.at(i)->lmbArgs = new QString();
            TxtColor = "black";
            TxtStyle = "normal";
            TxtDecoration = "normal";
            BkColor = "";
            HoverColor = "";
            rButtonList.at(i)->style[LMB] = (assembleStyle());
        }

        rButtonList.at(i)->mmbName = new QString(QString("M %1 ").arg(i));
        rButtonList.at(i)->mmbCommand = new QString();
        rButtonList.at(i)->mmbArgs = new QString();
        TxtColor = "black";
        TxtStyle = "normal";
        TxtDecoration = "normal";
        BkColor = "";
        HoverColor = "";
        rButtonList.at(i)->style[MMB] = (assembleStyle());

        // Need to set the name for rmb press. Plan is to have a popup menu
        rButtonList.at(i)->rmbName = new QString(QString("B %1 ").arg(i));
        rButtonList.at(i)->rmbCommand = new QString();
        rButtonList.at(i)->rmbArgs = new QString();
        TxtColor = ("black");
        TxtStyle = ("normal");
        TxtDecoration = ("normal");
        BkColor = "";
        HoverColor = "";
        rButtonList.at(i)->style[RMB] = (assembleStyle());
        // Set the main button(lmb) text
        rButtonList.at(i)->configButton();
    }
}
QString RPrefs::assembleStyle(void) {
    QString style;
    style = "QPushButton { background-color: ";
    style.append(BkColor);
    style.append("; color: ");
    style.append(TxtColor);
    style.append("; font: ");
    style.append(TxtStyle);
    style.append("; text-decoration: ");
    style.append(TxtDecoration);
    style.append("} ");
    style.append(" QPushButton:hover { color: ");
    style.append(HoverColor);
    style.append("} ");
    
    return style;
}