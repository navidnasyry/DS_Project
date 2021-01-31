#ifndef NODE_HJKJHJKJJK
#define NODE_HJKJHJKJJK


template<class T>
class Node
{

private:

	template<class T> friend class StackLinkedList;
	//template<class T> friend class QueueLinkedList;
	template<class T> friend class QueueLinkedList;


	T data;
	Node<T>* next;

	



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
	 next = nullptr;
	 delete next;
 }




#endif