#include "Soldier.h"
#include "Map.h"


Soldier::Soldier()
{
	this->speed = Map::speed_of_soldier;
	return;
}


Soldier::Soldier(int p , size_t owner)
{
	this->power = p;
	this->castle_key = owner;
	this->speed = Map::speed_of_soldier;
	return;
}

size_t Soldier::getPower()
{
	return this->power;
}

size_t Soldier::getCastleKey()
{
	return this->castle_key;
}

bool operator==( Soldier& r_val,  Soldier& l_val)
{
	if (r_val.castle_key == l_val.castle_key && r_val.power == l_val.power)
	{
		return true;
	}
	return false;


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
