#include <iostream>
#include <vector>
#include "validation.h"


const int MIN_LOGIN_SIZE = 4;
const int MAX_LOGIN_SIZE = 20;
const int MIN_PASSWORD_SIZE = 6;

const int MIN_TYPE_OF_TRANSPORT = 0;
const int MAX_TYPE_OF_TRANSPORT = 5;
const int MIN_MONTH = 1;
const int MAX_MONTH = 12;
const int MIN_YEAR = 2000;
const int MAX_YEAR = 2022;
const int MIN_COST_OF_TICKET = 0;
const int MIN_VALUE = 0;

bool isLoginCorrect(string login)
{
	int sizeLogin = size(login);

	if (sizeLogin >= MIN_LOGIN_SIZE && sizeLogin <= MAX_LOGIN_SIZE)
	{
		return true;
	}
	return false;
}

bool isPasswordCorrect(string password)
{
	int sizePassword = size(password);

	if (sizePassword >= MIN_PASSWORD_SIZE)
	{
		return true;
	}
	return false;
}

bool isLoginExist(string login, vector <User>& users)
{
	for(int i = 0; i < users.size(); i++)
	{
		if (users[i].login == login)
		{
			return true;
		}
	}
	return false;
}
bool isAccountExist(string login, string password, vector <User>& users)
{
	for (int i = 0; i < users.size(); i++)
	{
		if (users[i].login == login && users[i].password == password)
		{
			return true;
		}
	}
	return false;
}
bool isAccountWaiting(int status, vector <User>& users)
{
	if (status == Status::WAITING)
	{
		return true;
	}
	return false;
}
bool isAccountBlocked(int status, vector <User>& users)
{
	if (status == Status::BLOCKED)
	{
		return true;
	}
	return false;
}

bool isTicketsRecordsExist(vector <Ticket>& tickets)
{
	if (tickets.size() == 0)
	{
		return true;
	}
	return false;
}
bool isTypeOfTransportExist(int type)
{
	if (type < MIN_TYPE_OF_TRANSPORT || type > MAX_TYPE_OF_TRANSPORT)
	{
		return true;
	}
	return false;
}

bool isMonthExist(int month)
{
	if ( month < MIN_MONTH || month > MAX_MONTH)
	{
		return true;
	}
	return false;
}

bool isYearExist(int year)
{
	if (year < MIN_YEAR || year > MAX_YEAR)
	{
		return true;
	}
	return false;
}

bool isCostOfTicketExist(double costOfTicket)
{
	if (costOfTicket <= MIN_COST_OF_TICKET )
	{
		return true;
	}
	return false;
}

bool isNegativeValue(int value)
{
	if (value < MIN_VALUE)
	{
		return true;
	}
	return false;
}

bool isCorrectValue(int value)
{
	while (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		return true;
	}
	return false;
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
void printTransportType(int typeOfTransport)
{
	switch (typeOfTransport)
	{
	case Transport::BUS: cout << BUS_TEXT;
		break;

	case Transport::TRAM: cout << TRAM_TEXT;
		break;

	case Transport::TROLLEYBUS: cout << TROLLEYBUS_TEXT;
		break;

	case Transport::TRAIN: cout << TRAIN_TEXT;
		break;

	case Transport::PLANE: cout << PLANE_TEXT;
		break;

	case Transport::SHIP: cout << SHIP_TEXT;
		break;
	}
}

string transportTypeToString(int typeOfTransport)
{
	switch (typeOfTransport)
	{
	case Transport::BUS: return BUS_TEXT;

	case Transport::TRAM: return TRAM_TEXT;

	case Transport::TROLLEYBUS: return TROLLEYBUS_TEXT;

	case Transport::TRAIN: return TRAIN_TEXT;

	case Transport::PLANE: return PLANE_TEXT;

	case Transport::SHIP: return SHIP_TEXT;
	}
}
