#include "Castle.h"
#include "Map.h"

size_t create_castle_key()
{
	static size_t new_key = -1;
	new_key++;
	return new_key;
}


Castle::Castle()
{
	int num_of_neighbor = Map::number_of_castle;
	this->key = create_castle_key();
	this->neighbors = new int[num_of_neighbor];
	this->num_of_soldier = 0;
	for (int i=0 ; i<num_of_neighbor ; i++)
	{
		this->neighbors[i] = 0;

	}
	
}


Castle::~Castle()
{
	neighbors = nullptr;
	delete[] neighbors;
}

void Castle::addSoldier(int p)
{
	Soldier new_s;
	new_s.power = p;
	new_s.castle_key = this->key;
	avl.insertSoldier(new_s);
}

bool Castle::sendArmy()
{


	return true;
}

