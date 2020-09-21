#pragma once
class GameCharacter
{
protected:
	char* nameHero=nullptr;
	int HP;
	int MP;
	int AP;
	int DP;

public:
	GameCharacter();
	GameCharacter(const char* Name, int HP, int MP, int AP, int DP);
	GameCharacter(const GameCharacter&);
	~GameCharacter();

	const char* getNameHero() const;
	int getHP() const;
	int getMP() const;
	int getAP() const;
	int getDP() const;

	void setNameHero(const char* name);
	void setHP(int HP);
	void setMP(int MP);
	void setAP(int AP);
	void setDP(int DP);

	void getattacked(GameCharacter& );
	void print() const;
};

class Warrior : public GameCharacter
{
public:
	Warrior();
	void print() const;
};
class Guardian : public GameCharacter
{
public:
	Guardian();
	void print() const;
};
class Wizzard : public GameCharacter
{
public:
	Wizzard();
	void print() const;
};

