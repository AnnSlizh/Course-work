#include "tickets.h"

const double startingTotalIncome = 0;
const int EDIT_RECORD = 1;
const int RETURN_BACK = 2;

void serchTicketRecord(vector <Ticket>& tickets)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		viewTicketsRecords(tickets);

		cout << endl << SEARCH_BY_YEAR_TEXT << endl << SEARCH_BY_TYPE_OF_TRANSPORT_TEXT << endl;
		cout << SEARCH_BY_SOLD_TICKETS_TEXT << endl << FOUR_TEXT << RETURN_BACK_TEXT << endl;

		int typeOfTransport;
		int counter = 0;
		
		switch (_getch())
		{
		case '1': system("CLS");
			int minYear, maxYear;

			cout << ENTER_MIN_VALUE_OF_YEAR_TEXT; cin >> minYear;
			cout << ENTER_MAX_VALUE_OF_YEAR_TEXT; cin >> maxYear;

			while (true)
			{
				if (isCorrectValue(minYear) || isCorrectValue(maxYear))
				{
					cout << ENTER_COORECT_YEAR_TEXT << endl;
					cout << ENTER_MIN_VALUE_OF_YEAR_TEXT; cin >> minYear;
					cout << ENTER_MAX_VALUE_OF_YEAR_TEXT; cin >> maxYear;
				}
				else if (isYearExist(minYear) || isYearExist(maxYear))
				{
					cout << ENTER_COORECT_YEAR_TEXT << endl;
					cout << ENTER_MIN_VALUE_OF_YEAR_TEXT; cin >> minYear;
					cout << ENTER_MAX_VALUE_OF_YEAR_TEXT; cin >> maxYear;
				}
				else break;
			}

			system("CLS");
			cout << INFORMATION_OF_SEARCH_BY_YEAR_TEXT << minYear << TO_TEXT << maxYear << YEAR_TEXT << endl << endl;

			cout << TICKET_NUMBER_TEXT << setw(20) << TYPE_OF_TRANSPORT_TEXT << setw(10) << MONTH_OF_SALES_TEXT << setw(10);
			cout << YEAR_OF_SALES_TEXT << setw(18) << COST_OF_TICKET_TEXT << setw(25) << NUMBER_OF_SALE_TICKETS_TEXT << endl;
			cout << BORDER_OF_TICKETS_TABLE_TEXT << endl;

			for (int i = 0; i < tickets.size(); i++)
			{
				if (tickets[i].year >= minYear && tickets[i].year <= maxYear)
				{
					typeOfTransport = tickets[i].type;

					cout << i << setw(18);
					printTransportType(typeOfTransport);
					cout << setw(10) << tickets[i].month << setw(12) << tickets[i].year << setw(15);
					cout << tickets[i].costOfTicket << setw(15) << tickets[i].soldTickets << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				system("CLS");
				cout << NOT_INDORMATION_OF_SEARCH_TEXT << endl;
			}

			system("pause");
			break;

		case '2':  system("CLS");

			cout << ZERO_TEXT << BUS_TEXT << endl << ONE_TEXT << TRAM_TEXT << endl;
			cout << TWO_TEXT << TROLLEYBUS_TEXT << endl << THREE_TEXT << TRAIN_TEXT << endl;
			cout << FOUR_TEXT << PLANE_TEXT << endl << FIFE_TEXT << SHIP_TEXT << endl;

			cout << ENTER_TYPE_OF_TRANSPORT_TEXT; cin >> typeOfTransport;

			while (isCorrectValue(typeOfTransport) || isTypeOfTransportExist(typeOfTransport))
			{
				cout << NOT_CORRECT_TYPE_OF_TRANSPORT_TEXT << endl;
				cout << ENTER_TYPE_OF_TRANSPORT_TEXT;
				cin >> typeOfTransport;
			}

			system("CLS");
			cout << INFORMATION_OF_SEARCH_BY_TYPE_OF_TRANSPORT_TEXT;
			printTransportType(typeOfTransport);
			cout << endl << endl;

			cout << TICKET_NUMBER_TEXT << setw(20) << TYPE_OF_TRANSPORT_TEXT << setw(10) << MONTH_OF_SALES_TEXT << setw(10);
			cout << YEAR_OF_SALES_TEXT << setw(18) << COST_OF_TICKET_TEXT << setw(25) << NUMBER_OF_SALE_TICKETS_TEXT << endl;
			cout << BORDER_OF_TICKETS_TABLE_TEXT << endl;

			
			for (int i = 0; i < tickets.size(); i++)
			{
				if (tickets[i].type == typeOfTransport)
				{
					cout << i << setw(18);
					printTransportType(typeOfTransport);
					cout << setw(10) << tickets[i].month << setw(12) << tickets[i].year << setw(15);
					cout << tickets[i].costOfTicket << setw(15) << tickets[i].soldTickets << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				system("CLS"); 
				cout << NOT_INDORMATION_OF_SEARCH_TEXT << endl;
			}
		
			system("pause");
			break;

		case '3': system("CLS");
			int minSoldTickets, maxSoldTickets;

			cout << ENTER_MIN_VALUE_OF_SOlD_TICKETS_TEXT; cin >> minSoldTickets;
			cout << ENTER_MAX_VALUE_OF_SOlD_TICKETS_TEXT; cin >> maxSoldTickets;

			while (true)
			{
				if (isCorrectValue(minSoldTickets) || isCorrectValue(maxSoldTickets))
				{
					cout << NOT_COORECT_SALE_TICKETS_TEXT << endl;
					cout << ENTER_MIN_VALUE_OF_SOlD_TICKETS_TEXT; cin >> minSoldTickets;
					cout << ENTER_MAX_VALUE_OF_SOlD_TICKETS_TEXT; cin >> maxSoldTickets;
				}
				else if (isNegativeValue(minSoldTickets) || isNegativeValue(maxSoldTickets))
				{
					cout << NOT_COORECT_SALE_TICKETS_TEXT << endl;
					cout << ENTER_MIN_VALUE_OF_SOlD_TICKETS_TEXT; cin >> minSoldTickets;
					cout << ENTER_MAX_VALUE_OF_SOlD_TICKETS_TEXT; cin >> maxSoldTickets;
				}
				else break;
			}

			system("CLS");
			cout << INFORMATION_OF_SEARCH_BY_SOLD_TICKETS_TEXT << minSoldTickets << TO_TEXT << maxSoldTickets << endl << endl;

			cout << TICKET_NUMBER_TEXT << setw(20) << TYPE_OF_TRANSPORT_TEXT << setw(10) << MONTH_OF_SALES_TEXT << setw(10);
			cout << YEAR_OF_SALES_TEXT << setw(18) << COST_OF_TICKET_TEXT << setw(25) << NUMBER_OF_SALE_TICKETS_TEXT << endl;
			cout << BORDER_OF_TICKETS_TABLE_TEXT << endl;

			for (int i = 0; i < tickets.size(); i++)
			{
				if (tickets[i].soldTickets >= minSoldTickets && tickets[i].soldTickets <= maxSoldTickets)
				{
					typeOfTransport = tickets[i].type;

					cout << i << setw(18);
					printTransportType(typeOfTransport);
					cout << setw(10) << tickets[i].month << setw(12) << tickets[i].year << setw(15);
					cout << tickets[i].costOfTicket << setw(15) << tickets[i].soldTickets << endl;
					counter++;
				}
			}
			if (counter == 0)
			{
				system("CLS");
				cout << NOT_INDORMATION_OF_SEARCH_TEXT << endl;
			}

			system("pause");
			break;

		case '4': flag = false;
			break;
		}
	}
}

void sortTicketsRecords(vector <Ticket>& tickets)
{
	bool flag = true;
	while (flag)
	{
		system("CLS");
		if (tickets.size() == 0)
		{
			cout << TICKETS_NOT_EXIST_TEXT << endl;
			system("pause");
			break;
		}
		else
		{
			viewTicketsRecords(tickets);

			cout << endl << SORT_BY_TYPE_OF_TRANSPORT_TEXT << endl << SORT_BY_COST_OF_TICKET_TEXT << endl;
			cout << SORT_BY_YEAR_TEXT << endl << SEARCH_TEXT << endl << CALCULATE_TOTAL_INCOME_OF_TICKETS_TEXT << endl;
			cout << SIX_TEXT << RETURN_BACK_TEXT << endl;

			switch (_getch())
			{
			case '1': sort(tickets.begin(), tickets.end(), compareByTypeOfTransport);
				break;

			case '2':  sort(tickets.begin(), tickets.end(), compareByCostOfTicket);
				break;

			case '3': sort(tickets.begin(), tickets.end(), compareByYear);
				break;

			case '4': serchTicketRecord(tickets);
				break;

			case '5': system("CLS");

				int month, year;
				int counter;
				counter = 0;

				cout << ENTER_MONTH_OF_SALE_TEXT;
				cin >> month;

				while (isCorrectValue(month) || isMonthExist(month))
				{
					cout << ENTER_CORRECT_MONTH_TEXT;
					cin >> month;
				}

				cout << ENTER_YEAR_OF_SALES_TEXT;
				cin >> year;

				while (isCorrectValue(year) || isYearExist(year))
				{
					cout << ENTER_COORECT_YEAR_TEXT;
					cin >> year;
				}
				cout << endl;

				if (calculateTotalIncome(tickets, month, year) == 0)
				{
					cout << NOT_SOLD_TICKETS_IN_MONTH_TEXT << endl;
				}
				else
				{
					viewTopOfSoldTickets(tickets, month, year);
					cout << endl << TOTAL_INCOME_OF_TICKETS_TEXT << calculateTotalIncome(tickets, month, year) << endl;
				}

				system("pause");
				break;

			case '6': flag = false;
				break;
			}
		}
	}
}

void addNewTicketRecord(vector <Ticket>& tickets)
{
	Ticket newTicketNote;

	cout << ADDING_NEW_TICKET_RECORD_TEXT << endl;

	cout << ZERO_TEXT << BUS_TEXT << endl << ONE_TEXT << TRAM_TEXT << endl;
	cout << TWO_TEXT << TROLLEYBUS_TEXT << endl << THREE_TEXT << TRAIN_TEXT << endl;
	cout << FOUR_TEXT << PLANE_TEXT << endl << FIFE_TEXT << SHIP_TEXT << endl;

	int digit;

	cout << ENTER_TYPE_OF_TRANSPORT_TEXT;
	cin >> digit;

	while (isCorrectValue(digit) || isTypeOfTransportExist(digit))
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

	while (isCorrectValue(newTicketNote.month) || isMonthExist(newTicketNote.month))
	{
		cout << ENTER_CORRECT_MONTH_TEXT;
		cin >> newTicketNote.month;
	}

	cout << ENTER_YEAR_OF_SALES_TEXT;
	cin >> newTicketNote.year;

	while (isCorrectValue(newTicketNote.year) || isYearExist(newTicketNote.year))
	{
		cout << ENTER_COORECT_YEAR_TEXT;
		cin >> newTicketNote.year;
	}

	cout << ENTER_COST_TICKET_TEXT;
	cin >> newTicketNote.costOfTicket;

	while (isCorrectValue(newTicketNote.costOfTicket) || isCostOfTicketExist(newTicketNote.costOfTicket))
	{
		cout << NOT_COORECT_COST_OF_TIKCET_TEXT << endl << ENTER_COST_TICKET_TEXT;
		cin >> newTicketNote.costOfTicket;
	}

	cout << ENTER_NUMBER_OF_SALE_TICKETS_TEXT;
	cin >> newTicketNote.soldTickets;

	while (isCorrectValue(newTicketNote.soldTickets) || isNegativeValue(newTicketNote.soldTickets))
	{
		cout << NOT_COORECT_SALE_TICKETS_TEXT << endl << ENTER_NUMBER_OF_SALE_TICKETS_TEXT;
		cin >> newTicketNote.soldTickets;
	}

	tickets.push_back(newTicketNote);
	cout << TICKET_RECORD_ADDED_TEXT << endl;
}

void editTicketRecord(vector <Ticket>& tickets)
{
	int numberOfRecord;

	bool flag = true;
	while (flag)
	{
		system("CLS");
		if (tickets.size() == 0)
		{
			cout << TICKETS_NOT_EXIST_TEXT << endl;
			system("pause");
			break;
		}
	
		viewTicketsRecords(tickets);
		
		int digit;
		cout << endl << EDIT_RECORD_TEXT << endl << TWO_TEXT << RETURN_BACK_TEXT << endl;
		cin >> digit;

		if (digit == EDIT_RECORD)
		{
			cout << endl << ENTER_NUMBER_OF_RECORD_TEXT;
			cin >> numberOfRecord;
		}
		else if (digit == RETURN_BACK)
		{
			break;
		}
		
		while (isCorrectValue(numberOfRecord) || isNegativeValue(numberOfRecord) || numberOfRecord >= tickets.size())
		{
			cout << BEYOND_THE_VECTOR_OF_TICKETS_TEXT << endl;
			cout << ENTER_NUMBER_OF_RECORD_TEXT;
			cin >> numberOfRecord;
		}

		system("CLS");
		viewOneTicketRecord(tickets, numberOfRecord);

		cout << endl << CHANGE_PARAMETERS_TEXT << endl;
		cout << CHANGE_TYPE_OF_TRANSPORT_TEXT << endl << CHANGE_MONTH_TEXT << endl << CHANGE_YEAR_TEXT << endl;
		cout << CHANGE_COST_OF_TICKET_TEXT << endl << CHANGE_SOLD_TICKETS_TEXT << endl;
		cout << SIX_TEXT << RETURN_BACK_TEXT << endl;

		switch (_getch())
		{
		case '1': system("CLS");
			viewOneTicketRecord(tickets, numberOfRecord);

			cout << endl << ZERO_TEXT << BUS_TEXT << endl << ONE_TEXT << TRAM_TEXT << endl;
			cout << TWO_TEXT << TROLLEYBUS_TEXT << endl << THREE_TEXT << TRAIN_TEXT << endl;
			cout << FOUR_TEXT << PLANE_TEXT << endl << FIFE_TEXT << SHIP_TEXT << endl;

			int newTypeOfTransport;

			cout << ENTER_TYPE_OF_TRANSPORT_TEXT;
			cin >> newTypeOfTransport;

			while (isCorrectValue(newTypeOfTransport) || isTypeOfTransportExist(newTypeOfTransport))
			{
				cout << NOT_CORRECT_TYPE_OF_TRANSPORT_TEXT << endl;
				cout << ENTER_TYPE_OF_TRANSPORT_TEXT;
				cin >> newTypeOfTransport;
			}

			switch (newTypeOfTransport)
			{
			case 0: tickets[numberOfRecord].type = Transport::BUS;
				break;

			case 1: tickets[numberOfRecord].type = Transport::TRAM;
				break;

			case 2: tickets[numberOfRecord].type = Transport::TROLLEYBUS;
				break;

			case 3: tickets[numberOfRecord].type = Transport::TRAIN;
				break;

			case 4: tickets[numberOfRecord].type = Transport::PLANE;
				break;

			case 5: tickets[numberOfRecord].type = Transport::SHIP;
				break;
			}

			system("CLS");
			cout << EDITING_IS_OVER_TEXT << endl;

			system("pause");
			break;

		case '2':  system("CLS");
			viewOneTicketRecord(tickets, numberOfRecord);

			int newMonth;

			cout << endl << ENTER_MONTH_OF_SALE_TEXT;
			cin >> newMonth;
			
			while (isCorrectValue(newMonth) || isMonthExist(newMonth))
			{
				cout << ENTER_CORRECT_MONTH_TEXT;
				cin >> newMonth;
			}

			tickets[numberOfRecord].month = newMonth;

			system("CLS");
			cout << EDITING_IS_OVER_TEXT << endl;

			system("pause");
			break;

		case '3': system("CLS");
			viewOneTicketRecord(tickets, numberOfRecord);

			int newYear;

			cout << endl << ENTER_YEAR_OF_SALES_TEXT;
			cin >> newYear;

			while (isCorrectValue(newYear) || isYearExist(newYear))
			{
				cout << ENTER_CORRECT_MONTH_TEXT;
				cin >> newYear;
			}

			tickets[numberOfRecord].year = newYear;

			system("CLS");
			cout << EDITING_IS_OVER_TEXT << endl;

			system("pause");
			break;

		case '4': system("CLS");
			viewOneTicketRecord(tickets, numberOfRecord);

			int newCostOfTicket;

			cout << endl << ENTER_COST_TICKET_TEXT;
			cin >> newCostOfTicket;

			while (isCorrectValue(newCostOfTicket) || isCostOfTicketExist(newCostOfTicket))
			{
				cout << ENTER_CORRECT_MONTH_TEXT;
				cin >> newCostOfTicket;;
			}

			tickets[numberOfRecord].costOfTicket = newCostOfTicket;

			system("CLS");
			cout << EDITING_IS_OVER_TEXT << endl;

			system("pause");
			break;

		case '5': system("CLS");
			viewOneTicketRecord(tickets, numberOfRecord);

			int newSoldTickets;

			cout << endl << ENTER_NUMBER_OF_SALE_TICKETS_TEXT;
			cin >> newSoldTickets;

			while (isCorrectValue(newSoldTickets) || isNegativeValue(newSoldTickets))
			{
				cout << ENTER_CORRECT_MONTH_TEXT;
				cin >> newSoldTickets;
			}

			tickets[numberOfRecord].soldTickets = newSoldTickets;

			system("CLS");
			cout << EDITING_IS_OVER_TEXT << endl;

			system("pause");
			break;

		case '6': break;
		}
	}
}

double calculateTotalIncome(vector <Ticket>& tickets, int month, int year) // Income - доход
{
	double totalIncome = startingTotalIncome;

	double costOfTicket;
	int numberOfSoldTickets;

	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i].month == month && tickets[i].year == year)
		{
			costOfTicket = tickets[i].costOfTicket;
			numberOfSoldTickets = tickets[i].soldTickets;

			totalIncome = totalIncome + (costOfTicket * numberOfSoldTickets);
		}
	}
	
	return totalIncome;
}

void viewTopOfSoldTickets(vector <Ticket>& tickets, int month, int year)
{
	sort(tickets.begin(), tickets.end(), compareBySoldTickets);

	cout << TICKET_NUMBER_TEXT << setw(20) << TYPE_OF_TRANSPORT_TEXT << setw(10) << MONTH_OF_SALES_TEXT << setw(10);
	cout << YEAR_OF_SALES_TEXT << setw(18) << COST_OF_TICKET_TEXT << setw(25) << NUMBER_OF_SALE_TICKETS_TEXT << endl;
	cout << BORDER_OF_TICKETS_TABLE_TEXT << endl;

	for (int i = 0; i < tickets.size(); i++)
	{
		if (tickets[i].month == month && tickets[i].year == year)
		{
			cout << i << setw(18);
			printTransportType(tickets[i].type);
			cout << setw(10) << tickets[i].month << setw(12) << tickets[i].year << setw(15);
			cout << tickets[i].costOfTicket << setw(15) << tickets[i].soldTickets << endl;
		}
	}
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

void viewTicketsRecords(vector <Ticket>& tickets)
{
	cout << TICKET_NUMBER_TEXT << setw(20) << TYPE_OF_TRANSPORT_TEXT << setw(10) << MONTH_OF_SALES_TEXT << setw(10);
	cout << YEAR_OF_SALES_TEXT << setw(18) << COST_OF_TICKET_TEXT << setw(25) << NUMBER_OF_SALE_TICKETS_TEXT << endl;
	cout << BORDER_OF_TICKETS_TABLE_TEXT << endl;

	for (int i = 0; i < tickets.size(); i++)
	{
		int typeOfTransport;
		typeOfTransport = tickets[i].type;

		cout << i << setw(18);
		printTransportType(typeOfTransport);
		cout << setw(10) << tickets[i].month << setw(12) << tickets[i].year << setw(15);
		cout << tickets[i].costOfTicket << setw(15) << tickets[i].soldTickets << endl;
	}
}

void viewOneTicketRecord(vector <Ticket>& tickets, int numberOfRecord)
{
	cout << TICKET_NUMBER_TEXT << setw(20) << TYPE_OF_TRANSPORT_TEXT << setw(10) << MONTH_OF_SALES_TEXT << setw(10);
	cout << YEAR_OF_SALES_TEXT << setw(18) << COST_OF_TICKET_TEXT << setw(25) << NUMBER_OF_SALE_TICKETS_TEXT << endl;
	cout << BORDER_OF_TICKETS_TABLE_TEXT << endl;

	cout << numberOfRecord << setw(18); 
	printTransportType(tickets[numberOfRecord].type);
	cout << setw(10) << tickets[numberOfRecord].month << setw(12) << tickets[numberOfRecord].year << setw(15);
	cout << tickets[numberOfRecord].costOfTicket << setw(15) << tickets[numberOfRecord].soldTickets << endl;
}

bool compareBySoldTickets(Ticket& a, Ticket& b)
{
	return a.soldTickets > b.soldTickets;
}

bool compareByTypeOfTransport(Ticket& a, Ticket& b)
{
	return transportTypeToString(a.type) < transportTypeToString(b.type);
}

bool compareByCostOfTicket(Ticket& a, Ticket& b)
{
	return a.costOfTicket > b.costOfTicket;
}

bool compareByYear(Ticket& a, Ticket& b)
{
	if (a.year == b.year)
	{
		return a.month > b.month;
	}
	else return a.year > b.year;
}
