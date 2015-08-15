/* ---------------------------------------------------------------------------
**
** File: Enemy.cpp
** Description: Contains The Implementation of the class Enemy
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "Enemy.h"

//default constructor
Enemy::Enemy()
{
	SetLife(10);
	SetDamage(5);
	_symbol = '?';	
}

//constructor that takes a position
Enemy::Enemy(Position pos) : Character(pos)
{
	SetLife(10);
	SetDamage(5);
	_symbol = '?';
}