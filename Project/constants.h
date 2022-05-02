#pragma once
#include <string>

using namespace std;

//File names
const string USERS_FILE_NAME = "Users.txt";
const string TICKETS_FILE_NAME = "Tickets.txt";

//File not exist
const string TICKETS_NOT_EXIST_TEXT = "Нет сведений о продажах проездных билетов!";

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
const string PASSWORD_NOT_CORRECT_TEXT = "Введенный пароль не соответствует норме(не менее 6 символов)! Пожалуйста, придумайте другой.";
const string APPLICATION_IS_SENT_TEXT = "Ваша заявка на регистрацию отправлена!";
const string SYSTEM_ACCESS_TEXT = "Система будет доступна после одобрения вашей заявки администратором";

//Sign in
const string ACCOUNT_NOT_EXIT_TEXT = "Аккаунт не существует! Пожалуйста, проверьте логин и пароль.";
const string WAITNG_STATUS_TEXT = "Ваша заявка не регистрацию еще не одобрена администратором!";
const string BLOCKED_STATUS_TEXT = "Ваш аккаунт заблокирован администратором!";

//User menu
const string USER_MODE_TEXT = "Вы находитесь в режиме пользователя!";
const string SYSTEM_TICKETS_SALES_TEXT = "1) Система продаж проездных билетов";
const string USER_CHANGE_PASSWORD_TEXT = "2) Изменить пароль";
const string EXIT_FROM_ACCOUNT_TEXT = "Выйти из аккаунта";
const string ENTER_PASSWORD_FOR_CHANGE_TEXT = "Для изменения пароля введите свой текущий пароль: ";
const string ENTER_NEW_PASSWORD_TEXT = "Введите новый пароль: ";
const string PACCWORD_NOT_CORRECT_TEXT = "Некорректный ввод пароля! Пожалуйста, повторите попытку.";
const string PASSWORD_CHANGE_NOT_AVALIABLE_TEXT = "Неправильный пароль был введен трижды. Изменение пароля недоступно!";

//Admin menu
const string MAIN_ADMIN_MODE_TEXT = "Вы находитесь в режиме главного администратора!";
const string ADMIN_MODE_TEXT = "Вы находитесь в режиме администратора!";
const string ACCOUNT_MANAGEMENT_TEXT = "2) Управление аккаунтами";
const string ADMIN_CHANGE_PASSWORD_TEXT = "3) Изменить пароль";
const string VALIDATE_EXIT_FROME_ACCOUNT_TEXT = "Вы точно хотите выйти из аккаунта?";

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
const string RETURN_BACK_TEXT = "Назад";

//Accounts settings
const string CHOCE_ACTION_TEXT = "Выберите действие:";
const string CHANGE_ROLE_TEXT = "1) Изменить роль";
const string CHANGE_STATUS_TEXT = "2) Изменить статус";
const string ENTER_ID_OF_ACCOUNT_TEXT = "Введите ID аккаунта: ";
const string NOT_CHANGE_ROLE_MAIN_ADMIN_TEXT= "Вы не можете изменить роль главного администратора!";
const string NOT_CHANGE_STATUS_MAIN_ADMIN_TEXT = "Вы не можете изменить статус главного администратора!";
const string VALIDATE_DELATION_OF_ACCOUNT_TEXT = "Вы действительно хотите удалить аккаунт?";
const string ACOOUNT_IS_DELETED_TEXT = "Аккаунт удален!";
const string BEYOND_THE_VECTOR_OF_ACCOUNTS_TEXT = "Аккаунт с таким ID не существует! Пожалуйста, введите корректный ID";

//Application settings
const string ACCEPT_APPLICATION_TEXT = "1) Принять заявку";
const string BLOCKED_APPLICATION_TEXT = "2) Отклонить заявку";
const string NOT_APPLICATIONS_TEXT = "Нет заявок на регистрацию!";
const string ENTER_ID_OF_APPLICATION = "Введите ID заявки: ";
const string NOT_CORRECT_ID_TEXT = "Заявка с таким ID не существует! Пожалуйста, введите корректный ID";
const string VALIDATE_DELATION_OF_APPLICATION_TEXT = "Вы действительно хотите отклонить заявку на регистрацию пользователя?";
const string VALIDATE_ACCEPTANE_OF_APPLICATION_TEXT = "Вы действительно хотите принять заявку на регистрацию пользователя?";
const string YES_TEXT = "1) Да";
const string NOT_TEXT = "2) Нет";

//Enum structs text
const string ADMIN_TEXT = "Admin";
const string MAIN_ADMIN_TEXT = "Main admin";
const string USER_TEXT = "User";
const string ACTIVE_TEXT = "Active";
const string BLOCKED_TEXT = "Blocked";
const string WAITING_TEXT = "Waiting";

//Adding new ticket record
const string ADDING_NEW_TICKET_RECORD_TEXT = "Добавление новой записи проездных билетов в систему";
const string ENTER_TYPE_OF_TRANSPORT_TEXT = "Введите вид транспорта: ";
const string ENTER_MONTH_OF_SALE_TEXT = "Введите месяц продажи билетов [1 - 12]: ";
const string ENTER_YEAR_OF_SALES_TEXT = "Введите год продажи билетов [2000 - 2022]: ";
const string ENTER_COST_TICKET_TEXT = "Введите стоимость одного билета: ";
const string ENTER_NUMBER_OF_SALE_TICKETS_TEXT = "Введите количество проданных билетов: ";
const string BUS_TEXT = "Автобус";
const string TRAM_TEXT = "Трамвай";
const string TROLLEYBUS_TEXT = "Троллейбус";
const string TRAIN_TEXT = "Поезд";
const string PLANE_TEXT = "Самолет";
const string SHIP_TEXT = "Пароход";
const string NOT_CORRECT_TYPE_OF_TRANSPORT_TEXT = "Некорректный ввод вида транспорта! Пожалуйста, повторите попытку";
const string ENTER_CORRECT_MONTH_TEXT = "Пожалуйта, введите корректное [1 - 12] значение: ";
const string ENTER_COORECT_YEAR_TEXT = "Пожалуйста, введите корректное [2000 - 2022] значение: ";
const string NOT_COORECT_COST_OF_TIKCET_TEXT = "Некорректный ввод стоимости проездного билета! Пожалуйста, повторите попытку";
const string NOT_COORECT_SALE_TICKETS_TEXT = "Некорректный ввод количества проданных билетов! Пожалуйста, повторите попытку";
const string TICKET_RECORD_ADDED_TEXT = "Новая запись добавлена!";

//Tickets record settings
const string VIEW_TICKETS_RECORDS_TEXT = "1) Просмотр записей";
const string ADD_NEW_TICKET_RECORD_TEXT = "2) Добавить запись";
const string DELETE_TICKET_RECORD_TEXT = "3) Удалить запись";
const string CHANGE_TICKETS_RECORDS_TEXT = "4) Редактировать запись";
const string CALCULATE_TOTAL_INCOME_OF_TICKETS_TEXT = "5) Рассчитать общий доход от продаж билетов";
const string TOTAL_INCOME_OF_TICKETS_TEXT = "Общий доход от продажи билетов за месяц: ";
const string ENTER_NUMBER_OF_RECORD_TEXT = "Введите номер записи: ";
const string VALIDATE_DELATION_OF_RECORD_TEXT = "Вы действительно хотите удалить запись?";
const string RECORD_IS_DELETED_TEXT = "Запись удалена!";
const string BEYOND_THE_VECTOR_OF_TICKETS_TEXT = "Запись с таким номером не существует! Пожалуйста, введите корректный номер";
const string NOT_SOLD_TICKETS_IN_MONTH_TEXT = "Нет проданных проездных билетов в указанный месяц!";

//Editing tickets records
const string EDIT_RECORD_TEXT = "1) Выбрать запись";
const string CHANGE_PARAMETERS_TEXT = "Выберите параметр для изменения:";
const string CHANGE_TYPE_OF_TRANSPORT_TEXT = "1) Вид транспорта";
const string CHANGE_MONTH_TEXT = "2) Месяц продажи билетов";
const string CHANGE_YEAR_TEXT = "3) Год продажи билетов";
const string CHANGE_COST_OF_TICKET_TEXT = "4) Стоимость одного билета";
const string CHANGE_SOLD_TICKETS_TEXT = "5) Количество проданных билетов";
const string EDITING_IS_OVER_TEXT = "Редактирование успешно завершено!";

//Sorts settings
const string SORT_BY_TYPE_OF_TRANSPORT_TEXT = "1) Сортировка по алфавиту";
const string SORT_BY_COST_OF_TICKET_TEXT = "2) Сортировка по стоимости билета";
const string SORT_BY_YEAR_TEXT = "3) Сортировка по году продажи";
const string SEARCH_TEXT = "4) Поиск";

//Search settings
const string SEARCH_BY_YEAR_TEXT = "1) Поиск по году продажи билетов";
const string SEARCH_BY_TYPE_OF_TRANSPORT_TEXT = "2) Поиск по виду транспорта";
const string SEARCH_BY_SOLD_TICKETS_TEXT = "3) Поиск по количеству проданных билетов";
const string ENTER_MIN_VALUE_OF_YEAR_TEXT = "Введите min год для поиска: ";
const string ENTER_MAX_VALUE_OF_YEAR_TEXT = "Введите max год для поиска: ";
const string ENTER_MIN_VALUE_OF_SOlD_TICKETS_TEXT = "Введите min количество проданных билетов: ";
const string ENTER_MAX_VALUE_OF_SOlD_TICKETS_TEXT = "Введите max количество проданных билетов: ";
const string INFORMATION_OF_SEARCH_BY_YEAR_TEXT = "Информация о проездных билетах, проданных с ";
const string TO_TEXT = " до ";
const string YEAR_TEXT = " год";
const string INFORMATION_OF_SEARCH_BY_TYPE_OF_TRANSPORT_TEXT = "Информация о проездных билетах, проданных для вида транспорта ";
const string INFORMATION_OF_SEARCH_BY_SOLD_TICKETS_TEXT = "Информация о проездных билетах, проданных в количестве от ";
const string NOT_INDORMATION_OF_SEARCH_TEXT = "Нет информации по данному поиску!";

//Numbering
const string ZERO_TEXT = "0)";
const string ONE_TEXT = "1) ";
const string TWO_TEXT = "2) ";
const string THREE_TEXT = "3) ";
const string FOUR_TEXT = "4) ";
const string FIFE_TEXT = "5) ";
const string SIX_TEXT = "6) ";
const string SEVEN_TEXT = "7) ";

//Console table of tickets
const string TICKET_NUMBER_TEXT = "№";
const string TYPE_OF_TRANSPORT_TEXT = "Вид транспорта";
const string MONTH_OF_SALES_TEXT = "Месяц";
const string YEAR_OF_SALES_TEXT = "Год";
const string COST_OF_TICKET_TEXT = "Ст-ть билета";
const string NUMBER_OF_SALE_TICKETS_TEXT = "Кол-во прод. билетов";
const string BORDER_OF_TICKETS_TABLE_TEXT = "----------------------------------------------------------------------------------------";

//Console table of accounts
const string ID_OF_ACCOUNT_TEXT = "ID";
const string LOGIN_OF_ACCOUNT_TEXT = "Login";
const string ROLE_OF_ACCOUNT_TEXT = "Role";
const string STATUS_OF_ACCOUNT_TEXT = "Status";
const string BORDER_OF_ACCOUNTS_TABLE_TEXT = "---------------------------------------------";