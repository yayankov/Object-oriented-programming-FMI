#include<iostream>
#include"Matrix.h"
using namespace std;
int main()
{
	Matrix<int> test1(2, 2);
	test1.setAt(1, 1, 5);
	test1.setAt(1, 2, 3);
	test1.setAt(2, 1, 4);
	test1.setAt(2, 2, 1);
	test1.print();
	cout << "--------------" << endl;
	//test1.transpose();
	test1.print();
	cout << "--------------" << endl;
	cout <<" "<< test1.getAt(1, 2)<<endl;
	cout << "--------------" << endl;
	system("pause");
	return 0;
}
