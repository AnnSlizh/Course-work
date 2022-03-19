#include <iostream>
#include <vector>
#include "authorization .h"

using namespace std;

void registerNewUser(vector <User>& users)
{
	string login;
	string password;
	User newUser;

	cout << CREATING_ACCOUNT_MODE_TEXT << endl;
	cout << ENTER_LOGIN_TEXT;
	cin >> login;

	bool flag = true;
	while (flag)
	{
		if (isLoginCorrect(login) == false)
		{
			cout << LOGIN_NOT_CORRECT_TEXT << endl;
			cout << ENTER_LOGIN_TEXT;
			cin >> login;
		}
		else if (isLoginExist(login, users) == true)
		{
			cout << LOGIN_IS_EXIST_TEXT << endl;
			cout << ENTER_LOGIN_TEXT;
			cin >> login;
		}
		else flag = false;
	}

	cout << ENTER_PASSWORD_TEXT;
	cin >> password;

	/*flag = true;
	while (flag)
	{
		if (isPasswordExist(password, users) == true)
		{
			cout << PASSWORD_IS_EXIST_TEXT << endl;
			cout << ENTER_PASSWORD_TEXT;
			cin >> password;
		}
		else flag = false;
	}*/

	newUser.login = login;
	newUser.password = password;
	newUser.role = Role::USER;
	newUser.status = Status::WAITING;

	users.push_back(newUser);
}

void signInAccount(vector <User>& users)
{
	cout << AUTHORIZATION_IN_SYSTEM_TEXT << endl;

	User userAccount;

	cout << ENTER_LOGIN_TEXT;
	cin >> userAccount.login;
	cout << ENTER_PASSWORD_TEXT;
	cin >> userAccount.password;

	bool flag = true;
	while (flag)
	{
		if (isLoginExist(userAccount.login, users) == false)
		{
			cout << ACCOUNT_NOT_EXIT_TEXT << endl;
			cout << ENTER_LOGIN_TEXT;
			cin >> userAccount.login;
			cout << ENTER_PASSWORD_TEXT;
			cin >> userAccount.password;
		}
		else flag = false;
	}
		
	for (int i = 0; i < users.size(); i++)
	{
		if (userAccount.login == users[i].login)
		{
			userAccount.status = users[i].status;
		}
	}

	if (userAccount.status == Status::WAITING)
	{
		cout << WAITNG_STATUS_TEXT;
	}
	else if (userAccount.status == Status::BLOCKED)
	{
		cout << BLOCKED_STATUS_TEXT;
	}
	else cout << "ee";
}
