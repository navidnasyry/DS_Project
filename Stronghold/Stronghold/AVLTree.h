#ifndef AVLTREE_FGHJ
#define AVLTREE_FGHJ

#include <iostream>
#include "AVLNode.h"
#include "Vector.h"


using namespace std;

class AVLTree
{
	friend class AVLNode;
	friend class Soldier;

	AVLNode* root;
	Vector<AVLNode> leaves;

public:
	AVLTree();
	~AVLTree();
	void distructor(AVLNode* r);
	int height(AVLNode* r);
	AVLNode* rightRotate(AVLNode*& t);
	AVLNode* leftRotate(AVLNode*& t);
	AVLNode* doubleRightRotate(AVLNode*& t);
	AVLNode* doubleLeftRotate(AVLNode*& t);
	AVLNode* insert(Soldier p , AVLNode* t);
	AVLNode* remove(int p, AVLNode* t);
	Soldier removeSoldier(int power);
	void insertSoldier (Soldier new_s);
	AVLNode* findMin(AVLNode* t);
	AVLNode* findMax(AVLNode* t);
	void inorder(AVLNode* t);
	void inorderUpdate(AVLNode* t);
	void display();
	void updateLeavese();//when leaves Vector become empty then call this function**==> **importantl**
	Soldier popLeaf();
	//remove from tree maybe have bug
	//just search and remove whit power of soldier  
	//if our soldier from different castle by same power then we cant recognize them


};




#endif
