#pragma once
#include <string>


using namespace std;

//File names
const string FILE_NAME = "Users.txt";

//Main admin settings
const string MAIN_ADMIN_LOGIN = "admin";
const string MAIN_ADMIN_PASSWORD = "admin";

//Authorization menu
const string SIGN_IN_TEXT = "1) Войти";
const string SIGN_UP_TEXT = "2) Зарегистрировать новый аккаунт";
const string EXIT_OF_SYSTEM_TEXT = "3) Выйти из системы";

//
const string CREATING_ACCOUNT_MODE_TEXT = "Создание нового аккаунта в системе";
const string AUTHORIZATION_IN_SYSTEM_TEXT = "Авторизуйтесь в системе";
const string ENTER_LOGIN_TEXT = "Введите логин: ";
const string LOGIN_IS_EXIST_TEXT = "Аккаунт с таким логином уже существует! Пожалуйста, придумайте другой.";
const string LOGIN_NOT_CORRECT_TEXT = "Введенный логин не соответствует норме(не менее 4 символов)! Пожалуйста, придумайте другой.";
const string ENTER_PASSWORD_TEXT = "Введите пароль: ";
//const string PASSWORD_IS_EXIST_TEXT = "Аккаунт с таким паролем уже существует! Пожалуйста, придумайте другой.";
const string ACCOUNT_NOT_EXIT_TEXT = "Аккаунт с таким логином не существует! Пожалуйста, введите другой.";
const string WAITNG_STATUS_TEXT = "Ваша заявка не регистрацию еще не одобрена администратором!";
const string BLOCKED_STATUS_TEXT = "Ваш аккаунт заблокирован администратором!";

//User menu
const string USER_MODE_TEXT = "Вы находитесь в режиме пользователя!";
const string SYSTEM_TICKETS_SALES_TEXT = "1) Система продаж проездных билетов";
const string CHANGE_PASSWORD_TEXT = "2) Изменить пароль";
const string EXIT_OF_ACCOUNT_TEXT = "3) Выйти из аккаунта";
