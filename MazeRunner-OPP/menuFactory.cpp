/* ---------------------------------------------------------------------------
**
** File: menuFactory.cpp
** Description: Contains The Implementation of the class menuFactory
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "menuFactory.h"
#include "WindowsConsoleCmd.h"
#include "Files.h"
#include "Enums.h"
#include "global.h"
#include "Helpers.h"
#include <map>
#include <conio.h>

using namespace std;

//default constucter; private as to limit class to static methods only
menuFactory::menuFactory() {}

//contains user interaction for the start menu; returns a MainMenuOptions enum
MainMenuOptions menuFactory::StartMenu()
{
	drawMainMenu();

	char key;
	int selection = 0;
	MainMenuOptions choice = Exit_Game;
	bool exitMenu = false;
	do {
		key = _getch();

		if (isdigit(key))
		{
			selection = (key - '0');

			if (selection == 1)
			{
				choice = Select_Map;
				exitMenu = true;
			}
				
			else if (selection == 2)
			{
				choice = Score_List;
				exitMenu = true;
			}
			else if (selection == 3)
			{
				choice = Exit_Game;
				exitMenu = true;
			}
			else
				cout << "Invalid Selection" << endl;
		}
		else
		{
			cout << "Invlaid Selection" << endl;
		}
		
	} while (!exitMenu);
	
	return choice;
}

//contains user interaction for the select map; returns select map file name
string menuFactory::SelectMap()
{
	map<int, string> maps;
	getFiles(".\\Maps\\*.map", maps);
	drawMapMenu(maps);

	char key;
	
	do{
		key = _getch();

		if (isdigit(key))
		{
			int selection = (key - '0');

			if (selection != 0 && selection <= maps.size())
			{
				return maps[selection];
			}			
			else
			{
				cout << "Invlaid Selection" << endl;
			}
		}
		else if (key == 'r' || key == 'R')
		{
			getFiles(".\\Maps\\*.map", maps);
			drawMapMenu(maps);
		}		
		else if (key == 'e' || key == 'E')
		{
			_EnableEnemy = !_EnableEnemy;
			drawMapMenu(maps);
		}
	} while (key != 'm' && key != 'M');

	return "";
}

//contains uer interaction for the scores;
void menuFactory::ShowScores()
{
	Scores list = Scores();
	drawScoreMenu(list);

	string input;
	do {
		cin >> input;

		if (input.find(toLower("delete")) != std::string::npos)
		{
			int id;
			cin >> id;

			list.Remove(id);
			list.Save();
			ShowScores();
		}
		else if (input == "R" || input == "r")
		{
			ShowScores();			
		}
		else
		{
			list.Filter(input);
			drawScoreMenu(list);
			
		}

	} while (input != "M" && input != "m");
}

//draw the Main menu on screen
void menuFactory::drawMainMenu()
{
	ClearScreen();

	cout << string(35, '*') << endl;
	cout << "* Welcome to Maze Runner" << endl;
	cout << "* " << endl;
	cout << "* 1 - Select Map" << endl;
	cout << "* 2 - Score List" << endl;
	cout << "* 3 - Exit Game" << endl;
	cout << string(35, '*') << endl;
}

//draw the map menu on screen taking a map collection of the available maps to be played
void menuFactory::drawMapMenu(map<int, string>& maps)
{
	ClearScreen();

	cout << string(35, '*') << endl;
	cout << "* Select a Map to Load" << endl;
	cout << "* M - Main Menu" << endl;
	cout << "* R - Refresh Menu" << endl;
	cout << "* E - " << (_EnableEnemy ? "Disable" : "Enable") << " Enemy" << endl;

	for (int i = 1; i <= maps.size(); i++)
	{
		cout << "* " << i << " - " << maps[i] << endl;
	}
	cout << string(35, '*') << endl;
}

//draw the score menu and scores on screen
void menuFactory::drawScoreMenu(Scores scoreList)
{
	ClearScreen();

	cout << string(35, '*') << endl;
	cout << "* Times " << endl;
	cout << "* To Delete a entry type delete followed by the Id of the item. ie... delete 1 to delete the first record" << endl;
	cout << "* To filter by a name type that persons name and select enter" << endl;
	cout << "* R - remove current filter" << endl;
	cout << "* M - return to the Main Menu" << endl;
	cout << string(35, '*') << endl;
	cout << endl << endl;

	cout << scoreList;


}