#pragma once
#include <string>
#include "datastructs.h"

using namespace std;

bool isLoginCorrect(string login);
bool isLoginExist(string login, vector <User>& users);
bool isPasswordExist(string password, vector <User>& users);