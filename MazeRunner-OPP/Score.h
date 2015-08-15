/* ---------------------------------------------------------------------------
**
** File: Score.h
** Description: Contains The prototypes of the class Score
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#ifndef SCORE_H
#define SCORE_H

class Score
{
public:

	//default constructor
	Score();

	//constructor taking an name and a score
	Score(std::string name, int score);

	//constructor taking an name
	Score(std::string name);

	//constructor taking an id
	Score(int Id);

	//constructor taking an id, score and name
	Score(int Id, int score, std::string name);

	//returns the Id of the score object
	int GetId();

	//sets the score
	void SetValue(int value);

	//returns the score
	int GetValue();

	//set the Name
	void SetName(std::string value);

	//returns the name
	std::string GetName();

	//set the Id
	void SetId(int value);

	//overload of the == operator to compair Id's
	friend bool operator== (const Score &n1, const Score &n2);	

	//overload of the != operator to comapir Id's
	friend bool operator!=(const Score &s1, const Score &s2);

	//overlaod of the << operator to print a score object to a out stream
	friend std::ostream& operator<<(std::ostream& os, const Score& score);

private:
	//internal tracker for Id
	int _id;

	//internal tracker for score
	int _value;

	//internal tracker for name
	std::string _name;
};

#endif