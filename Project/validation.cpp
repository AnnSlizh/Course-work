#include <vector>
#include "validation.h"

const int MIN_LOGIN_SIZE = 3;
const int MAX_LOGIN_SIZE = 20;

bool isLoginCorrect(string login)
{
	int sizeLogin = size(login);

	if (sizeLogin > MIN_LOGIN_SIZE && sizeLogin < MAX_LOGIN_SIZE)
	{
		return true;
	}
	return false;
}

bool isLoginExist(string login, vector <User>& users)
{
	for(int i = 0; i < users.size(); i++)
	{
		if (users[i].login == login)
		{
			return true;
		}
	}
	return false;
}

bool isMonthExist(int month)
{
	if (month < 1 && month > 12)
	{
		return true;
	}
	return false;
}


/*bool isPasswordExist(string password, vector <User>& users)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].password == password)
		{
			return true;
		}
	}
	return false;
}*/

