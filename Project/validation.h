#pragma once
#include <string>
#include <conio.h>
#include "datastructs.h"
#include "constants.h"

using namespace std;

bool isLoginCorrect(string login);
bool isPasswordCorrect(string password);
bool isLoginExist(string login, vector <User>& users);
bool isAccountExist(string login, string password, vector <User>& users);
bool isAccountWaiting(int status, vector <User>& users);
bool isAccountBlocked(int status, vector <User>& users);
bool isTypeOfTransportExist(int type);
bool isMonthExist(int month);
bool isYearExist(int year);
bool isCostOfTicketExist(double costOfTicket);
bool isSoldTicketNegative(int soldTickets);
bool isCorrectValue(int value);
void roleToString(int role);
void statusToString(int status);
void printTransportType(int typeOfTransport);
string transportTypeToString(int typeOfTransport);

