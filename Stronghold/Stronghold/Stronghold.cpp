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
	int n = 0;
	cin >> n;
	int* input = new int [n*n];
	for (int i=0 ; i<n ; i++)
	{
		for (int j=0 ; j<n;j++)
		{
			cin >> input[i*n + j];
		}

	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << input[i * n + j]<<" ";
		}
		cout << endl;
	}
	int sp;
	cin >> sp;
	Map head(n , sp);
	head.deBug();
	head.convertMatrisToEdge(input , n);
	head.deBug();

	*/
	
	int time = 0;
	FibonacciHeapTree fht;
	while (++time)
	{
		Soldier a1(time+10);

		fht.addSoldier(a1);
		fht.display();

		if (time == 10)
		{
			break;
		}
	}

	fht.extractMin();
	fht.display();


	return 0;
}
