#include "Army.h"
#include "Map.h"


Army::Army()
{
	distance = -1;
	speed = Map::speed_of_soldier;
	num_of_soldier = 0;

}


Army::Army(int num_of_soldier, size_t from, size_t attack_to, int distance)
{
	speed = Map::speed_of_soldier;
	this->num_of_soldier = num_of_soldier;
	this->from_which = from;
	this->attack_to = attack_to;
	this->distance = distance;
	return;
}

Army::~Army()
{
}

void Army::addSoldier(Soldier s)
{
	army_soldier.Push(s);
	return;
}

bool Army::lowDistance(int sp)
{
	this->distance -= sp;
	if (distance <= 0)
	{
		return true;
	}
	return false;
}

Soldier Army::popSoldier()
{
	Soldier s = army_soldier.Pop();
	this->num_of_soldier--;
	return s;
}

bool Army::isEmpty()
{
	if (army_soldier.isEmpty())
	{
		return true;
	}
	return false;
}
