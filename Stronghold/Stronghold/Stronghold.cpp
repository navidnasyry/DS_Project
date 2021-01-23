#include <iostream>
#include "Vector.h"

using namespace std;


int main()
{



	//cout << sizeof(a);

	int* t = new int[10];
	for (int i = 0; i < 3; i++)
		t[i] = i + 1;
	//cout << sizeof(t) << endl << sizeof(*t);
	cout << _msize(t) << endl;




	int* a = new int[5];//must size = vector size
	for (int i = 0; i < 5; i++)
		a[i] = i + 1;

	Vector<int> v1(10, a);
	Vector<int> v2(10);
	v1.print();
	cout << endl << v1[1] << endl;
	v2 = v1;
	v2.print();
	Vector<int> v4(5, 100);
	v4.print();
	cout << "v4 : " << v4.size() << "  " << v4.capacity() << endl;


	v1.add_front(20);
	v1.push_back(20);

	v1.print();
	v1.erase(2);
	v1.print();

	v1.erase(2);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.erase(0);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;


	v1.erase(1);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.erase(0);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.erase(0);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.erase(0);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.erase(0);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.insert(0, 10);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.insert(1, 20);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.insert(1, 25);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.insert(2, 40);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.insert(2, 50);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.insert(3, 30);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;




	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	cout << "v2 : " << v2.size() << "  " << v2.capacity() << endl;
	v1.print();
	v1.pop_front();
	//v1.pop_back();
	v1.print();
	v1.pop_front();
	//v1.pop_back();
	v1.print();
	v1.pop_front();
	//v1.pop_back();
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;
	v1.pop_front();
	//v1.pop_back();
	v1.print();
	v1.pop_front();
	//v1.pop_back();
	v1.print();
	v1.pop_front();
	//v1.pop_back();
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;
	//v1.pop_back();
	//v1.pop_back();
	v1.pop_front();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.pop_front();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	cout << endl << "index : " << v1.find(50) << endl;

	v1.add_front(20);
	v1.push_back(20);
	v1.print();
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;
	v1.push_back(30);
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;

	v1.push_back(30);
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;
	v1.push_back(30);
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;
	v1.push_back(30);
	cout << "v1 : " << v1.size() << "  " << v1.capacity() << endl;




	return 0;
}
