/* ---------------------------------------------------------------------------
**
** File: Level.h
** Description: Contains The prototypes for the class Level
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#ifndef LEVEL_H
#define LEVEL_H

#include "global.h"
#include "Position.h"
#include "Player.h"
#include "Enemy.h"
#include "Enums.h"

class Level
{
public:

	//Default constructor
	Level();

	//get the maps width
	int GetWidth();

	//get the maps height
	int GetHeight();
	
	//Loads the map data into the internal data array
	void LoadLevelData(std::string LevelPath);

	//returns the player object
	Player GetPlayer();

	//returns the enemy object
	Enemy GetEnemy();

	//returns the symbol used for the goal
	char GetGoalSymbol();

	//updates the player's position on the map related to the direction passed in
	GameState UpdatePlayer(Direction direction);

	//updates the enemy's position on the map related to the direction passed in
	GameState UpdateEnemy(Direction direction);

	//overload of the << operator; to make the printing of the map easier
	friend std::ostream& operator<<(std::ostream& os, const Level& level);
private:	

	//Set the original positions of the player/goal/enemy actors
	void SetPositions();

	//internal tracker for map width
	int _width;

	//internal tracker for map height
	int _height;

	//internal tracker for the map data
	char data[MAX_HEIGHT][MAX_WIDTH];

	//internal tracker for the goal position
	Position _goalPosition;

	//internal tracker for the symbol used to represent the goal
	char _goalSymbol;

	//generate a random position that is not occupied by a wall or other actor
	Position GenerateRandomPOS();

	//the player object
	Player _player;

	//the enemy object
	Enemy _Enemy;	
	
};
#endif