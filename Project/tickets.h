#pragma once
#include <algorithm>
#include "constants.h"
#include "menu.h"
#include "datastructs.h"
#include "validation.h"

using namespace std;

double calculateTotalIncome(vector <Ticket>& tickets);
void viewTopOfSoldTickets(vector <Ticket>& tickets, int month);
bool compareBySoldTickets(Ticket& a, Ticket& b);
bool compareByTypeOfTransport(Ticket& a, Ticket& b);
bool compareByCostOfTicket(Ticket& a, Ticket& b);
bool compareByYear(Ticket& a, Ticket& b);
bool isMonthExist(int month);
void addNewTicketNote(vector <Ticket>& tickets);