#include <iostream>
#include <vector>
#include "authorization .h"

using namespace std;

const int ENTER = 13;

void registerNewUser(vector <User>& users)
{
	string login;
	string password;
	string hashPassword;
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

	while (isPasswordCorrect(password) == false)
	{
		cout << PASSWORD_NOT_CORRECT_TEXT << endl;
		cout << ENTER_PASSWORD_TEXT;
		cin >> password;
	}
	
	hashPassword = md5(password);

	newUser.login = login;
	newUser.password = hashPassword;
	newUser.role = Role::USER;
	newUser.status = Status::WAITING;

	users.push_back(newUser);
	writeUsersInFile(users);

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
	char passwordTemp;
	string password;
	string hashPassword;

	passwordTemp = _getch();
	while (passwordTemp != ENTER) //character 13 is enter
	{
		password.push_back(passwordTemp);
		cout << '*';
		passwordTemp = _getch();
	}
	
	hashPassword = md5(password);


	for (int i = 0; i < users.size(); i++)
	{
		if (userAccount.login == users[i].login && userAccount.password == users[i].password)
		{
			userAccount.status = users[i].status;
			userAccount.role = users[i].role;
		}
	}

	bool flag = true;
	while (flag)
	{   
		if (!isAccountExist(userAccount.login, hashPassword, users) && !isAccountWaiting(userAccount.status, users) && !isAccountBlocked(userAccount.status, users))
		{
			system("CLS");
			cout << ACCOUNT_NOT_EXIT_TEXT << endl;
			cout << SIGN_IN_TEXT << endl << TWO_TEXT << RETURN_BACK_TEXT << endl;

			switch (_getch())
			{
			case '1': system("CLS");
				cout << AUTHORIZATION_IN_SYSTEM_TEXT << endl;
				cout << ENTER_LOGIN_TEXT;
				cin >> userAccount.login;

				cout << ENTER_PASSWORD_TEXT;
				password.erase();
				hashPassword.erase();

				passwordTemp = _getch();
				while (passwordTemp != ENTER) //character 13 is enter
				{
					password.push_back(passwordTemp);
					cout << '*';
					passwordTemp = _getch();
				}
				hashPassword = md5(password);

				break;

			case '2': flag = false;
				break;

			}	
		}
		else
		{
			userAccount.password = hashPassword;
			flag = false;
		}
	}

	for (int i = 0; i < users.size(); i++)
	{
		if (userAccount.login == users[i].login && userAccount.password == users[i].password)
		{
			userAccount.status = users[i].status;
			userAccount.role = users[i].role;
		}
	}

	if (isAccountWaiting(userAccount.status, users) == true) 
	{
		cout << endl << WAITNG_STATUS_TEXT << endl;
		system("pause");
	}
	else if (isAccountBlocked(userAccount.status, users) == true)
	{
		cout << endl << BLOCKED_STATUS_TEXT << endl;
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


