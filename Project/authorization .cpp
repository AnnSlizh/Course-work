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

	system("CLS");

	cout << APPLICATION_IS_SENT_TEXT << endl;
	cout << SYSTEM_ACCESS_TEXT << endl;
	system("pause");
}

void signInAccount(vector <User>& users, vector <Ticket>& tickets)
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
		if (isPasswordCorrect(userAccount.login, userAccount.password, users) == false)
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

	if (isAccountWaiting(userAccount.status, users) == true) 
	{
		cout << WAITNG_STATUS_TEXT << endl;
		system("pause");
	}
	else if (isAccountBlocked(userAccount.status, users) == true)
	{
		cout << BLOCKED_STATUS_TEXT << endl;
		system("pause");
	}
	else
	{
		if (userAccount.role == Role::USER)
		{
			userMode(userAccount, users, tickets);
		}
		else if (userAccount.role == Role::MAIN_ADMIN || userAccount.role == Role::ADMIN)
		{
			adminMode(userAccount, users, tickets);
		}
	}
}


