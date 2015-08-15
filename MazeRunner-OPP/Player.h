/* ---------------------------------------------------------------------------
**
** File: Player.h
** Description:  Contains The prototypes for the class Player
**
** Inherits from Character.cpp
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player :
	public Character
{
public:
	//default constructor
	Player();

	//constructor that takes a position
	Player(Position pos);
};

#endif