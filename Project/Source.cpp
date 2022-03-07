#include <iostream>
#include <stdio.h>
#include <vector>
#include "datastructs.h"
#include "fileio.h"

using namespace std;

int main()
{
	vector <User> users;
	readUsersFromFile(users);
	cout << users.size();
	cout << endl;
	for (int i = 0; i < users.size(); i++)
	{
		cout << users[i].login << " " << users[i].password << " " << users[i].role << " " << users[i].status;
	}
	
}