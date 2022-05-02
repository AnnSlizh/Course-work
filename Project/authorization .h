#pragma once
#include <string>
#include "constants.h"
#include "validation.h"
#include "datastructs.h"
#include "menu.h"
#include "md5.h"

void registerNewUser(vector <User>& users);
void signInAccount(vector <User>& users, vector <Ticket>& tickets);