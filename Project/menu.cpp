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
		cout << THREE_TEXT << EXIT_FROM_ACCOUNT_TEXT;
		User userAccount;
		switch (_getch())
		{

		case '1': system("CLS");
			sortTicketsRecords(tickets);
			break;

		case '2': system("CLS");
			//cout << ENTER_LOGIN_TEXT; cin >> userAccount.login;
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
					for (int i = 0; i < NUMBER_OF_ATTEMPTS; i++)
					{
						cout << PACCWORD_NOT_CORRECT_TEXT << endl;
						cout << ENTER_PASSWORD_FOR_CHANGE_TEXT; cin >> userAccount.password;
					}
					cout << PASSWORD_CHANGE_NOT_AVALIABLE_TEXT;
					system("pause");
					break;
				}
			}

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
		cout << CALCULATE_TOTAL_INCOME_OF_TICKETS_TEXT << endl << SIX_TEXT << RETURN_BACK_TEXT << endl;

		switch (_getch())
		{
		
		case '1': system("CLS");
			sortTicketsRecords(tickets);
			break;

		case '2': system("CLS");
			addNewTicketRecord(tickets);
			system("pause");
			break;

		case '3': system("CLS");
			int numberOfRecord;

			cout << ENTER_NUMBER_OF_RECORD_TEXT;
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
			break;

		case '4': system("CLS");
			editTicketRecord(tickets);
			break;

		case '5': system("CLS");

			int month;
			int counter;
			counter = 0;

			cout << ENTER_MONTH_OF_SALE_TEXT;
			cin >> month;

			while (isMonthExist(month) == true)
			{
				cout << ENTER_CORRECT_MONTH_TEXT;
				cin >> month;
			}

			if (calculateTotalIncome(tickets, month) == 0)
			{
				cout << NOT_SOLD_TICKETS_IN_MONTH_TEXT << endl;
			}
			else
			{
				viewTopOfSoldTickets(tickets, month);
				cout << TOTAL_INCOME_OF_TICKETS_TEXT << calculateTotalIncome(tickets, month) << endl;
			}
		
			system("pause");
			break;

		case '6': flag = false;
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
				system("pause");
				break;

			case '3': system("CLS");
				editAccount(users);
				break;
				
			case '4': system("CLS");
				int idOfAccount;
				int role, status;

				if (userAccount.role == Role::MAIN_ADMIN)
				{
					for (int i = 0; i < users.size(); i++)
					{
						if (users[i].role != Role::MAIN_ADMIN && users[i].status != Status::WAITING)
						{
							cout << i << "\t" << users[i].login << "\t";
							role = users[i].role;
							status = users[i].status;

							roleToString(role);
							cout << "\t";
							statusToString(status);
							cout << endl;
						}
					}
				}
					
				else 
				{
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
				}
				cout << ENTER_ID_OF_ACCOUNT_TEXT;
				cin >> idOfAccount;
				
				while (idOfAccount >= users.size())
				{
					cout << BEYOND_THE_VECTOR_OF_ACCOUNTS_TEXT << endl;
					cout << ENTER_ID_OF_ACCOUNT_TEXT;
					cin >> idOfAccount;
				}

				system("CLS");

				cout << VALIDATE_DELATION_OF_ACCOUNT_TEXT << endl;
				cout << YES_TEXT << endl << NOT_TEXT << endl;

				deleteAccount(users, idOfAccount);
				break;
				
			case '5': system("CLS");
				manageApplication(users);
				break;

			case '6': flag = false;
				break;
		}
	}
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
			//cout << i << "\t" << users[i].login << "\t";

			int role = users[i].role;
			int status = users[i].status;

			roleToString(role);
			cout << setw(12);
			statusToString(status);
			cout << endl;
		}
	}
}

void addNewAccount(vector <User>& users)
{
	User newAccount;
	int role;

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
	cin >> newAccount.password;

	cout << endl << ROLE_ADMIN_TEXT << endl;
	cout << ROLE_USER_TEXT << endl;
	cout << ENTER_ROLE_OF_ACCOUNT_TEXT;
	cin >> role;
	newAccount.role = static_cast<Role>(role);
	newAccount.status = Status::ACTIVE;

	users.push_back(newAccount);

	cout << ACCOUNT_ADDED_TEXT << endl;
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
		cout << THREE_TEXT << RETURN_BACK_TEXT << endl;

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

void manageApplication(vector <User>& users)
{	
	bool flag = true;
	while (flag)
	{
		system("CLS");
		int counter = 0;

		cout << ID_OF_ACCOUNT_TEXT << setw(14) << LOGIN_OF_ACCOUNT_TEXT << setw(15);
		cout << ROLE_OF_ACCOUNT_TEXT << STATUS_OF_ACCOUNT_TEXT << endl;
		cout << BORDER_OF_ACCOUNTS_TABLE_TEXT << endl;

		for (int i = 0; i < users.size(); i++)
		{		
			if (users[i].status == Status::WAITING)
			{
				cout << i << setw(15) << users[i].login << setw(15);

				int status = users[i].status;

				statusToString(status);
				cout << endl;

				counter++;
			}
		}
		if (counter == 0)
		{
			system("CLS");
			cout << NOT_APPLICATIONS_TEXT << endl;
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

			system("CLS");
			cout << VALIDATE_DELATION_OF_APPLICATION_TEXT << endl;
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

	for (int i = 0; i < users.size(); i++)
	{
		system("CLS");
		cout << VALIDATE_ACCEPTANE_OF_APPLICATION_TEXT << endl;
		cout << YES_TEXT << endl << NOT_TEXT << endl;

		int digit;
		cin >> digit;

		if (digit == YES) 
		{
			users[numberOfApplication].status = Status::ACTIVE;
			break;
		}
		else if (digit == NOT) break; 
	}
}

