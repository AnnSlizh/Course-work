#include <conio.h>
#include "menu.h"

const int NUMBER_OF_ATTEMPTS = 2;

void authorizationMenu()
{
	cout << SIGN_IN_TEXT << endl;
	cout << SIGN_UP_TEXT << endl;
	cout << EXIT_OF_SYSTEM_TEXT;
}

void menuOfAuthorization(vector <User>& users)
{
	bool flag = true;
	
	while (flag)
	{
		system("CLS");
		authorizationMenu();

		switch (_getch())
		{
		case '1': 	system("CLS");
			signInAccount(users);
			break;

		case '2': 	system("CLS");
			registerNewUser(users);
			break;

		case '3': 	system("CLS");
			flag = false;
		}
	}
}

void userMode(vector <User>& users)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		cout << USER_MODE_TEXT << endl;
		cout << SYSTEM_TICKETS_SALES_TEXT << endl;
		cout << USER_CHANGE_PASSWORD_TEXT << endl;
		cout << EXIT_OF_ACCOUNT_TEXT;

		switch (_getch())
		{
		/*case '2':
			User userAccount;
			cout << ENTER_LOGIN_TEXT; cin >> userAccount.login;
			cout << ENTER_PASSWORD_FOR_CHANGE_TEXT; cin >> userAccount.password;
			for (int i = 0; i < users.size(); i++)
			{
				if (userAccount.password == users[i].password)
				{
					cout << ENTER_NEW_PASSWORD_TEXT; cin >> userAccount.password;
					userAccount.password = users[i].password;
				}
				else
				{
					for (int k = 0; k < NUMBER_OF_ATTEMPTS; i++)
					{
						cout << PACCWORD_NOT_CORRECT_TEXT << endl;
						cin >> userAccount.password;
					}
					
				}
			}*/

		case '3': authorizationMenu();
			break;
		}
	}
}

void adminMode(User userAccount, vector <User>& users)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		
		if (userAccount.role == Role::MAIN_ADMIN)
		{
			cout << MAIN_ADMIN_MODE_TEXT << endl;
		}
		else cout << ADMIN_MODE_TEXT;
		cout << SYSTEM_TICKETS_SALES_TEXT << endl;
		cout << ACCOUNT_MANAGEMENT_MODE_TEXT << endl;
		cout << ADMIN_CHANGE_PASSWORD_TEXT << endl;
		cout << EXIT_FROM_ACCOUNT_TEXT;
		
		switch (_getch())
		{
		
		case '4': flag = false;
		}
	}
}

void manageAccounts(vector <User>& users)
{
	bool flag = true;
	while (flag)
	{
		switch (_getch())
		{
		case '4': addNewAccount(users);
		}
	}
}

void addNewAccount(vector <User>& users)
{
	User newAccount;
	int role;

	cout << ADD_NEW_ACCOUNT_TEXT << endl;

	bool flag = true;
	while (flag)
	{
		cout << ENTER_LOGIN_TEXT;
		cin >> newAccount.login;

		if (isLoginCorrect(newAccount.login) == false)
		{
			cout << LOGIN_NOT_CORRECT_TEXT << endl;;

		}
		else if (isLoginExist(newAccount.login, users) == true)
		{
			cout << LOGIN_IS_EXIST_TEXT << endl;
		}
		else flag = false;
	}

	cout << ENTER_PASSWORD_TEXT;
	cin >> newAccount.password;

	cout << ROLE_ADMIN_TEXT << endl;
	cout << ROLE_USER_TEXT << endl;
	cout << ENTER_ROLE_OF_ACCOUNT_TEXT;
	cin >> role;
	newAccount.role = static_cast<Role>(role);
	newAccount.status = Status::ACTIVE;

	users.push_back(newAccount);

	cout << ACCOUNT_ADDED_TEXT;
}


