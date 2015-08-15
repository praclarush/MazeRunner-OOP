/* ---------------------------------------------------------------------------
**
** File: Character.h
** Description: Contains The prototypes for the class Character
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#ifndef CHARACTER_H
#define CHARACTER_H

#include "Position.h"
class Character
{
private:
	//tracks the amount of life the character has
	int _life;

	//Struct used to track the position of the character on the map
	Position _pos;

	//tracks the amount of damage the character deals
	int _damage;

	//tracks if the character is alive or dead
	bool _IsDead;
public:
	//default constructer
	Character();

	//constructer accepting a position struct
	Character(Position pos);

	//updates the characters life
	int UpdateLife(int value);

	//returns the characters life
	int GetLife();

	//returns the amount of damage the character does
	int GetDamage();

	//returns the position of the character on the map
	Position GetPosition();

	// set the position of the character on the map
	void SetPosition(Position pos);

	//get the symbol used to represent the character on the map
	char GetSymbol();

	//returns true is the character is dead; false is alive
	bool IsDead();

	//track damage delt to the characters life
	void TakeDamage(int value);
protected:
	// the symbol used to represent the character on the map
	char _symbol;

	//set the amount of life the character has
	void SetLife(int value);

	//set the amount of damage the character deals
	void SetDamage(int value);
};

#endif