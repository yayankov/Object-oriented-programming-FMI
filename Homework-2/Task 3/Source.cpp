#include<iostream>
#include"Guest.h"
using namespace std;
int main()
{
	User one("Yani","qwerty","One","asdasfas123");
	User two("Pavli", "123456", "Two", "knka213n");
	PowerUser three(53,"Toshko", "12345678", "Three", "145dfa");
	VIP four("Toshko","sdsd","Four","aijas868a");
	Admin five;
	cout << "----------------------------- " << endl;
	cout << "	 LOGIN SYSTEM"<<endl;
	cout << "----------------------------- Change password" << endl;
	one.print(); cout << endl;
	one.changePassword("qwerty", "1234");
	one.print();
	cout << "----------------------------- Change title" << endl;
	four.print(); cout << endl;
	four.setTitle("Praskova");
	four.print();
	cout << "----------------------------- Change username" << endl;
	two.print(); cout << endl;
	five.setNameOtherUser(two, "Krasavica");
	two.print();
	cout << "-----------------------------" << endl;

	system("pause");
	return 0;
}