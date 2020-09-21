
#include "Stack.h"
#include <iostream>
using namespace std;

void ArraySort(int *array,int length)
{
    for(int i = 0; i<length-1; i++)
        for(int j = i+1; j<length; j++)
            if(array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
}
IntStack StackSort(const IntStack &s)
{
    IntStack result(s);
    ArraySort(result.arr, result.size);
    
    return result;
}


IntStack::IntStack(int capacity)
{
    size=0;
    arr=nullptr;
    grow(capacity);
    }

IntStack::IntStack(IntStack const& s):IntStack(s.size)
{
    this->size=s.size;
    for(int i=0;i<this->size;i++)
        this->arr[i]=s.arr[i];
}

IntStack& IntStack::operator=(IntStack const& s) {
	if (this != &s) {
		this->size = s.size;
        grow(s.size);
        for(int i=0;i<this->size;i++)
            this->arr[i]=s.arr[i];
	}
	return *this;
}

void IntStack::grow(int capacity)
{
    int *arr2= new int[capacity];
    if(arr!=nullptr)
    {
        for(int i=0;i<size;i++)
            arr2[i]=arr[i];
        delete[] arr;
    }
    arr=arr2;
    this->capacity=capacity;
}

IntStack::~IntStack()
{
	delete[] arr;
}

bool IntStack::empty() const
{
    return size==0;
}

int IntStack::peek() const
{
	if (empty()) {
		cout << "Error\n";
		return 0;
	}

	return arr[size-1];
}

void IntStack::push(int x) {
	if (size==capacity) {
		grow(2*capacity);
	}
	arr[size++] = x;
}

int IntStack::pop() {
	if (empty()) {
		cout << "Error!\n";
		return 0;
	}
	return arr[--size];
}

void IntStack::PrintStack() const
{
    for(int i=size-1;i>=0;i--)
        cout<<arr[i]<<" ";
}
