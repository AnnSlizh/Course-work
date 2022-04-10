#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "datastructs.h"
#include "fileio.h"
#include "authorization .h"
#include "menu.h"
#include "tickets.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	vector <User> users;
	vector <Ticket> tickets;
	

	//readUsersFromFile(users);

	/*cout << users.size();
	cout << endl;*/
	/*User user1;
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
	user3.role = Role::USER;
	user3.status = Status::WAITING;
	
	users.push_back(user1);
	users.push_back(user2);
	users.push_back(user3);

	menuOfAuthorization(users);
		//registerNewUser(users);
	//signInAccount(users);
	//addNewAccount(users);
//	viewAccounts(users);
	//manageAccounts( users);
	//editAccount(users);
	//viewAccounts(users);*/
	//manageApplication(users);

	//readTicketsFromFile(tickets);

	Ticket tick1;
	tick1.type = Transport::BUS;
	tick1.month = 1;
	tick1.year = 2019;
	tick1.costOfTicket = 2.5;
	tick1.soldTickets = 4;
	Ticket tick2;
	tick2.type = Transport::TROLLEYBUS;
	tick2.month = 1;
	tick2.year = 2018;
	tick2.costOfTicket = 10.1;
	tick2.soldTickets = 5;
	Ticket tick3;
	tick3.type = Transport::TROLLEYBUS;
	tick3.month = 1;
	tick3.year = 2020;
	tick3.costOfTicket = 1.89;
	tick3.soldTickets = 9;

	tickets.push_back(tick1);
	tickets.push_back(tick2);
	tickets.push_back(tick3);
	
	/*cout << "month: ";
	int month;
	cin >> month;*/

	
	//addNewTicketNote(tickets);
	manageTicketRecords(tickets);
	//calculateTotalIncome(tickets);
	//viewTopOfSoldTickets(tickets, month);
	//writeTicketsInFile(tickets);
	

	/*for (int i = 0; i < tickets.size(); i++)
	{
		cout << i << " " << tickets[i].type << " " << tickets[i].month << " " << tickets[i].year << " ";
		cout << tickets[i].costOfTicket << " " << tickets[i].soldTickets << endl;
	}
	*/
	/*for (int i = 0; i < users.size(); i++)
	{
		cout << users[i].login << " " << users[i].password << " " << users[i].role << " " << users[i].status << "|";
	}*/
	//writeUsersInFile(users);
}
