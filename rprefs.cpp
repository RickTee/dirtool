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
    }
}
RPrefs::~RPrefs() {
}

void RPrefs::createButtons(void) {
    int i, j, k=0;
    RButton *temp;
    ButtonData data[36];

    for(i = 0; i < 6; i++) {
        for(j = 0; j < 6; j++) {
            data[k].lmbName =  new QString(QString("T %1 ").arg(k));
            data[k].mmbName =  new QString(QString("M %1 ").arg(k));
            data[k].rmbName =  new QString(QString("B %1 ").arg(k));
            temp = new RButton(&data[k]);
            rButtonList.append(temp);
            k++;
        }
    }
    std::cout << "k " << k << std::endl;
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
    for (i = 0; i < numOfButtons; i++) {
        settings.setArrayIndex(i);
//        settings.setValue("LmbName", this->rButtonList->at(i)->);
//        settings.setValue("LmbCommand", this->lmbCommand[i]);
//        settings.setValue("LmbArgs", this->lmbArgs[i]);
//        settings.setValue("LmbTxtColor", this->lmbTxtColor[i]);
//        settings.setValue("LmbTxtStyle", this->lmbTxtStyle[i]);
//        settings.setValue("LmbTxtDecoration", this->lmbTxtDecoration[i]);
//        settings.setValue("LmbBkColor;", this->lmbBkColor[i]);
//        settings.setValue("MmbName", this->mmbName[i]);
//        settings.setValue("MmbCommand", this->mmbCommand[i]);
//        settings.setValue("MmbArgs", this->mmbArgs[i]);
//        settings.setValue("MmbTxtColor", this->mmbTxtColor[i]);
//        settings.setValue("MmbTxtStyle", this->mmbTxtStyle[i]);
//        settings.setValue("MmbTxtDecoration", this->mmbTxtDecoration[i]);
//        settings.setValue("MmbBkColor;", this->mmbBkColor[i]);
    }
    settings.endArray();
    settings.endGroup();
    
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
    for(i = 0; i < numOfButtons; i++) {
        
    }
}