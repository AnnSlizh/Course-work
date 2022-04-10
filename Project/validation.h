#pragma once
#include <string>
#include "datastructs.h"

using namespace std;

bool isLoginCorrect(string login);
bool isLoginExist(string login, vector <User>& users);
bool isMonthExist(int month);
bool isYearExist(int year);
bool isCostOfTicketExist(double costOfTicket);
bool isSoldTicketNegative(int soldTickets);
//bool isPasswordExist(string password, vector <User>& users);