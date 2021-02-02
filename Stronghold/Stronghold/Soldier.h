#ifndef SOLDIER_SDFGHJ
#define SOLDIER_SDFGHJ


class Soldier
{
	friend class AVLTree;
	friend class AVLNode;
	friend class Castle;
	friend class FibonacciHeapNode;
	friend class FibonacciHeapTree;
	friend bool operator==( Soldier& r_val,  Soldier& l_val);

	
	size_t speed;
	size_t castle_key;
	int power;

public:
	Soldier();
	Soldier(int p , size_t owner_k);
	~Soldier();
	Soldier(const Soldier&);
	Soldier(Soldier&&);
	size_t getPower();
	size_t getCastleKey();
	Soldier& operator=(const Soldier& r_val);
};

bool operator==( Soldier& r_val,  Soldier& l_val);





#endif