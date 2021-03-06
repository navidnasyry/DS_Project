#ifndef CASTLE_HJKJHJHJ
#define CASTLE_HJKJHJHJ

#include "Soldier.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "AVLTree.h"
#include "FibonacciHeapTree.h"


class Castle
{
	friend class Map;
	friend class Soldier;

	int* neighbors;
	size_t key;
	size_t landlord_key;
	size_t num_of_soldier_in_castle;
	StackLinkedList<Soldier> die_soldier;
	float stack_const;//if is 0.5 => in two frame, one soldier exit from stack :)
	QueueLinkedList<Soldier> inder_queue;
	size_t capacity_of_enter;// num of soldier back the door / num of soldier in the castle
	AVLTree avl;
	Vector<Soldier> all_in_soldier;
	FibonacciHeapTree fbTree;

	 

public:
	Castle();

	~Castle();
	void addSoldier(int power , int owner_k);//in avl
	void addSoldierToQueue(Soldier s);
	void addSoldierToFTree(Soldier s);
	void fillFHTreeWhitAllSoldier();

};




#endif
