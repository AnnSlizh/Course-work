#include "tickets.h"

const double startingTotalIncome = 0;

double calculateTotalIncome(vector <Ticket>& tickets) // Income - доход
{
	int month;

	cout << "ent month: ";
	cin >> month;

	double totalIncome = startingTotalIncome;

	double costOfTicket;
	int numberOfSoldTickets;

	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i].month == month)
		{
			costOfTicket = tickets[i].costOfTicket;
			numberOfSoldTickets = tickets[i].soldTickets;

			totalIncome = totalIncome + (costOfTicket * numberOfSoldTickets);
		}
	}
	
	return totalIncome;
}

void viewTopOfSoldTickets(vector <Ticket>& tickets, int month)
{
	sort(tickets.begin(), tickets.end(), compareBySoldTickets);

	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i].month == month)
		{
			
			cout << tickets[i].type << endl;
		}
	}
}

void addNewTicketNote(vector <Ticket>& tickets)
{
	Ticket newTicketNote;
	int typeOfTransport;

	cout << ADD_NEW_ACCOUNT_TEXT << endl;
	
	cout << ENTER_LOGIN_TEXT;

	int digit;
	cin >> digit;

	switch (digit)
	{
	case 0: newTicketNote.type = Transport::BUS; 
		break;

	case 1: newTicketNote.type = Transport::TRAM;
		break;

	case 2: newTicketNote.type = Transport::TROLLEYBUS;
		break;

	case 3: newTicketNote.type = Transport::TRAIN;
		break;

	case 4: newTicketNote.type = Transport::PLANE;
		break;

	case 5: newTicketNote.type = Transport::SHIP;
		break;

	default: cout << "nepr";
	}
		
	

	bool flag = true;
	while (flag)
	{
		cout << ENTER_PASSWORD_TEXT;
		cin >> newTicketNote.month;

		if (isMonthExist(newTicketNote.month) == true)
		{
			cout << "net";
		}
		else flag = false;
	}
	
	cout << ENTER_PASSWORD_TEXT;
	cin >> newTicketNote.year;

	cout << ENTER_PASSWORD_TEXT;
	cin >> newTicketNote.costOfTicket;

	cout << ENTER_PASSWORD_TEXT;
	cin >> newTicketNote.soldTickets;

	tickets.push_back(newTicketNote);

	cout << ACCOUNT_ADDED_TEXT << endl;
}

bool compareBySoldTickets(Ticket& a, Ticket& b)
{
	return a.costOfTicket > b.soldTickets;
}

bool compareByTypeOfTransport(Ticket& a, Ticket& b)
{
	return a.type > b.type;
}

bool compareByCostOfTicket(Ticket& a, Ticket& b)
{
	return a.costOfTicket > b.costOfTicket;
}

bool compareByYear(Ticket& a, Ticket& b)
{
	return a.year > b.year;
}
