/*
 * File: rprefs.cpp
 * Program: RdTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 11:06
 * Copyright (C) 2023 - 2030  Richard G Townsend
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include "rprefs.h"

using std::cout;
using std::endl;

RPrefs::RPrefs() {
    fileName = new QString(HOME_PATH);
    fileName->append(FILE_PATH);
    fileName->append(FILE_NAME);
    
}
RPrefs::~RPrefs() {
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
        settings.setValue("Name", *buttonNames[i]);
    }
    settings.endArray();
    settings.endGroup();
    
    settings.beginGroup("HighScoreNames");
    settings.beginWriteArray("HighScores");
    for (i = 0; i < this->numOfHighscores; i++) {
        settings.setArrayIndex(i);
        settings.setValue("Name", *this->highScoreNames[i]);
        settings.setValue("Score", this->highScoreScores[i]);
    }
    settings.endArray();
    settings.endGroup();
}
