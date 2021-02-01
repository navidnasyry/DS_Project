#ifndef SOLDIER_SDFGHJ
#define SOLDIER_SDFGHJ


class Soldier
{
	friend class AVLTree;
	friend class AVLNode;
	friend class Castle;
	friend class FibonacciHeapNode;
	friend class FibonacciHeapTree;

	
	size_t speed;
	size_t castle_key;
	int power;

public:
	Soldier();
	Soldier(int p);
	~Soldier();
	Soldier(const Soldier&);
	Soldier(Soldier&&);

	Soldier& operator=(const Soldier& r_val);
};






#endif