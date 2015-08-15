/* ---------------------------------------------------------------------------
**
** File: Player.cpp 
** Description: Contains The Implementation of the class Player
**
** Inherits from Character.cpp
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "Player.h"

//default constructor
Player::Player()
{
	SetLife(10);
	SetDamage(0);
	_symbol = '*';
}

//constructor that takes a position
Player::Player(Position pos) : Character(pos)
{
	SetLife(10);
	SetDamage(0);
	_symbol = '*';
}