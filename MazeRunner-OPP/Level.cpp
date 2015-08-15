/* ---------------------------------------------------------------------------
**
** File: Level.cpp
** Description: Contains The Implementation of the class Level
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "Level.h"
#include <fstream>
#include <ctime>
#include "Player.h"
#include "Enemy.h"
#include "Enums.h"

using namespace std;

//Default constructor
Level::Level()
{
	_goalSymbol = '#';
}

//Loads the map data into the internal data array
void Level::LoadLevelData(string LevelPath)
{
	ifstream in;
	in.open(LevelPath);

	if (!in.good())
	{
		throw exception("Invalid File Path");
	}

	in >> _height >> _width;
	in.ignore(100, END_OF_LINE_CHAR);

	for (int row = 1; row <= _height; row++)
	{
		char ch;
		for (int col = 1; col <= _width; col++)
		{
			in.get(ch);
			if ((row <= MAX_HEIGHT) && (col <= MAX_WIDTH))
				data[row - 1][col - 1] = ch;
		}

		in.ignore(100, END_OF_LINE_CHAR);
	}

	if ((_width > MAX_WIDTH) || (_height > MAX_HEIGHT)) 
	{
		throw exception("Map Data to large for window");
	}

	//Generate and Set Positions within Map Data
	SetPositions();
}

//Set the original positions of the player/goal/enemy actors
void Level::SetPositions()
{	
	//Set Goal Position
	cout << "Generating Goal Position" << endl;
	_goalPosition = GenerateRandomPOS();
	data[_goalPosition.Height][_goalPosition.Width] = _goalSymbol;

	//Set Player Position
	cout << "Generating Player Position" << endl;
	_player = Player(GenerateRandomPOS());
	data[_player.GetPosition().Height][_player.GetPosition().Width] = _player.GetSymbol();

	//Set Enemy Position if Enabled
	if (_EnableEnemy)
	{
		cout << "Generating Enemy Position" << endl;
		_Enemy = Enemy(GenerateRandomPOS());
		data[_Enemy.GetPosition().Height][_Enemy.GetPosition().Width] = _Enemy.GetSymbol();
	}
}

//generate a random position that is not occupied by a wall or other actor
Position Level::GenerateRandomPOS()
{
	srand(time(NULL));
	bool found = false;
	Position position;
	do {
		int width = rand() % _width;
		int Height = rand() % _height;

		if (data[Height][width] == ' ')
		{
			found = true;
			
			position.Height = Height;
			position.Width = width;
		}

	} while (!found);

	return position;
}

//get the maps height
int Level::GetHeight()
{
	return _height;
}

//get the maps width
int Level::GetWidth()
{
	return _width;
}

//returns the player object
Player Level::GetPlayer()
{
	return _player;
}

//returns the enemy object
Enemy Level::GetEnemy()
{
	return _Enemy;
}

//returns the symbol used for the goal
char Level::GetGoalSymbol()
{
	return _goalSymbol;
}

//updates the player's position on the map related to the direction passed in
GameState Level::UpdatePlayer(Direction direction)
{
	char targetFrame;
	Position targetPosition;
	switch (direction)
	{
	case Up:
		targetFrame = data[_player.GetPosition().Height - 1][_player.GetPosition().Width];		
		targetPosition.Width = _player.GetPosition().Width;
		targetPosition.Height = _player.GetPosition().Height - 1;
		break;
	case Down:
		targetFrame = data[_player.GetPosition().Height + 1][_player.GetPosition().Width];
		targetPosition.Width = _player.GetPosition().Width;
		targetPosition.Height = _player.GetPosition().Height + 1;
		break;
	case Left:
		targetFrame = data[_player.GetPosition().Height][_player.GetPosition().Width - 1];
		targetPosition.Width = _player.GetPosition().Width - 1;
		targetPosition.Height = _player.GetPosition().Height;
		break;
	case Right:
		targetFrame = data[_player.GetPosition().Height][_player.GetPosition().Width + 1];
		targetPosition.Width = _player.GetPosition().Width + 1;
		targetPosition.Height = _player.GetPosition().Height;
		break;
	case None:
		return Running;
		break;
	default:
		return Paused; //Sould Never Hit this Point
		break;
	}

	if (targetFrame == ' ') //if target frame is empty move to it
	{
		data[_player.GetPosition().Height][_player.GetPosition().Width] = ' ';
		_player.SetPosition(targetPosition);
		data[_player.GetPosition().Height][_player.GetPosition().Width] = _player.GetSymbol();
		return Running;
	}
	else if (targetFrame == _Enemy.GetSymbol()) //if target frame has an enemy take damage and check life
	{
		_player.TakeDamage(_Enemy.GetDamage());
		if (_player.IsDead())
			return LifeEnd;
	}
	else if (targetFrame == _goalSymbol) //if target fram has goal then end with victory
		return LevelEnd;	
}

//updates the enemy's position on the map related to the direction passed in
GameState Level::UpdateEnemy(Direction direction)
{
	char targetFrame;
	Position targetPosition;
	switch (direction)
	{
	case Up:
		targetFrame = data[_Enemy.GetPosition().Height - 1][_Enemy.GetPosition().Width];
		targetPosition.Width = _Enemy.GetPosition().Width;
		targetPosition.Height = _Enemy.GetPosition().Height - 1;
	case Down:
		targetFrame = data[_Enemy.GetPosition().Height + 1][_Enemy.GetPosition().Width];
		targetPosition.Width = _Enemy.GetPosition().Width;
		targetPosition.Height = _Enemy.GetPosition().Height + 1;
		break;
	case Left:
		targetFrame = data[_Enemy.GetPosition().Height][_Enemy.GetPosition().Width - 1];
		targetPosition.Width = _Enemy.GetPosition().Width - 1;
		targetPosition.Height = _Enemy.GetPosition().Height;
		break;
	case Right:
		targetFrame = data[_Enemy.GetPosition().Height][_Enemy.GetPosition().Width + 1];
		targetPosition.Width = _Enemy.GetPosition().Width + 1;
		targetPosition.Height = _Enemy.GetPosition().Height;
		break;
	case None:
		return Running;
		break;
	default:
		return Paused; //Sould Never Hit this Point
		break;
	}

	if (targetFrame == ' ') //if target frame is empty move to it
	{
		data[_Enemy.GetPosition().Height][_Enemy.GetPosition().Width] = ' ';
		_Enemy.SetPosition(targetPosition);		
		data[_Enemy.GetPosition().Height][_Enemy.GetPosition().Width] = _Enemy.GetSymbol();
		return Running;
	}
	else if (targetFrame == _Enemy.GetSymbol())  //if target frame has an enemy take damage and check life
	{
		_player.TakeDamage(_Enemy.GetDamage());
		if (_player.IsDead())
			return LifeEnd;
	}
}

//overload of the << operator; to make the printing of the map easier
ostream& operator<<(ostream& os, const Level& map)
{
	for (int i = 0; i < map._height; i++)
	{
		for (int j = 0; j < map._width; j++)
		{
			os << map.data[i][j];
		}

		os << endl;
	}
	return os;
}