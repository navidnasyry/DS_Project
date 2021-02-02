#ifndef _VECTOR12324
#define _VECTOR12324

#include <iostream>

using namespace std;
template<class T>
class Vector
{
private:
	long long int allocator_type;//total size of vector
	long long int size_type;//fill size of vector
	T* data;
	

public:
	Vector<T>();
	
	Vector<T>(long long int size, T* input);
	
	Vector<T>(long long int size);
	
	Vector<T>(long long int size, T val);
	
	~Vector<T>();
	
	Vector<T>(const Vector<T>& vec);
	
	T& operator[](int index);
	
	Vector<T> operator=(Vector<T> r_d);
	

	void push_back(const T& new_data);
	
	void add_front(const T& new_data);
	
	

	long long int insert(long long int index, const T& val);
	

	long long int find(const T& target);//return index
	
	long long int erase(size_t index);
	
	void pop_back();
	T& Top();
	void pop_front();
	

	long long int size();
	
	long long int capacity();
	
	bool isEmpty();

	//void print();
	
};

template<class T>
bool Vector<T>::isEmpty()
{
	if (data)
	{
		return false;
	}
	return true;
}

template<class T>
T& Vector<T>::Top()
{
	return this->data[0];
}

template<class T>
 Vector<T> :: Vector<T>()
{
	data = nullptr;
	allocator_type = 0;//total size of vector
	size_type = 0;//fill size of vector
}


template<class T>
 Vector<T>::Vector<T>(long long int size, T* input)
{
	this->allocator_type = size;
	//cout << _msize(input);
	this->size_type = _msize(input) / sizeof(T);
	this->data = new T[size];
	for (int i = 0; i < size_type; i++)
	{
		try {
			this->data[i] = input[i];
		}
		catch (...) {
			break;
		}

	}

}


 template<class T>
 Vector<T>::Vector<T>(long long int size)
{

	this->allocator_type = size;
	this->data = new T[size];

}


 template<class T>
 Vector<T>::Vector<T>(long long int size, T val)
{
	for (int i = 0; i < size; i++)
	{
		this->push_back(val);
	}
	return;
}


 template<class T>
 Vector<T> ::~Vector<T>()
{
	this->data = nullptr;
	delete data;
	delete[] data;

}


 template<class T>
 Vector<T>::Vector<T>(const Vector<T>& vec)
{
	this->data = new T[vec.allocator_type];
	this->allocator_type = vec.allocator_type;
	this->size_type = vec.size_type;

	for (int i = 0; i < vec.size_type; i++)
	{
		this->data[i] = vec.data[i];
	}


	return;

}


/*Vector<T>(Vector<T>&& vec)
{
	this->data = new T[vec.allocator_type];
	this->allocator_type = vec.allocator_type;
	this->size_type = vec.size_type;

	for (int i = 0; i < vec.size_type; i++)
	{
		this->data[i] = vec.data[i];
	}
	vec.~Vector();

	return;
}
*/
template<class T>
 T& Vector<T>:: operator[](int index)
{
	if (index >= size_type)
	{
		throw "Index out of size";
	}
	T my_T = this->data[index];
	return my_T;
}


template<class T>
 Vector<T> Vector<T>:: operator=(Vector<T> r_d)
{
	this->~Vector();
	this->data = new T[r_d.allocator_type];
	this->allocator_type = r_d.allocator_type;
	this->size_type = r_d.size_type;

	for (int i = 0; i < r_d.size_type; i++)
	{
		this->data[i] = r_d.data[i];
	}


	return *this;
}



template<class T>
void Vector<T> :: push_back(const T& new_data)
{
	if (allocator_type == 0)
	{
		allocator_type = 2;
		size_type = 1;
		this->data = new T[2];
		this->data[0] = new_data;
		return;
	}
	if (size_type >= allocator_type)
	{


		long long int new_allocate = allocator_type + (allocator_type / 2);
		Vector<T> new_vec(new_allocate);
		new_vec.size_type = this->size_type + 1;
		int i = 0;
		for (i = 0; i < size_type; i++)
		{
			new_vec.data[i] = this->data[i];
		}
		new_vec.data[i] = new_data;
		*this = new_vec;


	}
	else
	{
		this->data[size_type] = new_data;
		this->size_type++;

	}

}


template<class T>
void Vector<T> :: add_front(const T& new_data)
{
	if (allocator_type == 0)
	{
		allocator_type = 2;
		size_type = 1;
		this->data = new T[2];
		this->data[0] = new_data;

		return;
	}

	if (size_type >= allocator_type)
	{
		long long int new_allocate = allocator_type + (allocator_type / 2);
		Vector<T> new_vec(new_allocate);
		new_vec.size_type = this->size_type + 1;
		new_vec.data[0] = new_data;
		for (int i = 0; i < size_type; i++)
		{
			new_vec.data[i + 1] = this->data[i];
		}
		*this = new_vec;


	}
	else
	{
		//this->data[size_type] = this->data[size_type - 1];
		for (int i = size_type; i > 0; i--)
		{
			//T temp = this->data[i-1];
			this->data[i] = this->data[i - 1];
		}
		this->data[0] = new_data;
		this->size_type++;
	}
}


template<class T>
long long int Vector<T> :: insert(long long int index, const T& val)
{
	if (index == 0)
	{
		this->add_front(val);
		return index;
	}
	else if (index == size_type)
	{
		this->push_back(val);
		return index;
	}
	if (index < size_type)
	{

		if (size_type >= allocator_type)
		{
			long long int new_allocate = allocator_type + (allocator_type / 2);
			Vector<T> new_vec(new_allocate);
			new_vec.size_type = this->size_type + 1;
			int i = size_type;
			for (i = size_type; i >= 0; i--)
			{
				if (i == index)
				{
					new_vec.data[i] = val;
					continue;
				}
				if (i < index)
				{
					new_vec.data[i] = this->data[i];
					continue;

				}
				new_vec.data[i] = this->data[i - 1];
			}

			*this = new_vec;

		}
		else
		{
			for (int i = size_type; i > index; i--)
			{
				this->data[i] = this->data[i - 1];
			}
			this->data[index] = val;
			this->size_type++;
		}
		return index;

	}

	return -1;
}


template<class T>
long long int Vector<T> :: find(const T& target)//return index
{
	for (size_t i = 0; i < size_type; i++)
	{
		if (this->data[i] == target)
		{
			return i;
		}
	}
	return -1;
}


template<class T>
long long int Vector<T> ::erase(size_t index)
{
	if (size_type == 0)
	{
		return -1;
	}
	if (index == size_type - 1)
	{
		this->pop_back();
		return index;
	}
	else if (index == 0)
	{
		this->pop_front();
		return 0;
	}
	if (index < size_type)
	{
		size_type--;//  :)  :)
		if (size_type <= allocator_type / 2)
		{
			Vector<T> new_vec(size_type);
			size_t i = 0;
			for (i = 0; i < index; i++)
			{
				new_vec.data[i] = this->data[i];
			}
			for (size_t j = index + 1; j < size_type + 1; j++)
			{
				new_vec.data[i] = this->data[j];
				i++;
			}
			new_vec.size_type = size_type;
			*this = new_vec;
			return index;

		}
		for (size_t i = index; i < size_type; i++)
		{
			this->data[i] = this->data[i + 1];
		}
		return index;
	}
	return -1;
}



template<class T>
void Vector<T> :: pop_back()
{
	if (size_type == 0)
	{
		return;
	}
	size_type--;//  :)  :)
	if (size_type <= allocator_type / 2)
	{
		Vector<T> new_vec(size_type);
		for (size_t i = 0; i < size_type; i++)
		{
			new_vec.data[i] = this->data[i];
		}
		new_vec.size_type = size_type;
		*this = new_vec;
	}
	return;

}


template<class T>
void Vector<T> :: pop_front()
{

	if (size_type == 0)
	{
		return;
	}
	size_type--;//  :)  :)
	if (size_type <= allocator_type / 2)
	{
		Vector<T> new_vec(size_type);
		for (size_t i = 1; i < size_type + 1; i++)
		{
			new_vec.data[i - 1] = this->data[i];
		}
		new_vec.size_type = size_type;
		*this = new_vec;
	}
	else
	{
		for (size_t i = 1; i < size_type + 1; i++)
		{
			this->data[i - 1] = this->data[i];
		}
	}
	return;
}


template<class T>
long long int Vector<T> :: size()
{
	return this->allocator_type;
}


template<class T>
long long int Vector<T> :: capacity()
{
	return this->size_type;
}

/*
template<class T>
void Vector<T> :: print()
{
	cout << endl;
	for (int i = 0; i < this->size_type; i++)
	{
		cout << this->data[i] << "\t";
	}
	cout << endl;
	return;
}*/



#endif