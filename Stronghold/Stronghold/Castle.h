#ifndef CASTLE_HJKJHJHJ
#define CASTLE_HJKJHJHJ
#include "Map.h"

class Castle
{
	friend class Map;

	size_t key;
	int* neighbors;
	 

public:
	Castle();
	~Castle();
};




#endif
