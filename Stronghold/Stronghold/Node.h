#ifndef NODE_HJKJHJKJJK
#define NODE_HJKJHJKJJK


template<class T>
class Node
{

private:
	T data;
	Node<T>* next;

	template<class T> friend class StackLinkedList;
	//template<class T> friend class QueueLinkedList;
	template<class T> friend class Queue;



public:

	Node();
	~Node();
};

template<class T>
Node<T>::Node()
{
	 next = nullptr;
}
 template<class T>
 Node<T>::~Node()
 {

 }




#endif