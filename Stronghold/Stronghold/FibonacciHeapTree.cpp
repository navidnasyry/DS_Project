#include <cmath>
#include <iostream>
using namespace std;


#include "FibonacciHeapTree.h"

FibonacciHeapTree::FibonacciHeapTree()
{
	this->Min = initializeHeap();
	this->nH = 0;
	return;
}


FibonacciHeapTree::~FibonacciHeapTree()
{
}

FibonacciHeapNode* FibonacciHeapTree::initializeHeap()
{
	FibonacciHeapNode* n;
	n = nullptr;
	return n;
}

void FibonacciHeapTree::fibonacciLink(FibonacciHeapNode* y, FibonacciHeapNode* z)
{
	(y->left)->right = y->right;
	(y->right)->left = y->left;
	if (z->right == z)
		Min = z;
	y->left = y;
	y->right = y;
	y->parent = z;
	if (z->child == nullptr)
		z->child = y;
	y->right = z->child;
	y->left = (z->child)->left;
	((z->child)->left)->right = y;
	(z->child)->left = y;
	if (y->power < (z->child)->power)
		z->child = y;
	z->degree++;

	return;
}

void FibonacciHeapTree::addSoldier(Soldier soldier)
{
	FibonacciHeapNode* x = new FibonacciHeapNode;
	x->power = soldier.power;
	x->soldier = soldier;
	insert(x);

	return ;
}

void FibonacciHeapTree::insert(FibonacciHeapNode* new_node)
{
	
	new_node->degree = 0;
	new_node->parent = nullptr;
	new_node->child = nullptr;
	new_node->left = new_node;
	new_node->right = new_node;
	new_node->mark = 'W';
	new_node->C = 'N';
	if (Min != nullptr)
	{
		Min->left->right = new_node;
		new_node->right = Min;
		new_node->left = Min->left;
		Min->left = new_node;
		if (new_node->power < Min->power)
		{
			Min = new_node;
		}
	}
	else
	{
		Min = new_node;
	}
	nH++;

}

void FibonacciHeapTree::extractMin()
{
	if (Min == nullptr)
	{
		cout << "The Heap is empty" << endl;
	}
	else
	{
		FibonacciHeapNode* t = Min;
		FibonacciHeapNode* pt;
		pt = t;
		FibonacciHeapNode* y = nullptr;
		if (t->child != nullptr)
		{
			y = t->child;
			do 
			{
				pt = y->right;
				Min->left->right = y;
				y->right = Min;
				y->left = Min->left;
				Min->left = y;
				if (y->power < Min->power)
				{
					Min = y;
				}
				y->parent = nullptr;
				y = pt;

			} while (pt != t->child);
		}
		t->left->right = t->right;
		t->right->left = t->left;
		Min = t->right;
		if (t == t->right && t->child == nullptr)
		{
			Min = nullptr;
		}
		else
		{
			Min = t->right;
			Consolidate();
		}
		nH--;
	}
}

void FibonacciHeapTree::cut(FibonacciHeapNode* f, FibonacciHeapNode* t)
{
	if (f == f->right)
		t->child = nullptr;

	(f->left)->right = f->right;
	(f->right)->left = f->left;
	if (f == t->child)
		t->child = f->right;

	t->degree = t->degree - 1;
	f->right = f;
	f->left = f;
	(Min->left)->right = f;
	f->right = Min;
	f->left = f->left;
	Min->left = f;
	f->parent = NULL;
	f->mark = 'B';


}

void FibonacciHeapTree::cascaseCut(FibonacciHeapNode* t)
{
	FibonacciHeapNode* pt = t->parent;
	if (pt != nullptr)
	{
		if (t->mark == 'W')
		{
			t->mark = 'B';
		}
		else
		{
			cut(t, pt);
			cascaseCut(pt);
		}
	}
}

void FibonacciHeapTree::decreaseKey(FibonacciHeapNode* f, int val)
{
	if (Min == nullptr)
	{
		cout << "The HeapTree is Empty !!" << endl;
		return;
	}
	if (f == nullptr)
	{
		cout << "Node not found in the HeapTree !!" << endl;
		return;
	}

	f->power = val;
	FibonacciHeapNode* temp = f->parent;
	if (temp != nullptr && f->power < temp->power)
	{
		cut(f, temp);
		cascaseCut(temp);
	}
	if (f->power < Min->power)
	{
		Min = f;
	}

	return;
}

void FibonacciHeapTree::find(FibonacciHeapNode* Min,int last_val, int val)
{
	FibonacciHeapNode* found = nullptr;
	FibonacciHeapNode* t = Min;
	t->C = 'Y';
	FibonacciHeapNode* found_p = nullptr;
	if (t->power == last_val)
	{
		found_p = t;
		t->C = 'N';
		found = found_p;
		decreaseKey(found, val);
	}
	if (found_p == nullptr)
	{
		if (t->child != nullptr)
		{
			find(t->child, last_val, val);
		}
		if (t->right->C != 'Y')
		{
			find(t->right, last_val, val);
		}
	}
	t->C = 'N';
	found = found_p;
}

void FibonacciHeapTree::del(int val)
{
	if (Min == nullptr)
	{
		cout << "The Heap is empty !!";
	}
	else
	{
		find(Min, val, 0);

		extractMin();
		cout << "Soldier Deleted !!";
	}
	return;

}

void FibonacciHeapTree::display()
{
	FibonacciHeapNode* ptr = Min;
	if (Min == nullptr)
	{
		cout << "Thee is Empty !!";
	}
	else
	{
		cout << "The root nodes of HeapTree are : " << endl;
		do 
		{
			cout << ptr->power;
			ptr = ptr->right;
			if (ptr != Min)
			{
				cout << " ==> ";
			}
		} while (ptr != Min && ptr->right != nullptr);
		cout << endl << "The heap has " << nH << " Nodes ." << endl;
	}

}

void FibonacciHeapTree::Consolidate()
{
	int t1;
	float t2 = static_cast<int>(floor(log(static_cast<double>(nH)) / log(static_cast<double>(1 + sqrt(static_cast<double>(5))) / 2)));// (log(nH) / log(2));
	int t3 = t2;
	FibonacciHeapNode** arr = new FibonacciHeapNode * [t3];
	for (int i=0 ; i<t3 ; i++)
	{
		arr[i] = nullptr;
	}
	FibonacciHeapNode* p1 = Min;
	FibonacciHeapNode* p2 = nullptr;
	FibonacciHeapNode* p3 = nullptr;
	FibonacciHeapNode* p4 = p1;
	do 
	{
		p4 = p4->right;
		t1 = p1->degree;
		while (arr[t1] != nullptr)
		{
			p2 = arr[t1];
			if (p1 != nullptr && p2!=nullptr)
			{
				if (p1->power > p2->power)
				{
					p3 = p1;
					p1 = p2;
					p2 = p3;
				}

			}
			if (p2 == Min)
				Min = p1;
			fibonacciLink(p2, p1);
			if (p1->right == p1)
				Min = p1;
			arr[t1] = nullptr;
			t1++;

		}
		arr[t1] = p1;
		p1 = p1->right;

	} while (p1 != Min);

	Min = nullptr;
	for (int j=0 ; j<=t3 ; j++)
	{
		if (arr[j] != nullptr)
		{
			arr[j]->left = arr[j];
			arr[j]->right = arr[j];
			if (Min != nullptr) {
				(Min->left)->right = arr[j];
				arr[j]->right = Min;
				arr[j]->left = Min->left;
				Min->left = arr[j];
				if (arr[j]->power < Min->power)
					Min = arr[j];
			}
			else {
				Min = arr[j];
			}
			if (Min == NULL)
				Min = arr[j];
			else if (arr[j]->power < Min->power)
				Min = arr[j];
		}
	}

}
