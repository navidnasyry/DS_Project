#include "Soldier.h"
#include "Map.h"


Soldier::Soldier()
{
	this->speed = Map::speed_of_soldier;
	return;
}


Soldier::Soldier(int p)
{
	this->power = p;
	this->speed = Map::speed_of_soldier;
	return;
}

Soldier::~Soldier()
{
}

Soldier::Soldier(const Soldier& s)
{
	this->castle_key = s.castle_key;
	this->power = s.power;
	this->speed = s.speed;
	return;
}

Soldier::Soldier(Soldier&& s)
{

	this->castle_key = s.castle_key;
	this->power = s.power;
	this->speed = s.speed;
	return;
}

Soldier& Soldier::operator=(const Soldier& r_val)
{
	this->castle_key = r_val.castle_key;
	this->power = r_val.power;
	return *this;
}
