#pragma once
class Guest
{
protected:
	char* ipAdress=nullptr;
public:
	Guest(const char* = "");
	Guest(const Guest&);
	Guest & operator=(const Guest&);
	~Guest();
};

class User : public Guest
{
	friend class Admin;
protected:
	char* username=nullptr;
	char* password=nullptr;
	char* title=nullptr;
public:
	User(const char* = "",const char* = "",const char* = "", const char* = "");
	User(const User&);
	User& operator=(const User&);
	~User();

	const char* getUsername() const;
	void setPassword(const char*);
	void changePassword(const char*,const char*);
	void print() const;
};

class PowerUser : virtual public User
{	
protected:
	int reputation;
public:
	PowerUser(int = 0, const char* = "", const char* = "", const char* = "", const char* = "");
	void giveReputation(const User& obj);
	void printPU() const;
};

class VIP : virtual public User
{
public:
	VIP(const char * = "", const char * = "" , const char * = "" , const char * = "");
	void setTitle(const char* _title);
};

class Admin : public VIP, public PowerUser
{
public:
	Admin(const char * = "", const char * = "", const char * = "", const char * = "");

	void setAdminUsername(const char* user);
	void setNameOtherUser(User& obj,const char* user);
};
