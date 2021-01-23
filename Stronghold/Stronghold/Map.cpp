#include "Map.h"



Map::Map()
{
	this->number_of_castle = 0;
	this->castles = nullptr;
	return;
}


Map::Map(size_t n_castle)
{
	this->number_of_castle = n_castle;
	castles = new Castle[n_castle];

	return;
}

Map::~Map()
{
}

bool Map::addAdge(int castle_1, int castle_2, int weight)
{
	if (castle_2>= number_of_castle || castle_1>= number_of_castle)
	{
		return false;
	}

	for (int i=0 ; i<number_of_castle ; i++)
	{

	}


	return true;
}
