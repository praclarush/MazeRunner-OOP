/* ---------------------------------------------------------------------------
**
** File: Enums.h
** Description:  Contains Enum Implementations
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/
#ifndef ENUMS_H
#define ENUMS_H

//Enums for the main menu options
enum MainMenuOptions
{
	Select_Map = 1,
	Score_List = 2,
	Exit_Game = 3,
};

//the various game states the game can have
enum GameState
{
	Running = 1,
	LevelEnd = 2,
	LifeEnd = 3,
	Paused = 4,
	Quit = 5,
};

//the five possible directions it can move
enum Direction
{
	Up = 1,
	Down = 2,
	Left = 3,
	Right = 4,
	None = 5,
};

#endif