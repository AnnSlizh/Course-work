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
	
	bool flag = true;
	while (flag)
	{
		cout << ENTER_LOGIN_TEXT;
		cin >> login;

		if (isLoginCorrect(login) == false)
		{
			cout << LOGIN_NOT_CORRECT_TEXT << endl;;
			
		}
		else if (isLoginExist(login, users) == true)
		{
			cout << LOGIN_IS_EXIST_TEXT << endl;
		}
		else flag = false;
	}

	cout << ENTER_PASSWORD_TEXT;
	cin >> password;

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
			userAccount.role = users[i].role;
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
	if (userAccount.role == Role::USER)
	{
		userMode(users);
	}
	else if (userAccount.role == Role::MAIN_ADMIN || userAccount.role == Role::ADMIN)
	{
		adminMode(userAccount, users);
	}

}

