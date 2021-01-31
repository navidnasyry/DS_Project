#ifndef AVLTREE_FGHJ
#define AVLTREE_FGHJ
#include "AVLNode.h"

class AVLTree
{
	friend class AVLNode;

	AVLNode* root;


public:
	AVLTree();
	~AVLTree();
	void distructor(AVLNode* r);
	int height(AVLNode* r);
	AVLNode* rightRotate(AVLNode*& t);
	AVLNode* leftRotate(AVLNode*& t);
	AVLNode* doubleRightRotate(AVLNode*& t);
	AVLNode* doubleLeftRotate(AVLNode*& t);
	AVLNode* insert(int p , AVLNode* t);
	AVLNode* remove(int p, AVLNode* t);
	void removeSoldier(int power);
	void insertSoldier (int power);
	AVLNode* findMin(AVLNode* t);
	AVLNode* findMax(AVLNode* t);



};




#endif
