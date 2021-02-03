#include <iostream>
using namespace std;

#include "Map.h"
#include "QueueLinkedList.h"
#include "StackLinkedList.h"
#include "Vector.h"
#include "Soldier.h"
#include "Soldier.h"
#include "FibonacciHeapTree.h"




int main()
{
	/*
	input : 
	5
0 0 0 30 20
0 0 60 50 100
0 60 0 0 40
30 50 0 0 0
20 100 40 0 0
		*/
	int n = 0;

	cout << "Enter number of Castles : ";
	cin >> n;
	cout << "Enter matrix : \n";
	int* input = new int[n * n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> input[i * n + j];
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << input[i * n + j] << " ";
		}
		cout << endl;
	}
	int sp;
	int cap_of_exit;
	cout << "Enter Speed of soldier : ";
	cin >> sp;
	cout << "Enter capacity of exit : ";
	cin >> cap_of_exit;

	Map head(n, sp , cap_of_exit);
	head.deBug();
	head.convertMatrisToEdge(input, n);
	head.deBug();
	cout << "\n\n BFS : \n\n";
	head.writeBFS();
	cout << endl;
	
	for (int i=0 ; i<n ; i++)
	{
		float stack_ = 0.5;
		cout << "Enter capacity of Stack : \n";
		cin >> stack_;
		cout << "Enter number of soldier for castle " << i <<" :"<< endl;
		int num_of_s;
		cin >> num_of_s;
		cout << "Enter power of soldiers : \n";

		for (int j=0 ; j<num_of_s ; j++)
		{
			int power;
			cin >> power;
			power = i +j+ 10;
			Soldier new_s(power, i);
			head.inputSoldier(i, new_s , stack_);
		}

	}

	head.writeInorderAVL();

	int time = 0;
	while (++time)
	{
		head.mainFunction();

		
	}

//	fht.del(13);// :(
//	fht.display();


	return 0;
}
