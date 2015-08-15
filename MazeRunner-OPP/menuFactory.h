/* ---------------------------------------------------------------------------
**
** File: menuFactory.h
** Description:  Contains The prototypes for the static class menuFactory.cpp
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#ifndef MENUFACTORY_H
#define MENUFACTORY_H

#include <map>
#include "Scores.h"
#include "Enums.h"

class menuFactory
{
private:
	//default constucter; private as to limit class to static methods only
	menuFactory();

	//draw the Main menu on screen
	void static drawMainMenu();

	//draw the map menu on screen taking a map collection of the available maps to be played
	void static drawMapMenu(std::map<int, std::string>& maps);

	//draw the score menu and scores on screen
	void static drawScoreMenu(Scores scoreList);
public:

	//contains user interaction for the start menu; returns a MainMenuOptions enum
	static MainMenuOptions StartMenu();

	//contains user interaction for the select map; returns select map file name
	static std::string SelectMap();

	//contains uer interaction for the scores;
	static void ShowScores();
};

#endif