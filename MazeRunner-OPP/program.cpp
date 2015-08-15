/* ---------------------------------------------------------------------------
**
** File: program.cpp 
** Description: program entry point
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "menuFactory.h"
#include "Enums.h"
#include "Engine.h"

using namespace std;

void startGame();
void loadScore();

//entry point of the program; loads the varius menus
int main()
{
	MainMenuOptions menuChoice = menuFactory::StartMenu();

	switch (menuChoice)
	{
	case Select_Map:
		startGame();
		break;
	case Score_List:
		loadScore();
		break;
	case Exit_Game:		
		return 0;
		break;
	default:
		main();
	}	
	return 0;
}

//create and setup engine object and calls engine.start();
void startGame()
{
	cout << "Game Start!";

	string map = menuFactory::SelectMap();

	if (map != "")
	{
		Engine engine = Engine(".\\Maps\\" + map);

		GameState state = engine.Start();

		if (state == LifeEnd)
		{
			cout << "Game Over! You've Died" << endl;
			system("pause");
			main();
		}
		else if (state == LevelEnd)
		{
			cout << "Congragulation's You've Found the Goal!" << endl;
			system("pause");
			main();
		}
		else if (state == Quit)
			main();
	}
	else
		main();
}

//calls the scores menuFacotry
void loadScore()
{
	menuFactory::ShowScores();
	
	main();
}