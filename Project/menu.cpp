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
		cout << ACCOUNT_MANAGEMENT_TEXT << endl;
		cout << ADMIN_CHANGE_PASSWORD_TEXT << endl;
		cout << EXIT_FROM_ACCOUNT_TEXT;
		
		switch (_getch())
		{
		
		//case '2': manageAccounts(users);

		case '4': flag = false;
		}
	}
}

void manageAccounts(vector <User>& users)
{
	

	bool flag = true;
	while (flag)
	{
		system("CLS");
		cout << ACCOUNT_MANAGEMENT_MODE_TEXT << endl;
		cout << VIEW_ACCOUNTS_TEXT << endl << ADD_NEW_ACCOUNT_TEXT << endl;
		cout << ACCOUNTS_SETTINGS_TEXT << endl << DELETE_ACCOUNT_TEXT << endl;
		cout << VIEW_APLICATIONS_TEXT << endl << RETURN_BACK_TEXT << endl;

		switch (_getch())
		{
			//case '1': system("CLS");
			//viewAccounts(users);
		//	break;

			case '2': system("CLS");
				addNewAccount(users);
				system("pause");
				break;

			case '3': system("CLS");
			//	viewAccounts(users);
				editAccount(users);
				break;
				//case '4': 
				
			case '5': system("CLS");
				manageApplication(users);
				break;

			case '6': flag = false;
				break;
				
			//}
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

	cout << ACCOUNT_ADDED_TEXT << endl;
}

void viewAccounts(vector <User>& users)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].status != Status::WAITING)
		{

			cout << i << "\t" << users[i].login << "\t";

			int role = users[i].role;
			int status = users[i].status;

			roleToString(role);
			cout << "\t";
			statusToString(status);
			cout << endl;
		}
	}
}
/*void deleteAccount(vector <User>& users)
{

}*/

void manageApplication(vector <User>& users)
{	
	bool flag = true;
	while (flag)
	{
		system("CLS");
		int counter = 0;
		for (int i = 0; i < users.size(); i++)
		{
			if (users[i].status == Status::WAITING)
			{
				cout << i << "\t" << users[i].login << endl;
				counter++;
			}
		}
		if (counter == 0) cout << NOT_APPLICATIONS_TEXT << endl;
		
		cout << endl << CHOCE_ACTION_TEXT << endl;
		cout << ACCEPT_APPLICATION_TEXT << endl << BLOCKED_APPLICATION_TEXT << endl;
		cout << RETURN_TO_MENU_TEXT << endl;

		switch (_getch())
		{
		case '1': acceptAplication(users);
			break;

		case '2': blockedApplication(users);
			break;

		case '3': flag = false;
			break;
		}
	}
}

void acceptAplication(vector <User>& users)
{
	int numberOfApplication;

	cout << ENTER_ID_OF_APPLICATION;
	cin >> numberOfApplication;

	for (int i = 0; i < users.size(); i++)
	{
		system("CLS");
		cout << VALIDATE_ACCEPTANE_OF_APPLICATION_TEXT << endl;
		cout << YES_TEXT << endl << NOT_TEXT << endl;

		int digit;
		cin >> digit;

		if (digit == 1) //yes
		{
			users[numberOfApplication].status = Status::ACTIVE;
			break;
		}
		else if (digit == 2) break; //not
	}
}

void blockedApplication(vector <User>& users)
{
	int numberOfApplication;
	cout << ENTER_ID_OF_APPLICATION;
	cin >> numberOfApplication;

	for (int i = 0; i < users.size(); i++)
	{
		system("CLS");
		cout << VALIDATE_DELATION_OF_APPLICATION_TEXT << endl;
		cout << YES_TEXT << endl << NOT_TEXT << endl;

		int digit;
		cin >> digit;

		if (digit == 1) //yes
		{
			auto iter = users.cbegin();

			if (numberOfApplication == 0)
			{
				users.erase(iter);
				break;
			}
			else
			{
				users.erase(iter + numberOfApplication);
				break;
			}
		}
		else if (digit == 2) break; //not
	}
}

void editAccount(vector <User>& users)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		viewAccounts(users);

		cout << endl << CHOCE_ACTION_TEXT << endl;
		cout << CHANGE_ROLE_TEXT << endl;
		cout << CHANGE_STATUS_TEXT << endl;
		cout << RETURN_TO_MENU_TEXT << endl;

		int idOfAcccount;
	
		switch (_getch())
		{
		case '1':
			cout << ENTER_ID_OF_ACCOUNT_TEXT;
			cin >> idOfAcccount;

			if (users[idOfAcccount].role == Role::MAIN_ADMIN)
			{
				system("CLS");
				cout << NOT_CHANGE_ROLE_MAIN_ADMIN_TEXT << endl;
				system("pause");
				break;
			}
			else if (users[idOfAcccount].role == Role::USER)
			{
				users[idOfAcccount].role = Role::ADMIN;
				break;
			}
			else
			{
				users[idOfAcccount].role = Role::USER;
				break;
			}
		break;

		case '2':
			cout << ENTER_ID_OF_ACCOUNT_TEXT;
			cin >> idOfAcccount;

			if (users[idOfAcccount].role == Role::MAIN_ADMIN)
			{
				system("CLS");
				cout << NOT_CHANGE_STATUS_MAIN_ADMIN_TEXT << endl;
				system("pause");
			}
			else
			{
				if (users[idOfAcccount].status == Status::ACTIVE)
				{
					users[idOfAcccount].status = Status::BLOCKED;
					break;
				}
				else
				{
					users[idOfAcccount].status = Status::ACTIVE;
					break;
				}
			}
		break;

		case '3': 
			flag = false;
			break;
		}
	}
}

void roleToString(int role)
{
	switch (role)
	{
	case Role::ADMIN: cout << ADMIN_TEXT;
		break;
		
	case Role::MAIN_ADMIN: cout << MAIN_ADMIN_TEXT;
		break;

	case Role::USER: cout << USER_TEXT;
		break;
	}
}
void statusToString(int status)
{
	switch (status)
	{
	case Status::ACTIVE: cout << ACTIVE_TEXT;
		break;

	case Status::BLOCKED: cout << BLOCKED_TEXT;
		break;

	case Status::WAITING: cout << WAITING_TEXT;
		break;
	}
}