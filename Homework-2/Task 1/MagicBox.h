#pragma once
#include<iostream>
using namespace std;

template<class T>
class MagicBox
{
	T* array;
	int size;
	int capacity;
	void expand();
	void pop(int index);
public:
	MagicBox();
	MagicBox(const MagicBox<T>&);
	MagicBox<T>& operator=(const MagicBox<T>&);
	~MagicBox();

	void insert(const T&);
	void pop();
	void list() const;
};

template<class T>
void MagicBox<T>::expand()
{
	capacity *= 2;
	T* tmp = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = array[i];
	}
	delete[] array;
	array = tmp;
}
template<class T>
void MagicBox<T>::pop(int index)
{
	for (int i = index; i < size - 1; i++)
	{
		array[i] = array[i + 1];
	}
	size--;
}
template<class T>
MagicBox<T>::MagicBox() : capacity(10), size(0)
{
	array = new T[capacity];
}

template<class T>
MagicBox<T>::MagicBox(const MagicBox<T>& cpy) : capacity(cpy.capacity), size(cpy.size)
{
	array = new T[capacity];
	for (int i = 0; i < size; i++)
	{
		array[i] = cpy.array[i];
	}
}
template<class T>
MagicBox<T> & MagicBox<T>::operator=(const MagicBox<T>& cpy)
{
	if (this != &cpy)
	{
		delete[] array;
		size = cpy.size;
		capacity = cpy.capacity;
		array = new T[cpy.capacity];
		for (int i = 0; i < size; i++)
		{
			array[i] = cpy.array[i];
		}
	}
	return *this;
}
template<class T>
MagicBox<T>::~MagicBox()
{
	delete[] array;
}


template<class T>
void MagicBox<T>::insert(const T&  a)
{
	if (size == capacity)
	{
		expand();
	}
	array[size] = a;
	size++;
}


template<class T>
void MagicBox<T>::pop()
{
	pop(rand() % size);

}

template<class T>
void MagicBox<T>::list() const
{
	for (int i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
}


