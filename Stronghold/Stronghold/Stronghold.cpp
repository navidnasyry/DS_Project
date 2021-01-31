#include <iostream>
using namespace std;

#include "Map.h"
#include "QueueLinkedList.h"
#include "StackLinkedList.h"
#include "Vector.h"




int main()
{

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
	Map head(n);
	head.deBug();
	head.convertMatrisToEdge(input , n);
	head.deBug();

	int time = 0;
	while (++time)
	{

	}


	return 0;
}
