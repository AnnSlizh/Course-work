#include "validation.h"

const int MIN_LOGIN_SIZE = 3;
const int MAX_LOGIN_SIZE = 20;

bool isLoginCorrect(string login)
{
	int sizeLogin = size(login);

	if (sizeLogin > MIN_LOGIN_SIZE && sizeLogin < MAX_LOGIN_SIZE)
	{
		return true;
	}
	return false;
}