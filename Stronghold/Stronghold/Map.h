#ifndef MAP_GHJKJHG
#define MAP_GHJKJHG

#include "Castle.h"


class Map
{
private:
	friend class Castle;


	static size_t number_of_castle;
	static size_t speed_of_soldier;
	static size_t capacity_of_exit;//zarfiat khoroji az har ghale
	size_t capacity_of_enter;// num of soldier back the door / num of soldier in the castle
	Castle* castles;            



public:
	Map();
	Map(size_t n_castle , size_t sp);
	~Map();

	bool addAdge(int castle_1 , int castle_2 , int waight);
	bool convertMatrisToEdge(int matrix[] , int n);
	void deBug();

};




#endif
