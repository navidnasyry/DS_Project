#ifndef MAP_GHJKJHG
#define MAP_GHJKJHG

#include "Vector.h"
#include "Castle.h"


class Map
{
private:
	friend class Castle;


	size_t number_of_castle;
	Castle* castles;            



public:
	Map();
	Map(size_t n_castle);
	~Map();

	bool addAdge(int castle_1 , int castle_2 , int waight);



};




#endif
