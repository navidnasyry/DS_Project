#ifndef SOLDIER_SDFGHJ
#define SOLDIER_SDFGHJ


class Soldier
{
	friend class AVLTree;
	friend class AVLNode;
	friend class Castle;

	
	static size_t speed;
	size_t castle_key;
	int power;

public:
	Soldier();
	~Soldier();

	Soldier& operator=(const Soldier& r_val);
};






#endif