#ifndef FIBONACCIHEAPTREE_FGHJ
#define FIBONACCIHEAPTREE_FGHJ
#include "FibonacciHeapNode.h"


class FibonacciHeapTree
{

	friend class FibonacciHeapNode;
	friend class Soldier;

	int nH;
	FibonacciHeapNode* Min;


public:
	FibonacciHeapTree();
	~FibonacciHeapTree();
	FibonacciHeapNode* initializeHeap();
	void fibonacciLink(FibonacciHeapNode* y, FibonacciHeapNode* z);
	void addSoldier(Soldier soldier);
	void insert(FibonacciHeapNode* new_node);
	void Consolidate();
	void extractMin();
	void cut(FibonacciHeapNode* found, FibonacciHeapNode* temp);
	void cascaseCut(FibonacciHeapNode* t);
	void decreaseKey(FibonacciHeapNode* f, int val);
	void find(FibonacciHeapNode* Min,int last_val, int val);
	void del(int val);
	void display();


};




#endif