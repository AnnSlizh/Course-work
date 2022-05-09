#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include "datastructs.h"
#include "fileio.h"
#include "authorization .h"
#include "menu.h"
#include "tickets.h"
#include "md5.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	vector <User> users;
	vector <Ticket> tickets;
	
	readUsersFromFile(users);
	readTicketsFromFile(tickets);

	menuOfAuthorization(users, tickets);

	writeTicketsInFile(tickets);
	//writeUsersInFile(users);
}
