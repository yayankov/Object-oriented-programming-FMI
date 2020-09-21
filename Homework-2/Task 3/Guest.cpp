#include "Guest.h"
#include<cstring>
#include<iostream>
using namespace std;


Guest::Guest(const char * IP)
{
	delete[] ipAdress;
	int len = strlen(IP) + 1;
	ipAdress = new char[len];
	strcpy_s(ipAdress,len,IP );
}

Guest::Guest(const Guest & cpy) 
{
	delete[] ipAdress;
	int len = strlen(cpy.ipAdress) + 1;
	ipAdress = new char[len];
	strcpy_s(ipAdress, len, cpy.ipAdress);
}

Guest & Guest::operator=(const Guest & cpy)
{
	if (this != &cpy)
	{
		delete[] ipAdress;
		int len=strlen(cpy.ipAdress) + 1;
		ipAdress = new char[len];
		strcpy_s(ipAdress,len, cpy.ipAdress);
	}
	return *this;
}

Guest::~Guest()
{
	delete[] ipAdress;
}

User::User(const char * user, const char * pass, const char * _title, const char * ipAdress) : Guest(ipAdress)
{
	setPassword(pass);

	delete[] username;
	int len = strlen(user) + 1;
	username = new char[len];
	strcpy_s(username,len,user);
	
	delete[] title;
	int length = strlen(_title) + 1;
	title = new char[length];
	strcpy_s(title,length, _title);
}

User::User(const User & cpy) : Guest(cpy)
{
	setPassword(cpy.password);

	delete[] username;
	int len = strlen(cpy.username) + 1;
	username = new char[len];
	strcpy_s(username,len, cpy.username);

	delete[] title;
	int length = strlen(cpy.title) + 1;
	title = new char[len];
	strcpy_s(title,length, cpy.title);
}

User & User::operator=(const User &cpy)
{
	if (this != &cpy)
	{
		Guest::operator=(cpy);
		setPassword(cpy.password);

		delete[] username;
		int len = strlen(cpy.username) + 1;
		username = new char[len];
		strcpy_s(username,len, cpy.username);

		delete[] title;
		int length = strlen(cpy.title) + 1;
		title = new char[length];
		strcpy_s(title,length, cpy.title);
	}
	return *this;
}

User::~User()
{
	delete[] username;
	delete[] password;
	delete[] title;
}

const char * User::getUsername() const
{
	return username;
}

void User::setPassword(const char * pass)
{
	delete[] password;
	int len = strlen(pass) + 1;
	password = new char[len];
	strcpy_s(password,len, pass);
	for (int i = 0; i < len - 1; i++)
	{
		this->password[i] += 2;
	}
}

void User::changePassword(const char * oldPassword, const char* newPass)
{
	for (size_t i = 0; i < strlen(password); i++)
	{
		this->password[i] -= 2;
	}

	if (strcmp(this->password, oldPassword) != 0)
	{
		for (size_t i = 0; i < strlen(oldPassword); i++)
		{
			this->password[i] += 2;
		}
		cout << "Invalid Password!" << endl;
	}
	else
	{
		delete[] this->password;
		int length = strlen(newPass) + 1;
		this->password = new char[length];
		strcpy_s(this->password,length, newPass);
		for (int i = 0; i < length - 1; i++)
		{
			this->password[i] += 2;
		}
	}
}

void User::print() const
{
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "Title: " << title << endl;
	cout << "IP Adress: " << ipAdress<< endl;
}

PowerUser::PowerUser(int _reputation, const char * username, const char * password, const char * title, const char * ipAdress) : User(username,password,title,ipAdress)
{
	reputation = _reputation;
}

void PowerUser::giveReputation(const User & obj)
{
	if ( strcmp( username, obj.getUsername()) != 0 )
	{
		reputation++;
	}
	else cout << "Error!" << endl; return;
}

void PowerUser::printPU() const
{
	for (int i = 0; i <strlen(password); i++)
	{
		this->password[i] -= 2;
	}
	cout << "Username: " << username << endl;
	cout << "Password: " << password << endl;
	cout << "Title: " << title << endl;
	cout << "IP Adress: " << ipAdress << endl;
	cout << "Reputation: " << reputation << endl;
}

VIP::VIP(const char * name, const char * pass, const char * title, const char * ip) : User(name,pass,title,ip)
{
}

void VIP::setTitle(const char * _title)
{
	delete[] title;
	int len = strlen(_title) + 1;
	title = new char[len];
	strcpy_s(title,len, _title);

}

Admin::Admin(const char * name, const char *pass, const char *title, const char *ip) : User(name,pass,title,ip)
{
}

void Admin::setAdminUsername(const char * user)
{
	delete[] username;
	int len = strlen(user) + 1;
	username = new char[len];
	strcpy_s(username,len, user);
}

void Admin::setNameOtherUser(User & obj,const char * user)
{
	delete[] obj.username;
	int len = strlen(user) + 1;
	obj.username = new char[len];
	strcpy_s(obj.username,len, user);
}

