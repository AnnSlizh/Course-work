#pragma once
#include <string>
#include "datastructs.h"
#include "constants.h"

using namespace std;

bool isLoginCorrect(string login);
bool isLoginExist(string login, vector <User>& users);
bool isPasswordCorrect(string login, string password, vector <User>& users);
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
void transportToString(int typeOfTransport);

