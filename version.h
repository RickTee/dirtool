/*
 * File: version.h
 * Program: DirTool
 * Author: Richard G Townsend
 * Email: ricktee@virginmedia.com
 * Created on: 22 February 2023, 07:24
 * GNU GENERAL PUBLIC LICENSE Version 3, 29 June 2007
 */

#ifndef __VERSION_H__
#define __VERSION_H__

#define SPC         " "
#define RELEASE     "0.0"
#define REVISION    ".2"
#define UPDATE      "22 Feb 2023"
#define DATE        "(Feb 2023)"
#define YEAR        "2023 - 2030"
#define VERSION     "Version: " RELEASE REVISION SPC DATE

#define AUTHOR      "Richard G Townsend"
#define TITLE       "RdTool "
#define DESCRIPTION "written in C++ with the Qt library"
//#define VERSTAG     "$VER: " TITLE VERSION SPC DESCRIPTION
#define VERSTAG     TITLE VERSION SPC DESCRIPTION
#define APPLICATION TITLE VERSION
#define COPYRIGHT   "(C) " YEAR SPC AUTHOR
#define EMAIL       "ricktee@virginmedia.com"

#endif
