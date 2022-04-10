#include "tickets.h"

const double startingTotalIncome = 0;

void viewTicketsRecords(vector <Ticket>& tickets)
{
	for (int i = 0; i < tickets.size(); i++)
	{
		cout << i << " " << tickets[i].type << " " << tickets[i].month << " " << tickets[i].year << " ";
		cout << tickets[i].costOfTicket << " " << tickets[i].soldTickets << endl;
	}
}

void sortTicketsRecords(vector <Ticket>& tickets)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		viewTicketsRecords(tickets);

		cout << SORT_BY_TYPE_OF_TRANSPORT_TEXT << endl << SORT_BY_COST_OF_TICKET_TEXT << endl; 
		cout << SORT_BY_YEAR_TEXT << endl << COME_BACK_TEXT << endl;

		switch (_getch())
		{
		case '1': sort(tickets.begin(), tickets.end(), compareByTypeOfTransport);
			break;

		case '2':  sort(tickets.begin(), tickets.end(), compareByCostOfTicket);
			break;

		case '3': sort(tickets.begin(), tickets.end(), compareByYear);
			break;
			
		case '4': flag = false;
			break;
		}
	}
}

void addNewTicketRecord(vector <Ticket>& tickets)
{
	Ticket newTicketNote;

	cout << ADDING_NEW_TICKET_RECORD_TEXT << endl;

	cout << ONE_TEXT << BUS_TEXT << endl << TWO_TEXT << TRAM_TEXT << endl;
	cout << THREE_TEXT << TROLLEYBUS_TEXT << endl << FOUR_TEXT << TRAIN_TEXT << endl;
	cout << FIFE_TEXT << PLANE_TEXT << endl << SIX_TEXT << SHIP_TEXT << endl;

	int digit;

	cout << ENTER_TYPE_OF_TRANSPORT_TEXT;
	cin >> digit;

	while (isTypeOfTransportExist(digit) == true)
	{
		cout << NOT_CORRECT_TYPE_OF_TRANSPORT_TEXT << endl;
		cout << ENTER_TYPE_OF_TRANSPORT_TEXT;
		cin >> digit;
	}

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

	cout << TICKET_RECORD_ADDED_TEXT << endl;
}

void deleteTicketRecord(vector <Ticket>& tickets, int numberOfRecord)
{
	int digit;
	cin >> digit;

	if (digit == 1) //yes
	{
		auto iter = tickets.cbegin();

		if (numberOfRecord == 0)
		{
			tickets.erase(iter);
		}
		else
		{
			tickets.erase(iter + numberOfRecord);
		}
		system("CLS");
		cout << RECORD_IS_DELETED_TEXT << endl;
		system("pause");
	}
	else if (digit == 2) return; //not
}

double calculateTotalIncome(vector <Ticket>& tickets, int month) // Income - доход
{
	while (isMonthExist(month) == true)
	{
		cout << ENTER_CORRECT_MONTH_TEXT;
		cin >> month;
	}

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
			cout << tickets[i].type << " " << tickets[i].month << " " << tickets[i].year << " ";
			cout << tickets[i].costOfTicket << " " << tickets[i].soldTickets << endl;
		}
	}
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

/*for (int i = 0; i < users.size(); i++)
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
*/
void transportToString(int typeOfTransport)
{
	switch (typeOfTransport)
	{
	case Transport::BUS:  cout << BUS_TEXT;
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