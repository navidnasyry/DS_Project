
#include <iostream>
#include "Map.h"
using namespace std;
size_t Map::number_of_castle = 0;

Map::Map()
{
	Map::number_of_castle = 0;
	this->castles = nullptr;
	return;
}


Map::Map(size_t n_castle)
{
	Map::number_of_castle = n_castle;
	castles = new Castle[n_castle];

	return;
}

Map::~Map()
{
}

bool Map::addAdge(int castle_1, int castle_2, int weight)
{
	if (castle_2 >= Map::number_of_castle || castle_1 >= Map::number_of_castle)
	{
		return false;
	}

	castles[castle_1].neighbors[castle_2] = weight;
	castles[castle_2].neighbors[castle_1] = weight;

	return true;
}

bool Map::convertMatrisToEdge(int matrix[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		for (int j=i ; j<n ;j++)
		{
			if (matrix[i*n + j])
			{
				this->addAdge(i, j, matrix[i * n + j]);
			}
		}
	}

	return true;
}

void Map::deBug()
{
	int n = Map::number_of_castle;
	cout << endl << "matrix whit weight of edge : \n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << castles[i].neighbors[j] << "\t";
		}
		cout << endl;
	}


}











