/* ---------------------------------------------------------------------------
**
** File: Enemy.h
** Description: Contains The prototypes for the class Enemy
**
** Inherits from Character.cpp
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy :
	public Character
{
public:
	//default constructor
	Enemy();

	//constructor that takes a position
	Enemy(Position pos);
};

#endif