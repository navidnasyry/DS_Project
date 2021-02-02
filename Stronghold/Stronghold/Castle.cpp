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
	landlord_key = key;
	this->neighbors = new int[num_of_neighbor];
	this->num_of_soldier_in_castle = 0;
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

void Castle::addSoldier(int p , int owner_k)
{
	Soldier new_s;
	new_s.power = p;
	new_s.castle_key = owner_k;
	all_in_soldier.push_back(new_s);
	avl.insertSoldier(new_s);
	this->num_of_soldier_in_castle++;
	return;
}

void Castle::addSoldierToQueue(Soldier s)
{
	this->inder_queue.Push(s);
	return;
}

void Castle::addSoldierToFTree(Soldier s)
{
	fbTree.addSoldier(s);
	return;

}

void Castle::fillFHTreeWhitAllSoldier()
{
	////////////////////////////////////////////////////////////To Do
}

