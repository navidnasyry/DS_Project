#ifndef FIBONACCIHEAPNODE_DFGHJK
#define FIBONACCIHEAPNODE_DFGHJK

#include "Soldier.h"

class FibonacciHeapNode
{
	friend class FibonacciHeapTree;
	friend class Soldier;

	Soldier soldier;
	int power;
	int degree;
	FibonacciHeapNode* parent;
	FibonacciHeapNode* child;
	FibonacciHeapNode* left;
	FibonacciHeapNode* right;
	char mark;
	char C;



public:
	FibonacciHeapNode();
	~FibonacciHeapNode();
};




#endif