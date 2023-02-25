/*
 * File: rprefs.cpp
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 11:06
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include <qt5/QtCore/qlist.h>

#include "rprefs.h"

using std::cout;
using std::endl;
RPrefs::RPrefs() {
    fileName = new QString(HOME_PATH);
    fileName->append(FILE_NAME);

    //cout << "fileName " << fileName->toStdString() << endl;
    //rButtonList = new QList<RButton*>();
    // Create button list
    numOfButtons = 36;
    createButtons();
    //rButtonList

    if (QFile(*fileName).exists()) {
        loadPrefs();
    } else {
        setDefaultPrefs();
        savePrefs();
    }
}
RPrefs::~RPrefs() {
}
void RPrefs::createButtons(void) {
    int i;
    RButton *temp;
    ButtonData data[36];

    for (i = 0; i < 36; i++) {
        temp = new RButton();
        temp->lmbName = new QString(QString("T %1 ").arg(i));
        temp->lmbCommand = new QString(QString());
        temp->lmbArgs = new QString(QString());
        temp->lmbTxtColor = new QString(QString("black"));
        temp->lmbTxtStyle = new QString(QString("normal"));
        temp->lmbTxtDecoration = new QString(QString("normal"));
        temp->lmbBkColor = new QString(QString("transparent"));

        temp->mmbName = new QString(QString("M %1 ").arg(i));
        temp->mmbCommand = new QString(QString());
        temp->mmbArgs = new QString(QString());
        temp->mmbTxtColor = new QString(QString("black"));
        temp->mmbTxtStyle = new QString(QString("normal"));
        temp->mmbTxtDecoration = new QString(QString("normal"));
        temp->mmbBkColor = new QString(QString("transparent"));

        temp->rmbName =  new QString(QString("B %1 ").arg(i));
        //            data[i].rmbCommand =  new QString(QString());
        //            data[i].rmbArgs =  new QString(QString());
        //            data[i].rmbTxtColor =  new QString(QString("black"));
        //            data[i].rmbTxtStyle =  new QString(QString("normal"));
        //            data[i].rmbTxtDecoration =  new QString(QString("normal"));
        //            data[i].rmbBkColor =  new QString(QString("transparent"));
        
        rButtonList.append(temp);
        temp = NULL;
    }
}
void RPrefs::loadPrefs(void) {
    //    int i;
    //
    //    if (QFile(*this->fileName).exists()) {
    //        QSettings settings(*this->fileName, QSettings::NativeFormat);
    //        settings.beginGroup("Game");
    //        this->gameType = settings.value("type", "").toInt();
    //        settings.endGroup();
    //
    //        settings.beginGroup("PlayerNames");
    //        this->numOfPlayers = settings.beginReadArray("Players");
    //        for (i = 0; i < this->numOfPlayers; i++) {
    //            settings.setArrayIndex(i);
    //            // if this player name already exists delete the QString
    //            if(this->playerNames[i] != NULL) 
    //            {
    //                delete this->playerNames[i];
    //                this->playerNames[i] = NULL;
    //            }
    //            this->playerNames[i] = new QString(settings.value("Name").toString());
    //        }
    //        settings.endArray();
    //        settings.endGroup();
    //        
    //        settings.beginGroup("HighScoreNames");
    //        settings.beginReadArray("HighScores");
    //        for (i = 0; i < this->numOfHighscores; i++) {
    //            settings.setArrayIndex(i);
    //            this->highScoreNames[i] = new QString(settings.value("Name").toString());
    //            this->highScoreScores[i] = settings.value("Score").toInt();
    //        }
    //        settings.endArray();
    //        settings.endGroup();
    //    
    //    } else {
    // Set defaults and save
    //        this->playerNames[0] = new QString("Player 1");
    //        savePrefs();
    //    }
}
void RPrefs::savePrefs(void) {
    int i;
    QSettings settings(*this->fileName, QSettings::NativeFormat);
    settings.beginGroup("Buttons");
    settings.beginWriteArray("ButtonNames");
    for (i = 0; i < rButtonList.count(); i++) {
        settings.setArrayIndex(i);
//        settings.setValue("LmbName", *rButtonList.at(i)->bdata->lmbName);
//        settings.setValue("LmbCommand", *rButtonList.at(i)->bdata->lmbCommand);
//        settings.setValue("LmbArgs", *rButtonList.at(i)->bdata->lmbArgs);
//        settings.setValue("LmbTxtColor", *rButtonList.at(i)->bdata->lmbTxtColor);
//        settings.setValue("LmbTxtStyle", *rButtonList.at(i)->bdata->lmbTxtStyle);
//        settings.setValue("LmbTxtDecoration", *rButtonList.at(i)->bdata->lmbTxtDecoration);
//        settings.setValue("LmbBkColor;", *rButtonList.at(i)->bdata->lmbBkColor);
//        settings.setValue("MmbName", *rButtonList.at(i)->bdata->mmbName);
//        settings.setValue("MmbCommand", *rButtonList.at(i)->bdata->mmbCommand);
//        settings.setValue("MmbArgs", *rButtonList.at(i)->bdata->mmbArgs);
//        settings.setValue("MmbTxtColor", *rButtonList.at(i)->bdata->mmbTxtColor);
//        settings.setValue("MmbTxtStyle", *rButtonList.at(i)->bdata->mmbTxtStyle);
//        settings.setValue("MmbTxtDecoration", *rButtonList.at(i)->bdata->mmbTxtDecoration);
//        settings.setValue("MmbBkColor;", *rButtonList.at(i)->bdata->mmbBkColor);        
    }
    settings.endArray();
    settings.endGroup();

    std::cout << "rButtonList.count() " << rButtonList.count() << std::endl;
    std::cout << "rButtonList.at(25)->lmbTxtDecoration " << rButtonList.at(25)->lmbTxtDecoration->toStdString() << std::endl;
    

    //    settings.beginGroup("HighScoreNames");
    //    settings.beginWriteArray("HighScores");
    //    for (i = 0; i < numOfHighscores; i++) {
    //        settings.setArrayIndex(i);
    //        settings.setValue("Name", *this->highScoreNames[i]);
    //        settings.setValue("Score", this->highScoreScores[i]);
    //    }
    //    settings.endArray();
    //    settings.endGroup();
}
void RPrefs::setDefaultPrefs(void) {
    int i;
    numOfButtons = 4;
    for (i = 0; i < numOfButtons; i++) {

    }
}