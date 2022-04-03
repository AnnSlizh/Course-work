#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include "datastructs.h"
#include "fileio.h"
#include "authorization .h"

using namespace std;

void authorizationMenu();
void menuOfAuthorization(vector <User>& users);
void userMode(vector <User>& users);
void adminMode(vector <User>& users);
void addNewAccount(vector <User>& users);
void manageAccounts(vector <User>& users);
void manageApplication(vector <User>& users);
void acceptAplication(vector <User>& users);
void blockedApplication(vector <User>& users);
void viewAccounts(vector <User>& users);
void roleToString(int role);
void statusToString(int status);
void editAccount(vector <User>& users);