/* ---------------------------------------------------------------------------
**
** File: Scores.h
** Description: Contains The prototypes of the class Scores
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#ifndef SCORES_H
#define SCORES_H

#include "stdafx.h"
#include "Score.h"
class Scores
{
public:

	//default constractor
	Scores();	

	//add a score to the internal vector collection
	void Add(Score score);

	//remove a score from the internal vector collection based on id
	void Remove(int Id);	

	//filter the internal vector collection based on a name
	void Filter(std::string name);

	//save the internal vector collection to a file
	bool Save();

	//overload of the << operator to write the internal vector collection to a out stream
	friend std::ostream& operator<<(std::ostream& os, const Scores& scores);

private:
	//internal tracker for the vector collection
	std::vector<Score> _Collection;

	//load the scores from a file to the internal vector collection
	void Load();

	//internal tracker for the filepath to the scores save file
	std::string _filePath;
};

#endif