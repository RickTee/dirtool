/*
 * File: main.cpp
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#include <QApplication>
#include "rdirman.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);

    // create and show your widgets here
    RDirMan win;
    win.show();

    return app.exec();
}
