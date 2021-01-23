#include <iostream>

#include "QueueLinkedList.h"
#include "StackLinkedList.h"
#include "Vector.h"




int main()
{

	int n = 0;
	cin >> n;
	int** input = new int* [n];
	for (int i=0 ; i<n ; i++)
	{
		*input = new int[n];
		for (int j=0 ; j<n;j++)
		{
			cin >> input[i][j];
		}

	}



	return 0;
}
