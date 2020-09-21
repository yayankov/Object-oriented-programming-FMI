#include "GameCharacter.h"
#include<cstring>
#include<iostream>
using namespace std;



GameCharacter::GameCharacter(): HP(0), MP(0),AP(0),DP(0)
{
	setNameHero(" ");
}

GameCharacter::GameCharacter(const char * _name, int HP, int MP, int AP, int DP) : HP(HP),MP(MP),AP(AP),DP(DP)
{
	setNameHero(_name);
}

GameCharacter::GameCharacter(const GameCharacter & cpy):HP(cpy.HP),MP(cpy.MP),AP(cpy.AP),DP(cpy.DP)
{
	setNameHero(cpy.nameHero);
}

GameCharacter::~GameCharacter()
{
	delete[] nameHero;
}

const char * GameCharacter::getNameHero() const
{
	return nameHero;
}

int GameCharacter::getHP() const
{
	return HP;
}

int GameCharacter::getMP() const
{
	return MP;
}

int GameCharacter::getAP() const
{
	return AP;
}

int GameCharacter::getDP() const
{
	return DP;
}

void GameCharacter::setNameHero(const char * _name)
{
	delete[] nameHero;
	int nameLen = strlen(_name) + 1;
	nameHero = new char[nameLen];
	strcpy_s(nameHero,nameLen, _name);

}

void GameCharacter::setHP(int HP)
{
	this->HP = HP;
}

void GameCharacter::setMP(int MP)
{
	this->MP = MP;
}

void GameCharacter::setAP(int AP)
{
	this->AP = AP;
}

void GameCharacter::setDP(int DP)
{
	this->DP = DP;
}

void GameCharacter::getattacked(GameCharacter& b)
{
	if (b.AP > DP)
	{
		HP = HP-(b.AP - DP);
		if (HP < 0)
		{ 
			HP = 0;
		}
	}
}

void GameCharacter::print() const
{
	cout << "HP: " << HP << endl;
	cout << "MP: " << MP << endl;
	cout << "AP: " << AP << endl;
	cout << "DP: " << DP << endl;
}

Warrior::Warrior() : GameCharacter()
{
	setNameHero("Warrior");
	setHP(20);
	setMP(5);
	setAP(4);
	setDP(1);
}

void Warrior::print() const
{
	GameCharacter::print();
}

Guardian::Guardian()
{
	setNameHero("Guardian");
	setHP(40);
	setMP(25);
	setAP(1);
	setDP(3);
}

void Guardian::print() const
{
	GameCharacter::print();
}

Wizzard::Wizzard()
{
	setNameHero("Wizzard");
	setHP(30);
	setMP(30);
	setAP(2);
	setDP(2);
}

void Wizzard::print() const
{
	GameCharacter::print();
}
