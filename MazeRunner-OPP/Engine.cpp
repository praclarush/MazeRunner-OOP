/* ---------------------------------------------------------------------------
**
** File: Engine.cpp
** Description: Contains The Implementation of the class Engine
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "Engine.h"
#include "Level.h"
#include "WindowsConsoleCmd.h"
#include "Enums.h"
#include <conio.h>
#include <ctime>
#include "Score.h"
#include "Scores.h"

using namespace std;

//Constructor Takes a String containing the path  to the map to be played
Engine::Engine(string Map)
{
	_MapPath = Map;
	_IsPaused = false;
	_Score = 0;
	_gameState = Running;
	_elapsedTime = 0;
	LoadMap();

}

//the internal game loop, when it exits return the gamestate
GameState Engine::GameLoop()
{
	Update();

	clock_t clockTicks = clock() - _startTime;
	
	_elapsedTime = clockTicks / (double)CLOCKS_PER_SEC;

	switch (_gameState)
	{
	case Running:
	{
		Direction move = GetInput();

		if (_gameState == Quit)
			break;

		_gameState = _level.UpdatePlayer(move);
		if (_gameState == LevelEnd)
			return LevelEnd;
		else if (_gameState == LifeEnd)
			return LifeEnd;
		_gameState = _level.UpdateEnemy(GetEnemyMovement());
		break;
	}
	case LevelEnd:
		return LevelEnd;
		break;
	case LifeEnd:
		return LifeEnd;
		break;
	case Paused:
		_gameState = _level.UpdatePlayer(GetInput());
		break;
	case Quit:
		return Quit;
		break;
	default:
		_gameState = Running;
		break;
	}

	if (_IsPaused)
		_gameState = Paused;

	if (_gameState != Running || _gameState != Paused)
		GameLoop();
	else
		return _gameState;
}

//gets a random direction for the enemy's movement returning a direction enum value
Direction Engine::GetEnemyMovement()
{ 
	srand(time(NULL));
	int direction = rand() % 5;	
	return static_cast<Direction>(direction);	
}

//gets the players input returning a direction enum value
Direction Engine::GetInput()
{
	char key;
	if (_IsPaused)
	{
		do {
			key = _getch();

			if (key == 'p' || key == 'P')
				resume();
		} while (_IsPaused);
	
		return None;
	}
	else
	{
		Direction moveDirection;
		do {
			key = _getch();

			switch (key)
			{
			case 'w':
				moveDirection = Up;
				break;
			case 's':
				moveDirection = Down;
				break;
			case 'a':
				moveDirection = Left;
				break;
			case 'd':
				moveDirection = Right;
				break;
			case 'p':
				pause();
				moveDirection = None;
				break;
			case ESC:
				_gameState = Quit;
				moveDirection = None;
				break;
			default:
				moveDirection = None;
				break;
			}
		} while (moveDirection == None && _gameState == Running);

		return moveDirection;
	}		
}

//draws the map on screen
void Engine::Update()
{
	ClearScreen();

	//write the instructions
	cout << "You are the '" << _level.GetPlayer().GetSymbol() << "' symbol. Your goal is to reach the end of the maze\n";
	cout << "marked by the '" << _level.GetGoalSymbol() << "' symbol. You can quit at anytime by pressing the ESC key\n";
	cout << "if you get hit by an enemy marked by the '" << _level.GetEnemy().GetSymbol() << "' symbol you will take damage.\n when all your life is gone you lose" << endl;
	cout << "Use the w (up), s (down), a (left), d (right), p (pause/unpause) to navigate the maze and reach the goal." << endl << endl;;
	cout << "Life: " << _level.GetPlayer().GetLife() << string(10, ' ') << "Time: " << _elapsedTime;
	cout << endl << endl;

	if (!_IsPaused)
		cout << _level;
	else
		cout << "GAME PAUSED!" << endl;
}

//sets the paused flag as well as gamestate
void Engine::pause()
{
	_IsPaused = true;
	_gameState = Paused;
}


//sets the paused flag as well as gamestate
void Engine::resume()
{
	_IsPaused = false;
	_gameState = Running;
}

//starts the game loop; returns the gamestate
GameState Engine::Start()
{
	_gameState = Running;
	_IsPaused = false;
	_startTime = clock();

	GameLoop();

	if (_gameState == LevelEnd)
	{
		End();
	}

	return _gameState;
}

//prompts if the player would like to save thier time
void Engine::End()
{
	ClearScreen();
	
	string name;
	

	cout << "You Finish Time was: " << _elapsedTime << " Seconds" << endl;
	cout << "Save Score? y - Yes, n - No" << endl;
	
	char save;
	cin >> save;

	if (save == 'y' || save == 'Y')
	{
		cout << "Please Enter your Name" << endl;
		cin >> name;

		Score score = Score(name, _elapsedTime);

		Scores scores = Scores();
		scores.Add(score);
		scores.Save();
	}
}

//inits the level object and loads the game map into memory
void Engine::LoadMap()
{
	_level = Level();
	_level.LoadLevelData(_MapPath);
}