#ifndef CASTLE_HJKJHJHJ
#define CASTLE_HJKJHJHJ

#include "Soldier.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "AVLTree.h"

class Castle
{
	friend class Map;
	friend class Soldier;

	int* neighbors;
	size_t key;
	size_t num_of_soldier;
	StackLinkedList<Soldier> die_soldier;
	float stack_const;//if is 0.5 => in two frame, one soldier exit from stack :)
	QueueLinkedList<Soldier> inder_queue;
	AVLTree avl;

	 

public:
	Castle();
	~Castle();
	void addSoldier(int power);
};




#endif
