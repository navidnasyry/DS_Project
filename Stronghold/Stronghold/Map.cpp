
#include <iostream>
#include <cmath>
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
	Map::capacity_of_exit = 0;
	this->castles = nullptr;
	return;
}





Map::Map(size_t n_castle , size_t sp , int capacity_of_ex)
{
	Map::number_of_castle = n_castle;
	Map::speed_of_soldier = sp;
	Map::capacity_of_exit = capacity_of_ex;
	castles = new Castle[n_castle];

	return;
}

Map::~Map()
{
	castles = nullptr;
	delete[] castles;
}

bool Map::reviveSoldierFromStack(int index)
{
	static double int_num_of_soldier_can_exit = 0;
	int_num_of_soldier_can_exit += castles[index].stack_const;
	if (castles[index].die_soldier.IsEmpty())
	{
		return false;
	}

	if (fmod(int_num_of_soldier_can_exit,1) == 0)
	{
		for (int i=0 ; i<int_num_of_soldier_can_exit ; i++)
		{
			Soldier s = castles[i].die_soldier.Pop();
			castles[i].avl.insertSoldier(s);
			castles[i].all_in_soldier.push_back(s);
			castles[i].num_of_soldier_in_castle++;
		}
	}
	return true;
}

void Map::enterEnemyFromQueue(int index)
{
	castles[index].capacity_of_enter = ceil(static_cast<double>(castles[index].inder_queue.Size()) / (double)castles[index].num_of_soldier_in_castle);
	//if castle is empty => change owner of key
	//fill FHtree whit all soldier

	//for (int i=0 ; i<castles[index].num_of_soldier_in_castle ; i++)
	//{
		//castles[index].fbTree.addSoldier(castles[index].all_in_soldier[i]);
	//}
	for (int i = 0; i < castles[index].capacity_of_enter; i++)
	{
		Soldier entered_soldier = castles[index].inder_queue.Pop();
		if (entered_soldier.getCastleKey() == castles[index].landlord_key)//if castle has been faild then:
		{
			castles[index].addSoldier(entered_soldier.getPower() , entered_soldier.getCastleKey());
			continue;
		}
		else {
			//castles[index].fbTree.addSoldier(entered_soldier);
			Soldier defender = castles[index].avl.findDefender(entered_soldier.getPower());
			//castles[index].fbTree.addSoldier(defender);
			while(entered_soldier.getPower() > defender.getPower())
			{
				castles[index].die_soldier.Push(castles[index].avl.removeSoldier(defender.getPower()));
				castles[index].num_of_soldier_in_castle--;
				if (castles[index].num_of_soldier_in_castle == 0)
				{
					castles[index].landlord_key = entered_soldier.getCastleKey();
					break;
				}
				defender = castles[index].avl.findDefender(entered_soldier.getPower());

			}
			if (entered_soldier.getPower() <= defender.getPower())
			{
				castles[entered_soldier.getCastleKey()].die_soldier.Push(entered_soldier);
				
			}
			

		}
	}



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
		cout <<"Castle : "<< current << "\n\n ";
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

void Map::writeBFS()
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
		for (int i = 0; i < number_of_castle; i++)
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

void Map::writeInorderAVL()
{
	for (int i=0 ;i< number_of_castle ; i++)
	{
		cout << "AVL of castle " << i << " : \n";
		castles[i].avl.display();
	}
}

void Map::displayMap()
{




}

bool Map::updateCastle(int index)
{
	
	////pop from stack to AVLtree
	reviveSoldierFromStack(index);
	castles[index].avl.display();

	//attack to castle and  fill army
	attackArmy(index);
	castles[index].avl.display();
	//select soldier to defend from our castle && send soldier to fibonacci tree




	//pop from queue to fibonacci tree :(
	enterEnemyFromQueue(index);
	castles[index].avl.display();

	//clash of soldier


	return true;
}

void Map::attackArmy(int index)
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
			if (castles[i].num_of_soldier_in_castle < val)
			{
				val = castles[i].num_of_soldier_in_castle;//sum
				index_of_castle_have_min_soldier = i;//find index of castle that have min soldier
			}
		}

	}

	if (sum_of_neighber_soldier == 0)
		return;
	int* num_of_attacker = new int[number_of_castle];
	int num_of_attacker_uncal = Map::capacity_of_exit;//mande 
	int num_of_soldier_can_exit = min(Map::capacity_of_exit, castles[index].num_of_soldier_in_castle);
	/////find num of attacker not calculate
	for (int i = 0; i < Map::number_of_castle; i++)
	{
		if (castles[index].neighbors[i] != 0)
		{
			num_of_attacker[i] = num_of_soldier_can_exit * castles[i].num_of_soldier_in_castle / sum_of_neighber_soldier;
			num_of_attacker_uncal = num_of_attacker_uncal-num_of_attacker[i];
		}
	}
	//////////////////
	int j = 0;
	for (int i = 0; i < Map::number_of_castle; i++)
	{
		//j = 0;
		if (castles[index].neighbors[i] != 0)
		{
			if (i == index_of_castle_have_min_soldier)
			{
				j = num_of_attacker_uncal;
			}
			//num_of_attacker = num_of_soldier_can_exit * (castles[i].num_of_soldier_in_castle / sum_of_neighber_soldier);
			//num_of_attacker_uncal -= num_of_attacker;
			Army new_army(num_of_attacker[i], index, i, castles[index].neighbors[i]);
			for (int k = 0; k< num_of_attacker[i] + j; k++)
			{
				//from leaves of AVL tree : 
				if (castles[index].avl.isLeavesIsEmpty())
				{
					castles[index].avl.updateLeavese();
				}
				Soldier s = castles[index].avl.popLeaf();
				new_army.addSoldier(s);
				castles[index].all_in_soldier.erase(castles[index].all_in_soldier.find(s));
				castles[index].num_of_soldier_in_castle--;

			}

			all_army.push_back(new_army);
		}

	}
	//////////////////////////////////////////////////////////////////////////////////////////// ATACK END //////////////////////////////////////////////////

}

void Map::mainFunction()
{
	checkArmy();//army attack to target castle
	cout << "Army status : \n";
	for (int i=0 ; i<all_army.size() ;  i++)
	{
		cout << "\n\nArmy from castle : " << all_army[i].getFromWhich() <<
			"\nAtack To : " << all_army[i].getAttackTo() << "\nNumber of soldier in this army : " << 
			all_army[i].army_soldier.Size() << "\nDistanse from target : " << all_army[i].getDistanse() << endl;
	}


	BFS();


}

void Map::checkArmy()
{
	for (int i=0 ; i < this->all_army.size() ; i++)
	{
		if (all_army[i].lowDistance(speed_of_soldier))//if true => army arrived
		{
			while(!all_army[i].isEmpty())
			{
				castles[all_army[i].getAttackTo()].addSoldierToQueue(all_army[i].popSoldier());//add attacker soldier to target castle queue
			}
		}
	}

	return;
}

void Map::inputSoldier(int index, Soldier s , float st)
{
	
	castles[index].addSoldier(s.getPower() , s.getCastleKey());
	castles[index].stack_const = st;
	return;

}







