#ifndef QUEUE_ASDFADFAS
#define QUEUE_ASDFADFAS
#include "Node.h"

using namespace std;

template<class T>
class QueueLinkedList
{

	template<class T> friend class Node;

	Node<T> *rear;
	int size;

public:
	// First => second => third => ... => Rear =>First =>second =>...

	QueueLinkedList();
	~QueueLinkedList();
	void Push(const T& new_data);
	T& Pop();
	bool isEmpty();
	T& getRear();
	T& getFirst();
	int Size();
	int Find(const T& target);
	//void print();
};

template<class T>
bool QueueLinkedList<T>::isEmpty()
{
	if (this->rear)
	{
		return false;
	}
	return true;
}

template<class T>

QueueLinkedList<T>::QueueLinkedList()
{
	this->rear = nullptr;
	size = 0;
	return;
}

template<class T>
QueueLinkedList<T>::~QueueLinkedList()
{
	Node<T> *temp = rear;
	while (temp)
	{
		Node<T>* next_del = temp->next;
		temp = nullptr;
		delete temp;
		temp = next_del;
	}
	rear = nullptr;
	return;
}



template<class T>
void QueueLinkedList<T>::Push(const T& new_data)
{
	if (rear == nullptr)
	{
		rear = new Node<T>();
		rear->data = new_data;
		rear->next = rear;
		size++;
		return;
	}

	Node<T>* new_node = new Node<T>();
	Node<T>* first = rear->next;

	new_node->data = new_data;
	new_node->next = first;
	rear->next = new_node;
	rear = new_node;

	size++;
	return;


}

template<class T>
T& QueueLinkedList<T>::Pop()
{
	// First => second => third => ... => Rear =>First(del) =>second =>...
	if (!rear)
	{
		throw "Queue is empty";
	}
	if (rear->next ==rear)
	{
		T del_data = rear->data;
		rear = nullptr;
		delete rear;
		size--;
		return del_data;
	}


	Node<T>* first_del = rear->next;
	Node<T>* second = first_del->next;
	T del_data = first_del->data;
	rear->next = second;

	first_del = nullptr;
	delete first_del;
	size--;
	return del_data;

}


template<class T>
T& QueueLinkedList<T>::getFirst()
{
	return this->rear->next->data;
}

template<class T>
T& QueueLinkedList<T>::getRear()
{
	return this->rear->data;
}



template<class T>
int QueueLinkedList<T>::Size()
{
	return size;
}
template<class T>
int QueueLinkedList<T>::Find(const T& target)
{
	if (rear->data == target)
	{
		return size - 1;
	}

	Node<T>* temp = this->rear->next;
	for (int i=0 ; i<size-1 ; i++)
	{
		if (temp->data == target)
		{
			return i;
		}
		temp = temp->next;
	}
	return -1;
}





/*template<class T>
void QueueLinkedList<T>::print()
{

	if (size <1)
	{
		throw "Queue is empty";
	}
	Node<T>* temp = this->rear->next;
	for (int i=0 ; i<size ; i++)
	{
		cout << temp->data << "\t\t";
		temp = temp->next;
	}
	cout << endl;
	return;
}*/







#endif