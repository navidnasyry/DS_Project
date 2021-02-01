#include "Army.h"
#include "Map.h"


Army::Army()
{
	distance = -1;
	speed = Map::speed_of_soldier;
	num_of_soldier = 0;

}


Army::~Army()
{
}
