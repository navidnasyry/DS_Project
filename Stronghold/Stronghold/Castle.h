#ifndef CASTLE_HJKJHJHJ
#define CASTLE_HJKJHJHJ

#include "Soldier.h"
#include "StackLinkedList.h"
#include "QueueLinkedList.h"
#include "AVLTree.h"

class Castle
{
	friend class Map;


	int* neighbors;
	size_t key;
	size_t num_of_soldier;
	StackLinkedList<Soldier> die_soldier;
	QueueLinkedList<Soldier> inder_queue;
	AVLTree avl;

	 

public:
	Castle();
	~Castle();
};




#endif
