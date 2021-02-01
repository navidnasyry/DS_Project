#include "FibonacciHeapNode.h"



FibonacciHeapNode::FibonacciHeapNode()
{
	this->parent = nullptr;
	this->child = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}


FibonacciHeapNode::~FibonacciHeapNode()
{

	this->parent = nullptr;
	this->child = nullptr;
	this->left = nullptr;
	this->right = nullptr;
}
