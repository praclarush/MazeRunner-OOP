/* ---------------------------------------------------------------------------
**
** File: Files.h
** Description: Contains The prototypes used to access the Windows File System
** for Files.cpp 
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#pragma once

#include "targetver.h"
#include "stdafx.h"
#include <map>


//Get Files from provided directory using a Map<int, string> format
void getFiles(char* dir, std::map<int, std::string>& files);
