/* ---------------------------------------------------------------------------
**
** File: score.cpp
** Description: Contains The Implementation of the class score
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "Score.h"

using namespace std;

//default constructor
Score::Score()
{
	_id = 0;
	_value = 0;
	_name = "Invalid";
}

//constructor taking an name and a score
Score::Score(string name, int score)
{
	_id = 0;
	_value = score;
	_name = name;
}

//constructor taking an name
Score::Score(string name)
{
	_id = 0;
	_value = 0;
	_name = name;
}

//constructor taking an id
Score::Score(int Id)
{
	_id = Id;
}

//constructor taking an id, score and name
Score::Score(int Id, int score, string name)
{
	_id = Id;
	_value = score;
	_name = name;
}

//returns the Id of the score object
int Score::GetId()
{
	return _id;
}

//returns the score
int Score::GetValue()
{
	return _value;
}

//returns the name
string Score::GetName()
{
	return _name;
}

//sets the score
void Score::SetValue(int value)
{
	_value = value;
}

//set the Name
void Score::SetName(string value)
{
	_name = value;
}

//set the Id
void Score::SetId(int value)
{
	_id = value;
}

//overload of the == operator to compair Id's
bool operator== (const Score &s1, const Score &s2)
{
	return (s1._id == s2._id);
}

//overload of the != operator to comapir Id's
bool operator!=(Score &s1, Score &s2)
{
	return !(s1 == s2);
}

//overlaod of the << operator to print a score object to a out stream
ostream& operator<<(ostream& os, const Score& score)
{
	os << score._id << " ";
	os << score._name << " ";
	os << score._value << endl;
	return os;
}