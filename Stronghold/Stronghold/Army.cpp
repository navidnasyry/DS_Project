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

Army::Army(const Army& a)
{
	this->attack_to = a.attack_to;
	this->from_which = a.from_which;
	this->num_of_soldier = a.num_of_soldier;
	this->distance = a.distance;
	this->speed = a.speed;
	this->army_soldier = a.army_soldier;
}

Army::Army(Army&& a)
{
	this->attack_to = a.attack_to;
	this->from_which = a.from_which;
	this->num_of_soldier = a.num_of_soldier;
	this->distance = a.distance;
	this->speed = a.speed;
	this->army_soldier = a.army_soldier;
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

size_t Army::getFromWhich()
{
	return this->from_which;
}

size_t Army::getAttackTo()
{
	return this->attack_to;
}

Army& Army ::operator=(const Army& a)
{
	this->attack_to = a.attack_to;
	this->from_which = a.from_which;
	this->num_of_soldier = a.num_of_soldier;
	this->distance = a.distance;
	this->speed = a.speed;
	this->army_soldier = a.army_soldier;
	return *this;
}
