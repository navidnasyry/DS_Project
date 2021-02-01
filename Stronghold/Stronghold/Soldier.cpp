#include "Soldier.h"



Soldier::Soldier()
{
}


Soldier::~Soldier()
{
}

Soldier& Soldier::operator=(const Soldier& r_val)
{
	this->castle_key = r_val.castle_key;
	this->power = r_val.power;
	return *this;
}
