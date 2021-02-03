#ifndef MAP_GHJKJHG
#define MAP_GHJKJHG

#include "Castle.h"
#include "Army.h"
#include "Vector.h"
#include <vector>

class Map
{
private:
	friend class Castle;
	//friend class AVLTree;

	vector<Army> all_army;
	Castle* castles;

public:

	//fill from input : 
	
	static int capacity_of_exit;//zarfiat khoroji az har ghale
	static size_t number_of_castle;
	static size_t speed_of_soldier;


	Map();
	Map(size_t n_castle , size_t sp , int capacity_of_e);
	~Map();

	bool reviveSoldierFromStack(int index);
	void enterEnemyFromQueue(int index);
	void mainFunction();
	bool addAdge(int castle_1 , int castle_2 , int waight);
	bool convertMatrisToEdge(int matrix[] , int n);
	void deBug();
	void BFS();
	bool updateCastle(int caslte_key);
	void attackArmy(int index);
	void checkArmy();
	void inputSoldier(int index , Soldier s , float st);
	void writeBFS();
	void writeInorderAVL();
	void displayMap();



};




#endif
