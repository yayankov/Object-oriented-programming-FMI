#include<iostream>
#include<cstdlib>
#include<ctime>
#include"MagicBox.h"
using namespace std;

int main()
{
	MagicBox<int> one;
	one.insert(6);
	one.insert(2);
	one.insert(1);
	one.insert(4);
	one.insert(9);
	one.list();
	one.pop();
	one.list();
	system("pause");
	return 0;
}