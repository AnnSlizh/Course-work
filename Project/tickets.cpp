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

	cout << ADDING_NEW_TICKET_NOTE_TEXT << endl;

	cout << BUS_TEXT << endl << TRAM_TEXT << endl << TROLLEYBUS_TEXT << endl;
	cout << TRAIN_TEXT << endl << PLANE_TEXT << endl << SHIP_TEXT << endl;
	
	int digit;

	cout << ENTER_TYPE_OF_TRANSPORT_TEXT;
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
		cin >> digit;
	}

	cout << ENTER_MONTH_OF_SALE_TEXT;
	cin >> newTicketNote.month;

	while (isMonthExist(newTicketNote.month) == true)
	{
		cout << ENTER_CORRECT_MONTH_TEXT;
		cin >> newTicketNote.month;
	}

	cout << ENTER_YEAR_OF_SALES_TEXT;
	cin >> newTicketNote.year;

	while (isYearExist(newTicketNote.year) == true)
	{
		cout << ENTER_COORECT_YEAR_TEXT;
		cin >> newTicketNote.year;
	}


	cout << ENTER_COST_TICKET_TEXT;
	cin >> newTicketNote.costOfTicket;

	while (isCostOfTicketExist(newTicketNote.costOfTicket) == true)
	{
		cout << NOT_COORECT_COST_OF_TIKCET_TEXT << endl << ENTER_COST_TICKET_TEXT;
		cin >> newTicketNote.costOfTicket;
	}

	cout << ENTER_NUMBER_OF_SALE_TICKETS_TEXT;
	cin >> newTicketNote.soldTickets;

	while (isSoldTicketNegative(newTicketNote.soldTickets))
	{
		cout << NOT_COORECT_SALE_TICKETS_TEXT << endl << ENTER_NUMBER_OF_SALE_TICKETS_TEXT;
		cin >> newTicketNote.soldTickets;
	}

	tickets.push_back(newTicketNote);

	cout << TICKET_NOTE_ADDED_TEXT << endl;
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
