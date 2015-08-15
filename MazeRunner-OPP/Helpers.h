/* ---------------------------------------------------------------------------
**
** File: Helpers.h
** Description:  Contains The prototypes for Helpers.cpp
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/
#ifndef HELPERS_H
#define HELPERS_H

#include "stdafx.h"

//checks if the std::string contains only digits
bool is_digits(const std::string &str);

//sets each char in the std::string to a lowercase
std::string toLower(std::string value);

#endif