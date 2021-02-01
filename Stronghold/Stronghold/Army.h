#ifndef ARMY_GHJK
#define ARMY_GHJK

#include "QueueLinkedList.h"
#include "Soldier.h"

class Army
{

	size_t from_which;//priority key of castle 
	size_t attack_to;//priority key of castle 
	int distance;//distance from distination
	int speed;
	int num_of_soldier;

	QueueLinkedList<Soldier> army_soldier;



public:
	Army();
	~Army();
};






#endif