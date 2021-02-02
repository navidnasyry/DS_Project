#ifndef MAP_GHJKJHG
#define MAP_GHJKJHG

#include "Castle.h"
#include "Army.h"
#include "Vector.h"

class Map
{
private:
	friend class Castle;


	Castle* castles;            
	Vector<Army> all_army;


public:

	//fill from input : 
	static int capacity_of_exit;//zarfiat khoroji az har ghale
	static size_t number_of_castle;
	static size_t speed_of_soldier;


	Map();
	Map(size_t n_castle , size_t sp);
	~Map();

	bool addAdge(int castle_1 , int castle_2 , int waight);
	bool convertMatrisToEdge(int matrix[] , int n);
	void deBug();
	void BFS();
	bool updateCastle(int caslte_key);
	void checkArmy();

};




#endif
