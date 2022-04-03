#include <iostream>
#include <stdio.h>
#include <vector>
#include "datastructs.h"
#include "fileio.h"
#include "authorization .h"
#include "menu.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	vector <User> users;

	

	//readUsersFromFile(users);

	/*cout << users.size();
	cout << endl;*/
	User user1;
	user1.login = "a111";
	user1.password = "123";
	user1.role = Role::MAIN_ADMIN;
	user1.status = Status::ACTIVE;
	User user2;
	user2.login = "a2";
	user2.password = "123";
	user2.role = Role::ADMIN;
	user2.status = Status::ACTIVE;
	User user3;
	user3.login = "a3";
	user3.password = "123";
	user3.role = Role::ADMIN;
	user3.status = Status::WAITING;
	
	users.push_back(user1);
	users.push_back(user2);
	users.push_back(user3);

	//menuOfAuthorization(users);
		//registerNewUser(users);
	//signInAccount(users);
	//addNewAccount(users);
//	viewAccounts(users);
	manageAccounts(users);
	//editAccount(users);
	//viewAccounts(users);
	//manageApplication(users);
	/*for (int i = 0; i < users.size(); i++)
	{
		cout << users[i].login << " " << users[i].password << " " << users[i].role << " " << users[i].status << "|";
	}*/
	//writeUsersInFile(users);
}