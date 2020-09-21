/*
* Main.cpp
*/

#include "Stack.h"

#include <iostream>
using namespace std;

int main()
{
	IntStack st;


   for(int i = 0; i <  30; i++)	{
		st.push(30-i);
	}

	IntStack st1 = StackSort(st);
	


	while (!st.empty())
	{
		cout << st.pop() << ' ';
	}
	cout << endl;
    
    st1.PrintStack();
    cout<<endl;
    return 0;
}
