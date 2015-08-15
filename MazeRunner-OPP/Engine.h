/* ---------------------------------------------------------------------------
**
** File: Engine.h
** Description:  Contains The prototypes for the class Engine
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#ifndef ENGINE_H
#define ENGINE_H
#include "Level.h"
#include <ctime>


class Engine
{
public:

	//Constructor Takes a String containing the path  to the map to be played
	Engine(std::string Map);

	//starts the game loop; returns the gamestate
	GameState Start();
private:
	//the internal game loop, when it exits return the gamestate
	GameState GameLoop();

	//draws the map on screen
	void Update();

	//sets the paused flag as well as gamestate
	void pause();

	//sets the paused flag as well as gamestate
	void resume();	

	//inits the level object and loads the game map into memory
	void LoadMap();

	//The gamestate enum
	GameState _gameState;

	//denotes if the game has been paused or not
	bool _IsPaused;

	//internal tracker for the time
	int _Score;

	//internal tracker of the filepath for the map being played
	std::string _MapPath;

	//internal trafcker for the level/map
	Level _level;

	//gets the players input returning a direction enum value
	Direction GetInput();

	//gets a random direction for the enemy's movement returning a direction enum value
	Direction GetEnemyMovement();

	//the clock's tick time at the start of the map
	clock_t _startTime;

	//internal tracker to keep track of the players time
	int _elapsedTime;

	//prompts if the player would like to save thier time
	void End();
};

#endif