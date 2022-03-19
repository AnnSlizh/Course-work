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