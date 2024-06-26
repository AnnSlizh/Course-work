#pragma once
#include <algorithm>
#include <conio.h>
#include <iomanip>
#include "constants.h"
#include "menu.h"
#include "datastructs.h"
#include "validation.h"

using namespace std;

void viewTicketsRecords(vector <Ticket>& tickets);
void viewOneTicketRecord(vector <Ticket>& tickets, int numberOfRecord);
void serchTicketRecord(vector <Ticket>& tickets);
void sortTicketsRecords(vector <Ticket>& tickets);
void addNewTicketRecord(vector <Ticket>& tickets);
void deleteTicketRecord(vector <Ticket>& tickets, int numberOfRecord);
void editTicketRecord(vector <Ticket>& tickets);
double calculateTotalIncome(vector <Ticket>& tickets, int month, int year);
void viewTopOfSoldTickets(vector <Ticket>& tickets, int month, int year);
bool compareBySoldTickets(Ticket& a, Ticket& b);
bool compareByTypeOfTransport(Ticket& a, Ticket& b);
bool compareByCostOfTicket(Ticket& a, Ticket& b);
bool compareByYear(Ticket& a, Ticket& b);


