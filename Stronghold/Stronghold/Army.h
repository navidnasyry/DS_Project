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




public:
	QueueLinkedList<Soldier> army_soldier;

	Army();
	Army(const Army&);
	Army(Army&&);
	Army(int num_of_soldier, size_t from, size_t attack_to, int distance);
	~Army();
	void addSoldier(Soldier s);
	bool lowDistance(int sp);
	Soldier popSoldier();
	bool isEmpty();
	size_t getFromWhich();
	size_t getAttackTo();
	Army& operator=(const Army& r_val);
	int getDistanse() { return this->distance; }
};






#endif