#pragma once
#include <string>
using namespace std;

enum  Role
{
	MAIN_ADMIN,
	ADMIN,
	USER,
};

enum Status
{
	ACTIVE,
	BLOCKED,
	WAITING
};
struct User
{
	string login;
	string password;
	Role role;
	Status status;
};



