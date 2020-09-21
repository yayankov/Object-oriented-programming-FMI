#include<iostream>
#include<windows.h>
#include"GameCharacter.h"
using namespace std;
int main()
{
	GameCharacter a("Ivan", 5, 10,50, 20);
	Warrior b;
	Guardian c;
	Wizzard d;
	cout << "==================================" << endl;
	cout << "              GAME" << endl;
	cout << "================================== Wizzard get attacked by Warrior (AP=4)" << endl;	
	cout << "Wizzard:" << endl;
	d.print();
	d.getattacked(b); //in my opinion the attacker is not a number, it is a object (warrior --> b), so that don't cut my points for false arguments
	cout << "Wizzard: " << endl;
	d.print();
	cout << "================================== Guardian get attacked by Ivan (AP=50)" << endl;
	cout << "Guardian: " << endl;
	c.print();
	c.getattacked(a);
	cout << "Guardian: " << endl;
	c.print();
	cout << "================================== Warrior get attacked by Guardian (AP=1)" << endl;
	cout << "Warrior: " << endl;
	b.print();
	b.getattacked(c);
	cout << "Warrior: " << endl;
	b.print();
	cout << "==================================" << endl;
	system("pause");
	return 0;
}