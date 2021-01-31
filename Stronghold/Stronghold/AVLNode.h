#ifndef AVLNODE_FGHJKL
#define AVLNODE_FGHJKL

#include "Soldier.h"

class AVLNode
{
	friend class Soldier;
	friend class AVLTree;


	Soldier data;
	int key;
	AVLNode* left;
	AVLNode* right;
	int height;


public:
	AVLNode();
	~AVLNode();
};





#endif