#include <vector>
#include <fstream>
#include "fileio.h"
#include "constants.h"

void readUsersFromFile(vector <User>& users)
{
	fstream file;
	file.open(FILE_NAME, ios::in);
	if (!file.is_open())
	{

		file.open(FILE_NAME, ios::out);

		User adminTemp;

		adminTemp.login = MAIN_ADMIN_LOGIN;
		adminTemp.password = MAIN_ADMIN_PASSWORD;
		adminTemp.role = Role::MAIN_ADMIN;
		adminTemp.status = Status::ACTIVE;
		
		file << adminTemp.login << " " << adminTemp.password << " " << adminTemp.role << " " << adminTemp.status;

		users.push_back(adminTemp);

		file.close();
	}
	else
	{
		User userTemp;

		while (!file.eof())
		{
			int role;
			int status;
			file >> userTemp.login >> userTemp.password;
			file >> role >> status;

			userTemp.role = static_cast<Role>(role);
			userTemp.status = static_cast<Status>(status);

			users.push_back(userTemp);
		}
	}
	file.close();
}