/* ---------------------------------------------------------------------------
**
** File: scores.cpp
** Description: Contains The Implementation of the class scores
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/

#include "stdafx.h"
#include "Scores.h"
#include <fstream>

using namespace std;

//default constractor
Scores::Scores()
{
	_filePath = ".\\Scores.dat";
	Load();
}

//add a score to the internal vector collection
void Scores::Add(Score score)
{
	score.SetId(_Collection.size() + 1);
	_Collection.push_back(score);
}

//remove a score from the internal vector collection based on id
void Scores::Remove(int Id)
{
	_Collection.erase(std::find(_Collection.begin(), _Collection.end() - 1, Score(Id)));
}

//save the internal vector collection to a file
bool Scores::Save()
{
	ofstream oFile;
	oFile.open(_filePath);

	if (oFile.good())
	{
		for (vector<Score>::iterator it = _Collection.begin(); it != _Collection.end(); ++it)
		{
			oFile << *it;
		}

		oFile.close();

		return true;
	}
	else
		return false;	
}

//filter the internal vector collection based on a name
void Scores::Filter(string name)
{
	vector<Score> FilterdList;

	for (vector<Score>::iterator it = _Collection.begin(); it != _Collection.end(); ++it)
	{
		if ((*it).GetName() == name)
			FilterdList.push_back(*it);
	}

	_Collection = FilterdList;
}

//load the scores from a file to the internal vector collection
void Scores::Load()
{
	ifstream iFile;
	iFile.open(_filePath);

	int id;
	int value;
	string name;

	if (iFile.good())
	{
		while (iFile >> id >> name >> value)
		{
			Score newScore = Score(id, value, name);
			_Collection.push_back(newScore);
		}
	}

	iFile.clear();
}

//overload of the << operator to write the internal vector collection to a out stream
ostream& operator<<(ostream& os, const Scores& scores)
{
	for (auto it = begin(scores._Collection); it != end(scores._Collection); ++it)
	{
		os << *it;
	}
	os << endl;

	return os;
}