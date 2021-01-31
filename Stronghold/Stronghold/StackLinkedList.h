#ifndef STACK_ASDJJJJJJJ
#define STACK_ASDJJJJJJJ

#include "Node.h"
using namespace std;


template<class T>
class StackLinkedList
{
private:


	Node<T>* top;//first node 

	template<class T> friend class Node;

public:

	StackLinkedList();
	~StackLinkedList();

	void Push(const T& new_data);//add new data to first of linked list

	T& Pop();
	T& Top();
	int Find(const T& target);
	int size();
	bool IsEmpty();

	//void print();
};

template<class T>
bool StackLinkedList<T>::IsEmpty()
{
	if (top)
	{
		return false;
	}
	return true;
}

template<class T>
T& StackLinkedList<T>::Top()
{
	return this->top->data;
}

template<class T>
int StackLinkedList<T>::size()
{
	Node<T> *temp = top;
	int size_ = 0;
	while (temp)
	{
		size_++;
		temp = temp->next;
	}
	return size_;
}

template<class T>
int StackLinkedList<T>::Find(const T& target)
{
	Node<T>* temp = top;
	int index = 0;
	while (temp)
	{
		T t_data= temp->data;
		if (t_data == target)
		{
			return index;
		}
		temp = temp->next;
		index++;
	}
	return -1;
}

/*template<class T>
void StackLinkedList<T>::print()
{
	Node<T> *temp = this->top;
	while (temp)
	{
		cout << temp->data << "\t\t";
		temp = temp->next;

	}
	cout << endl;
	
}*/

template<class T>
StackLinkedList<T>::StackLinkedList()
{
	this->top = nullptr;
	return;

}

template<class T>
StackLinkedList<T>::~StackLinkedList()
{
	Node<T>* temp = top;
	while (temp)
	{
		Node<T>* temp2 = temp->next;
		temp = nullptr;
		delete temp;
		temp = temp2;

	}
	top = nullptr;

	return;
}
template<class T>
T& StackLinkedList<T>::Pop()
{
	if (!top)
	{
		throw "Stack is";
	}

	Node<T> *del_node = top;
	top = top->next;
	T delete_data = del_node->data;
	del_node = nullptr;
	delete del_node;
	return delete_data;

}

template<class T>
 void StackLinkedList<T>::Push(const T& new_data)
{
	 if (!top)
	 {
		 top = new Node<T>();
		 top->data = new_data;
		 top->next = nullptr;
		 return;
	 }


	 Node<T>* new_node = new Node<T>();
	 new_node->next = top;
	 new_node->data = new_data;
	 top = new_node;
	 return;

}




#endif