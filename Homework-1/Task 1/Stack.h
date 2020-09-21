#pragma once

class IntStack
{
private:
	int *arr;
	int size;
    int capacity;
	void grow(int capacity);
    static const int DEFAULT_SIZE = 16;
    friend IntStack StackSort(const IntStack &);
public:
	
	IntStack(int capacity=DEFAULT_SIZE);
	
	IntStack(IntStack const&);

	~IntStack();

	IntStack& operator=(IntStack const &);

     bool empty() const;

	
	int peek() const;

	void push(int);
	
	int pop();

    void PrintStack() const;
};

IntStack StackSort(const IntStack &);

