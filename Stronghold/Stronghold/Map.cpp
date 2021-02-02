
#include <iostream>
#include "Map.h"
#include "QueueLinkedList.h"

#define min(a,b) a>b?b:a

using namespace std;
size_t Map::number_of_castle = 0;
size_t Map::speed_of_soldier = 0;
int Map::capacity_of_exit = 0;

Map::Map()
{
	Map::number_of_castle = 0;
	Map::speed_of_soldier = 0;
	this->castles = nullptr;
	return;
}





Map::Map(size_t n_castle , size_t sp)
{
	Map::number_of_castle = n_castle;
	Map::speed_of_soldier = sp;

	castles = new Castle[n_castle];

	return;
}

Map::~Map()
{
	castles = nullptr;
	delete[] castles;
}

bool Map::addAdge(int castle_1, int castle_2, int weight)
{
	if (castle_2 >= Map::number_of_castle || castle_1 >= Map::number_of_castle)
	{
		return false;
	}

	castles[castle_1].neighbors[castle_2] = weight;
	castles[castle_2].neighbors[castle_1] = weight;

	return true;
}

bool Map::convertMatrisToEdge(int matrix[], int n)
{
	for (int i=0 ; i<n ; i++)
	{
		for (int j=i ; j<n ;j++)
		{
			if (matrix[i*n + j])
			{
				this->addAdge(i, j, matrix[i * n + j]);
			}
		}
	}

	return true;
}

void Map::deBug()
{
	int n = Map::number_of_castle;
	cout << endl << "matrix whit weight of edge : \n\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << castles[i].neighbors[j] << "\t";
		}
		cout << endl;
	}


}

void Map::BFS()
{
	bool* visited = new bool[Map::number_of_castle];
	for (int i = 0; i < number_of_castle; i++)
		visited[i] = false;


	QueueLinkedList<int> queue;
	queue.Push(0);
	visited[0] = true;
	int current;

	while (!queue.isEmpty())
	{
		current = queue.Pop();
		cout << current << " ";
		//call update function :)
		updateCastle(current);
		for (int i=0 ; i<number_of_castle ; i++)
		{
			if (castles[current].neighbors[i] != 0)
			{
				if (!visited[i])
				{
					visited[i] = true;
					queue.Push(i);
				}
				
			}
		}

	}



}

bool Map::updateCastle(int index)
{
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////attack to other castles start: 
	long int sum_of_neighber_soldier = 0;
	int index_of_castle_have_min_soldier = 0;
	int val = 2147483645;
	for (int i = 0; i < Map::number_of_castle; i++)
	{
		if (castles[index].neighbors[i] != 0)
		{
			sum_of_neighber_soldier += castles[i].num_of_soldier_in_castle;
			if (castles[i].num_of_soldier_in_castle > val)
			{
				val = castles[i].num_of_soldier_in_castle;
				index_of_castle_have_min_soldier = i;//find index of castle that have min soldier
			}
		}

	}

	int *num_of_attacker = new int[number_of_castle];
	int num_of_attacker_uncal = Map::capacity_of_exit;//mande 
	int num_of_soldier_can_exit = min(Map::capacity_of_exit, castles[index].num_of_soldier_in_castle);
	/////find num of attacker not calculate
	for (int i=0 ; i<Map::number_of_castle ;i++)
	{
		if (castles[index].neighbors[i] != 0)
		{
			num_of_attacker[i] = num_of_soldier_can_exit * (castles[i].num_of_soldier_in_castle / sum_of_neighber_soldier);
			num_of_attacker_uncal -= num_of_attacker[i];
		}
	}
	//////////////////
	int j = 0;
	for (int i=0 ; i<Map::number_of_castle ; i++)
	{
		j = 0;
		if (castles[index].neighbors[i] != 0)
		{
			if (j==index_of_castle_have_min_soldier)
			{
				j = num_of_attacker_uncal;
			}
			//num_of_attacker = num_of_soldier_can_exit * (castles[i].num_of_soldier_in_castle / sum_of_neighber_soldier);
			//num_of_attacker_uncal -= num_of_attacker;
			Army new_army(num_of_attacker[i], index, i, castles[index].neighbors[i]);
			for (int i=0 ; i<num_of_attacker[i] + j ; i++)
			{
				//from leaves of AVL tree : 
				if (castles[i].avl.isLeavesIsEmpty())
				{
					castles[i].avl.updateLeavese();
				}
				new_army.addSoldier(castles[i].avl.popLeaf());
				castles[i].num_of_soldier_in_castle--;

			}

			all_army.add_front(new_army);
		}
		
	}
//////////////////////////////////////////////////////////////////////////////////////////// ATACK END //////////////////////////////////////////////////





	return true;
}

void Map::checkArmy()
{
	for (int i=0 ; i < this->all_army.capacity() ; i++)
	{
		if (all_army[i].lowDistance(speed_of_soldier))//if true => army arrived
		{
			while(!all_army[i].isEmpty())
			{

			}
		}
	}


}








