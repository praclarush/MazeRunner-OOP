/* ---------------------------------------------------------------------------
**
** File: Helpers.cpp
** Description: Contains The Implementation of the class Helpers
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "Helpers.h"
#include "stdafx.h"

//checks if the std::string contains only digits
bool is_digits(const std::string &str)
{
	return std::all_of(str.begin(), str.end(), ::isdigit);
}
 
//sets each char in the std::string to a lowercase
std::string toLower(std::string value)
{
	std::transform(value.begin(), value.end(), value.begin(), tolower);
	return value;
}