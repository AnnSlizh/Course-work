#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include "datastructs.h"
#include "fileio.h"
#include "authorization .h"
#include "tickets.h"

using namespace std;

void authorizationMenu();
void menuOfAuthorization(vector <User>& users, vector <Ticket>& tickets);
void userMode(User userAccount, vector <User>& users, vector <Ticket>& tickets);
void adminMode(User userAccount, vector <User>& users, vector <Ticket>& tickets);
void manageTicketRecords(vector <Ticket>& tickets);
void addNewAccount(vector <User>& users, User userAccount);
void manageAccounts(User userAccount, vector <User>& users);
void manageApplication(vector <User>& users);
void acceptAplication(vector <User>& users);
void deleteAccount(vector <User>& users, int idOfAccount);
void viewAccounts(vector <User>& users);
void editAccount(vector <User>& users, User userAccount);
