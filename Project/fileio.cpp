#include <iostream>
#include <vector>
#include <fstream>
#include "fileio.h"
#include "constants.h"
#include "md5.h"

void readUsersFromFile(vector <User>& users)
{
	fstream file;
	file.open(USERS_FILE_NAME, ios::in);
	if (!file.is_open())
	{
		file.open(USERS_FILE_NAME, ios::out);

		User adminTemp;

		adminTemp.login = MAIN_ADMIN_LOGIN;
		adminTemp.password = md5(MAIN_ADMIN_PASSWORD);
		adminTemp.role = Role::MAIN_ADMIN;
		adminTemp.status = Status::ACTIVE;
		
		file << adminTemp.login << " " << adminTemp.password << " " << adminTemp.role << " " << adminTemp.status;

		users.push_back(adminTemp);

		file.close();
	}
	else
	{
		User userTemp;

		while (!file.eof())
		{
			int role;
			int status;
			file >> userTemp.login >> userTemp.password;
			file >> role >> status;

			userTemp.role = static_cast<Role>(role);
			userTemp.status = static_cast<Status>(status);

			users.push_back(userTemp);
		}
	}
	file.close();
}

void writeUsersInFile(vector <User>& users)
{
	fstream file;
	file.open(USERS_FILE_NAME, ios::out);

	for (int i = 0; i < users.size(); i++)
	{
		file << users[i].login << " " << users[i].password << " " << users[i].role << " " << users[i].status;
		if (i != users.size() - 1)
		{
			file << endl;			//Если последний элемент вектора, то переход на новую строку не ставится
		}
	}
	file.close();
}

void readTicketsFromFile(vector <Ticket>& tickets)
{
	fstream file;
	file.open(TICKETS_FILE_NAME, ios::in);

	Ticket ticketTemp;

	if (!file.is_open())
	{
		file.open(TICKETS_FILE_NAME, ios::out);
		cout << TICKETS_NOT_EXIST_TEXT << endl;
		file.close();
	}

	while (!file.eof())
	{
		int type;
		file >> type >> ticketTemp.month >> ticketTemp.year;
		file >> ticketTemp.costOfTicket >> ticketTemp.soldTickets;

		ticketTemp.type = static_cast<Transport>(type);

		tickets.push_back(ticketTemp);
	}
	file.close();
}

void writeTicketsInFile(vector <Ticket>& tickets)
{
	fstream file;
	file.open(TICKETS_FILE_NAME, ios::out);

	for (int i = 0; i <tickets.size(); i++)
	{
		file << tickets[i].type << " " << tickets[i].month << " " << tickets[i].year << " ";
		file << tickets[i].costOfTicket << " " << tickets[i].soldTickets;

		if (i != tickets.size() - 1)
		{
			file << endl;			//Если последний элемент вектора, то переход на новую строку не ставится
		}
	}
	file.close();
}