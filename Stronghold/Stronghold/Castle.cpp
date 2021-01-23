#include "Castle.h"

size_t create_castle_key()
{
	static size_t new_key = -1;
	new_key++;
	return new_key;
}


Castle::Castle()
{
	this->key = create_castle_key();

}


Castle::~Castle()
{
}


