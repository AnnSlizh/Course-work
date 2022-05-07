#include <conio.h>
#include "menu.h"
#include <iomanip>

const int NUMBER_OF_ATTEMPTS = 2;
const int YES = 1;
const int NOT = 0;
const int FIRST_ACCOUNT = 0;

void authorizationMenu()
{
	cout << SIGN_IN_TEXT << endl;
	cout << SIGN_UP_TEXT << endl;
	cout << EXIT_OF_SYSTEM_TEXT;
}

void menuOfAuthorization(vector <User>& users, vector <Ticket>& tickets)
{
	bool flag = true;
	
	while (flag)
	{
		system("CLS");
		authorizationMenu();

		switch (_getch())
		{
		case '1': 	system("CLS");
			signInAccount(users, tickets);
			break;

		case '2': 	system("CLS");
			registerNewUser(users);
			break;

		case '3': 	system("CLS");
			writeUsersInFile(users);
			writeTicketsInFile(tickets);
			flag = false;
		}
	}
}

void userMode(User userAccount, vector <User>& users, vector <Ticket>& tickets)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		cout << USER_MODE_TEXT << endl;
		cout << SYSTEM_TICKETS_SALES_TEXT << endl;
		cout << TWO_TEXT << EXIT_FROM_ACCOUNT_TEXT;
		User userAccount;
		switch (_getch())
		{

		case '1': system("CLS");
			sortTicketsRecords(tickets);
			//writeTicketsInFile(tickets);
			break;

		case '2': system("CLS");
			cout << VALIDATE_EXIT_FROME_ACCOUNT_TEXT << endl;
			cout << YES_TEXT << endl << NOT_TEXT << endl;
			int digit;
			cin >> digit;

			if (digit == YES)
			{
				flag = false;
			}
			else break; // not;	 
		}
	}
}

void adminMode(User userAccount, vector <User>& users, vector <Ticket>& tickets)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		
		if (userAccount.role == Role::MAIN_ADMIN)
		{
			cout << MAIN_ADMIN_MODE_TEXT << endl;
		}
		else cout << ADMIN_MODE_TEXT << endl;
		cout << SYSTEM_TICKETS_SALES_TEXT << endl;
		cout << ACCOUNT_MANAGEMENT_TEXT << endl;
		cout << THREE_TEXT << EXIT_FROM_ACCOUNT_TEXT;
		
		switch (_getch())
		{
		case '1': system("CLS");
			manageTicketRecords(tickets);
			break;
		
		case '2': manageAccounts(userAccount, users);
			break;

		case '3': system("CLS");
			cout << VALIDATE_EXIT_FROME_ACCOUNT_TEXT << endl;
			cout << YES_TEXT << endl << NOT_TEXT << endl;
			int digit;
			cin >> digit;

			if (digit == YES) 
			{
				flag = false;
			}
			else break; // not;
		}
	}
}

void manageTicketRecords(vector <Ticket>& tickets)
{
	bool flag = true;
	
	while (flag)
	{
		system("CLS");
		cout << VIEW_TICKETS_RECORDS_TEXT << endl << ADD_NEW_TICKET_RECORD_TEXT << endl;
		cout << DELETE_TICKET_RECORD_TEXT << endl << CHANGE_TICKETS_RECORDS_TEXT << endl;
		cout  << FIFE_TEXT << RETURN_BACK_TEXT << endl;

		switch (_getch())
		{
		
		case '1': system("CLS");
			sortTicketsRecords(tickets);
			writeTicketsInFile(tickets);
			break;

		case '2': system("CLS");
			addNewTicketRecord(tickets);
			writeTicketsInFile(tickets);
			system("pause");
			break;

		case '3': system("CLS");

			if (tickets.size() == 0)
			{
				cout << TICKETS_NOT_EXIST_TEXT << endl;
				system("pause");
				break;
			}

			viewTicketsRecords(tickets);

			int numberOfRecord;

			cout << endl << ENTER_NUMBER_OF_RECORD_TEXT;
			cin >> numberOfRecord;

			while ( numberOfRecord >= tickets.size())
			{
				cout << BEYOND_THE_VECTOR_OF_TICKETS_TEXT << endl;
				cout << ENTER_NUMBER_OF_RECORD_TEXT;
				cin >> numberOfRecord;
			}

			system("CLS");
			cout << VALIDATE_DELATION_OF_RECORD_TEXT << endl;
			cout << YES_TEXT << endl << NOT_TEXT << endl;

			deleteTicketRecord(tickets, numberOfRecord);
			writeTicketsInFile(tickets);
			break;

		case '4': system("CLS");
			editTicketRecord(tickets);
			writeTicketsInFile(tickets);
			break;

		case '5': flag = false;
			break;
		}
	}
}

void manageAccounts(User userAccount, vector <User>& users)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		cout << ACCOUNT_MANAGEMENT_MODE_TEXT << endl;
		cout << VIEW_ACCOUNTS_TEXT << endl << ADD_NEW_ACCOUNT_TEXT << endl;
		cout << ACCOUNTS_SETTINGS_TEXT << endl << DELETE_ACCOUNT_TEXT << endl;
		cout << VIEW_APLICATIONS_TEXT << endl << SIX_TEXT << RETURN_BACK_TEXT << endl;

		switch (_getch())
		{
			case '1': system("CLS");
			viewAccounts(users);
			system("pause");
			break;

			case '2': system("CLS");
				addNewAccount(users);
				writeUsersInFile(users);
				system("pause");
				break;

			case '3': system("CLS");
				editAccount(users, userAccount);
				writeUsersInFile(users);
				break;
				
			case '4': system("CLS");
				int idOfAccount;
				int role, status;

				if (userAccount.role == Role::MAIN_ADMIN)
				{
					cout << ID_OF_ACCOUNT_TEXT << setw(14) << LOGIN_OF_ACCOUNT_TEXT << setw(15);
					cout << ROLE_OF_ACCOUNT_TEXT << setw(12) << STATUS_OF_ACCOUNT_TEXT << endl;
					cout << BORDER_OF_ACCOUNTS_TABLE_TEXT << endl;

					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].role != Role::MAIN_ADMIN && users[i].status != Status::WAITING)
						{
							cout << i << setw(15) << users[i].login << setw(15);
							role = users[i].role;
							status = users[i].status;

							roleToString(role);
							cout << setw(12);
							statusToString(status);
							cout << endl;
						}
					}

					cout << endl << ENTER_ID_OF_ACCOUNT_TEXT;
					cin >> idOfAccount;

					while (isCorrectValue(idOfAccount) || isNegativeValue(idOfAccount) || idOfAccount >= users.size())
					{
						cout << BEYOND_THE_VECTOR_OF_ACCOUNTS_TEXT << endl << ENTER_ID_OF_ACCOUNT_TEXT;
						cin >> idOfAccount;
					}

					while (true)
					{
						if (users[idOfAccount].role == Role::MAIN_ADMIN)
						{
							cout << NOT_DELETE_MAIN_ADMIN_TEXT << endl;
							cout << ENTER_ID_OF_ACCOUNT_TEXT;
							cin >> idOfAccount;
						}
						else if (users[idOfAccount].status == Status::WAITING)
						{
							cout << NOT_DELETE_WEITING_ACCOUNT_TEXT << endl;
							cout << ENTER_ID_OF_ACCOUNT_TEXT;
							cin >> idOfAccount;
						}
						else break;
					}
				}	
				else 
				{
					cout << ID_OF_ACCOUNT_TEXT << setw(14) << LOGIN_OF_ACCOUNT_TEXT << setw(15);
					cout << ROLE_OF_ACCOUNT_TEXT << setw(12) << STATUS_OF_ACCOUNT_TEXT << endl;
					cout << BORDER_OF_ACCOUNTS_TABLE_TEXT << endl;

					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].role == Role::USER)
						{
							cout << i << "\t" << users[i].login;
							role = users[i].role;
							status = users[i].status;

							roleToString(role);
							cout << "\t";
							statusToString(status);
							cout << endl;
						}
					}

					cout << endl << ENTER_ID_OF_ACCOUNT_TEXT;
					cin >> idOfAccount;

					while (isCorrectValue(idOfAccount) || isNegativeValue(idOfAccount) || idOfAccount >= users.size())
					{
						cout << BEYOND_THE_VECTOR_OF_ACCOUNTS_TEXT << endl << ENTER_ID_OF_ACCOUNT_TEXT;
						cin >> idOfAccount;
					}

					while (true)
					{
						if (users[idOfAccount].role == Role::MAIN_ADMIN)
						{
							cout << NOT_DELETE_MAIN_ADMIN_TEXT << endl;
							cout << ENTER_ID_OF_ACCOUNT_TEXT;
							cin >> idOfAccount;
						}
						else if (users[idOfAccount].role == Role::ADMIN)
						{
							cout << NOT_DELETE_ADMIN_TEXT << endl;
							cout << ENTER_ID_OF_ACCOUNT_TEXT;
							cin >> idOfAccount;
						}
						else if (users[idOfAccount].status == Status::WAITING)
						{
							cout << NOT_DELETE_WEITING_ACCOUNT_TEXT << endl;
							cout << ENTER_ID_OF_ACCOUNT_TEXT;
							cin >> idOfAccount;
						}
						else break;
					}
				}
				system("CLS");

				cout << VALIDATE_DELATION_OF_ACCOUNT_TEXT << endl;
				cout << YES_TEXT << endl << NOT_TEXT << endl;

				deleteAccount(users, idOfAccount);
				writeUsersInFile(users);
				break;
				
			case '5': system("CLS");
				manageApplication(users);
				writeUsersInFile(users);
				break;

			case '6': flag = false;
				break;
		}
	}
}

void addNewAccount(vector <User>& users)
{
	User newAccount;
	int role;
	string password;

	cout << CREATING_ACCOUNT_MODE_TEXT << endl;

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
	cin >> password;

	while (isPasswordCorrect(password) == false)
	{
		cout << PASSWORD_NOT_CORRECT_TEXT << endl;
		cout << ENTER_PASSWORD_TEXT;
		cin >> password;
	}

	newAccount.password = md5(password);

	cout << endl << ROLE_ADMIN_TEXT << endl;
	cout << ROLE_USER_TEXT << endl;
	cout << ENTER_ROLE_OF_ACCOUNT_TEXT;
	cin >> role;

	while (isCorrectValue(role) || isNegativeValue(role) || role < Role::ADMIN || role > Role::USER)
	{
		cout << NOT_CORRECT_ROLE_TEXT << endl << ENTER_ROLE_OF_ACCOUNT_TEXT;
		cin >> role;
	}

	newAccount.role = static_cast<Role>(role);
	newAccount.status = Status::ACTIVE;

	users.push_back(newAccount);

	cout << ACCOUNT_ADDED_TEXT << endl;
}

void editAccount(vector <User>& users, User userAccount)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		viewAccounts(users);

		cout << endl << CHOCE_ACTION_TEXT << endl;
		cout << CHANGE_ROLE_TEXT << endl;
		cout << CHANGE_STATUS_TEXT << endl;
		cout << THREE_TEXT << RETURN_BACK_TEXT << endl;

		int idOfAccount;

		switch (_getch())
		{
		case '1':
			
			if (userAccount.role == Role::ADMIN)
			{
				system("CLS");
				cout << NOT_CHANGE_ROLE_TEXT << endl;
				system("pause");
			}
			else
			{
				cout << ENTER_ID_OF_ACCOUNT_TEXT;
				cin >> idOfAccount;

				while (isCorrectValue(idOfAccount) || isNegativeValue(idOfAccount) || idOfAccount >= users.size())
				{
					cout << BEYOND_THE_VECTOR_OF_ACCOUNTS_TEXT << endl << ENTER_ID_OF_ACCOUNT_TEXT;
					cin >> idOfAccount;
				}

				if (users[idOfAccount].role == Role::MAIN_ADMIN)
				{
					system("CLS");
					cout << NOT_CHANGE_ROLE_MAIN_ADMIN_TEXT << endl;
					system("pause");
					break;
				}
				else if (users[idOfAccount].status == Status::WAITING)
				{
					system("CLS");
					cout << NOT_CHANGE_ROLE_OF_WAITING_ACCOUNT_TEXT << endl;
					system("pause");
					break;
				}
				else if (users[idOfAccount].role == Role::USER)
				{
					users[idOfAccount].role = Role::ADMIN;
					break;
				}
				else
				{
					users[idOfAccount].role = Role::USER;
					break;
				}
			}
			break;

		case '2':
			cout << ENTER_ID_OF_ACCOUNT_TEXT;
			cin >> idOfAccount;

			while (isCorrectValue(idOfAccount) || isNegativeValue(idOfAccount) || idOfAccount >= users.size())
			{
				cout << BEYOND_THE_VECTOR_OF_ACCOUNTS_TEXT << endl << ENTER_ID_OF_ACCOUNT_TEXT;
				cin >> idOfAccount;
			}

			if (userAccount.role == Role::ADMIN)
			{
				if (users[idOfAccount].role == Role::MAIN_ADMIN)
				{
					system("CLS");
					cout << NOT_CHANGE_STATUS_MAIN_ADMIN_TEXT << endl;
					system("pause");
				}
				else if (users[idOfAccount].role == Role::ADMIN)
				{
					system("CLS");
						cout << NOT_CHANGE_STATUS_ADMIN_TEXT << endl;
						system("pause");
				}
				else if (users[idOfAccount].status == Status::WAITING)
				{
					system("CLS");
					cout << NOT_CHANGE_STATUS_OF_WAITING_ACCOUNT_TEXT << endl;
					system("pause");
					break;
				}
				else if (users[idOfAccount].status == Status::ACTIVE)
				{
					users[idOfAccount].status = Status::BLOCKED;
					break;
				}
				else
				{
					users[idOfAccount].status = Status::ACTIVE;
					break;
				}
				
			}
			else
			{
				if (users[idOfAccount].role == Role::MAIN_ADMIN)
				{
					system("CLS");
					cout << NOT_CHANGE_STATUS_MAIN_ADMIN_TEXT << endl;
					system("pause");
				}
				else if (users[idOfAccount].status == Status::WAITING)
				{
					system("CLS");
					cout << NOT_CHANGE_STATUS_OF_WAITING_ACCOUNT_TEXT << endl;
					system("pause");
					break;
				}
				else if(users[idOfAccount].status == Status::ACTIVE)
				{
					users[idOfAccount].status = Status::BLOCKED;
					break;
				}
				else
				{
					users[idOfAccount].status = Status::ACTIVE;
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

void manageApplication(vector <User>& users)
{	
	bool flag = true;
	while (flag)
	{
		system("CLS");
		int counter = 0;

		cout << ID_OF_ACCOUNT_TEXT << setw(14) << LOGIN_OF_ACCOUNT_TEXT << setw(15);
		cout << ROLE_OF_ACCOUNT_TEXT << setw(12) << STATUS_OF_ACCOUNT_TEXT << endl;
		cout << BORDER_OF_ACCOUNTS_TABLE_TEXT << endl;

		for (int i = 0; i < users.size(); i++)
		{		
			if (users[i].status == Status::WAITING)
			{
				cout << i << setw(15) << users[i].login << setw(15);

				int role = users[i].role;
				int status = users[i].status;
				
				roleToString(role);
				cout << setw(12);
				
				statusToString(status);
				cout << endl;

				counter++;
			}
		}
		if (counter == 0)
		{
			system("CLS");
			cout << NOT_APPLICATIONS_TEXT << endl;
			system("pause");
			break;
		}
		cout << endl << CHOCE_ACTION_TEXT << endl;
		cout << ACCEPT_APPLICATION_TEXT << endl << BLOCKED_APPLICATION_TEXT << endl;
		cout << THREE_TEXT << RETURN_BACK_TEXT << endl;

		switch (_getch())
		{
		case '1': acceptAplication(users);
			break;

		case '2':
			int numberOfApplication;
			cout << ENTER_ID_OF_APPLICATION;
			cin >> numberOfApplication;

			while (users[numberOfApplication].status != Status::WAITING)
			{
				cout << NOT_CORRECT_ID_TEXT << endl;
				cout << ENTER_ID_OF_APPLICATION;
				cin >> numberOfApplication;
			}

			system("CLS");
			cout << VALIDATE_ACCEPTANE_OF_APPLICATION_TEXT << endl;
			cout << YES_TEXT << endl << NOT_TEXT << endl;

			deleteAccount(users, numberOfApplication);
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

	while (users[numberOfApplication].status != Status::WAITING)
	{
		cout << NOT_CORRECT_ID_TEXT << endl;
		cout << ENTER_ID_OF_APPLICATION;
		cin >> numberOfApplication;
	}

	system("CLS");
	cout << VALIDATE_ACCEPTANE_OF_APPLICATION_TEXT << endl;
	cout << YES_TEXT << endl << NOT_TEXT << endl;

	int digit;
	cin >> digit;

	if (digit == YES)
	{
		users[numberOfApplication].status = Status::ACTIVE;
	}
	else if (digit == NOT) return;
}

void deleteAccount(vector <User>& users, int idOfAccount)
{
	int digit;
	cin >> digit;

	if (digit == YES)
	{
		auto iter = users.cbegin();

		if (idOfAccount == FIRST_ACCOUNT)
		{
			users.erase(iter);
		}
		else
		{
			users.erase(iter + idOfAccount);
		}
		system("CLS");
		cout << ACOOUNT_IS_DELETED_TEXT << endl;
		system("pause");
	}
	else if (digit == NOT) return;
}

void viewAccounts(vector <User>& users)
{
	cout << ID_OF_ACCOUNT_TEXT << setw(14) << LOGIN_OF_ACCOUNT_TEXT << setw(15);
	cout << ROLE_OF_ACCOUNT_TEXT << setw(12) << STATUS_OF_ACCOUNT_TEXT << endl;
	cout << BORDER_OF_ACCOUNTS_TABLE_TEXT << endl;
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].status != Status::WAITING)
		{
			cout << i << setw(15) << users[i].login << setw(15);
			
			int role = users[i].role;
			int status = users[i].status;

			roleToString(role);
			cout << setw(12);
			statusToString(status);
			cout << endl;
		}
	}
}
