/* ---------------------------------------------------------------------------
**
** File: Character.cpp
** Description: Contains The Implementation of the class Character
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "Character.h"

using namespace std;

//default constructer
Character::Character()
{
	_pos.Width = 0;
	_pos.Width = 0;
}

//constructer accepting a position struct
Character::Character(Position pos)
{
	_pos = pos;
}

//returns the characters life
int Character::GetLife()
{
	return _life;
}

//get the symbol used to represent the character on the map
char Character::GetSymbol()
{
	return _symbol;
}

//returns the position of the character on the map
Position Character::GetPosition()
{
	return _pos;
}

//updates the characters life
int Character::UpdateLife(int value)
{
	_life += value;
	return _life;
}

//set the amount of life the character has
void Character::SetLife(int value)
{
	_life = value;
}

//returns the amount of damage the character does
int Character::GetDamage()
{
	return _damage;
}

//set the amount of damage the character deals
void Character::SetDamage(int value)
{
	_damage = value;	
}

//returns true is the character is dead; false is alive
bool Character::IsDead()
{
	return _IsDead;
}

//track damage delt to the characters life
void Character::TakeDamage(int value)
{
	SetLife(_life - value);
	
	_IsDead = _life == 0;		
}

// set the position of the character on the map
void Character::SetPosition(Position pos)
{
	_pos = pos;
}