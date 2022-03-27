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
const string ENTER_LOGIN_TEXT = "Введите логин: ";
const string ENTER_PASSWORD_TEXT = "Введите пароль: ";

//Registariton
const string CREATING_ACCOUNT_MODE_TEXT = "Создание нового аккаунта в системе";
const string AUTHORIZATION_IN_SYSTEM_TEXT = "Авторизуйтесь в системе";
const string LOGIN_IS_EXIST_TEXT = "Аккаунт с таким логином уже существует! Пожалуйста, придумайте другой.";
const string LOGIN_NOT_CORRECT_TEXT = "Введенный логин не соответствует норме(не менее 4 символов)! Пожалуйста, придумайте другой.";

//Sign in
const string ACCOUNT_NOT_EXIT_TEXT = "Аккаунт с таким логином не существует! Пожалуйста, введите другой.";
const string WAITNG_STATUS_TEXT = "Ваша заявка не регистрацию еще не одобрена администратором!";
const string BLOCKED_STATUS_TEXT = "Ваш аккаунт заблокирован администратором!";

//User menu
const string USER_MODE_TEXT = "Вы находитесь в режиме пользователя!";
const string SYSTEM_TICKETS_SALES_TEXT = "1) Система продаж проездных билетов";
const string USER_CHANGE_PASSWORD_TEXT = "2) Изменить пароль";
const string EXIT_OF_ACCOUNT_TEXT = "3) Выйти из аккаунта";
const string ENTER_PASSWORD_FOR_CHANGE_TEXT = "Для изменения пароля введите свой текущий пароль: ";
const string ENTER_NEW_PASSWORD_TEXT = "Введите новый пароль: ";
const string PACCWORD_NOT_CORRECT_TEXT = "Некорректный ввод пароля! Пожалуйста, повторите попытку.";

//Admin menu
const string MAIN_ADMIN_MODE_TEXT = "Вы находитесь в режиме главного администратора!";
const string ADMIN_MODE_TEXT = "Вы находитесь в режиме администратора!";
const string ACCOUNT_MANAGEMENT_TEXT = "2) Управление аккаунтами";
const string ADMIN_CHANGE_PASSWORD_TEXT = "3) Изменить пароль";
const string EXIT_FROM_ACCOUNT_TEXT = "4) Выйти из аккаунта";

//New account settings

const string ENTER_ROLE_OF_ACCOUNT_TEXT = "Введите роль: ";
const string ROLE_ADMIN_TEXT = "1) Администратор";
const string ROLE_USER_TEXT = "2) Пользователь";
const string ACCOUNT_ADDED_TEXT = "Новый аккаунт добавлен!";

//Accounts manage
const string ACCOUNT_MANAGEMENT_MODE_TEXT = "Модуль управления аккаунтами системы";
const string VIEW_ACCOUNTS_TEXT = "1) Просмотр аккаунтов";
const string ADD_NEW_ACCOUNT_TEXT = "2) Добавить новый аккаунт";
const string ACCOUNTS_SETTINGS_TEXT = "3) Редактирование аккаунтов";
const string DELETE_ACCOUNT_TEXT = "4) Удаление аккаунтов";
const string VIEW_APLICATIONS_TEXT = "5) Просмотр запросов на регистрацию";
const string RETURN_BACK_TEXT = "6) Назад";

//Application settings
const string ACCEPT_APPLICATION_TEXT = "1) Принять заявку";
const string BLOCKED_APPLICATION_TEXT = "2) Отклонить заявку";
const string ENTER_NUMBER_OF_APPLICATION = "Введите номер заявки: ";
const string VALIDATE_DELATION_OF_APPLICATION_TEXT = "Вы действительно хотите отклонить заявку на регистрацию пользователя?";
const string VALIDATE_ACCEPTANE_OF_APPLICATION_TEXT = "Вы действительно хотите принять заявку на регистрацию пользователя?";
const string YES_TEXT = "1) Да";
const string NOT_TEXT = "2) Нет";
