#pragma once
#include <string>


using namespace std;

//File names
const string USERS_FILE_NAME = "Users.txt";
const string TICKETS_FILE_NAME = "Tickets.txt";

//File not exist
const string TICKETS_NOT_EXIST_TEXT = "��� �������� � �������� ��������� �������!";

//Main admin settings
const string MAIN_ADMIN_LOGIN = "admin";
const string MAIN_ADMIN_PASSWORD = "admin";

//Authorization menu
const string SIGN_IN_TEXT = "1) �����";
const string SIGN_UP_TEXT = "2) ���������������� ����� �������";
const string EXIT_OF_SYSTEM_TEXT = "3) ����� �� �������";
const string ENTER_LOGIN_TEXT = "������� �����: ";
const string ENTER_PASSWORD_TEXT = "������� ������: ";

//Registariton
const string CREATING_ACCOUNT_MODE_TEXT = "�������� ������ �������� � �������";
const string AUTHORIZATION_IN_SYSTEM_TEXT = "������������� � �������";
const string LOGIN_IS_EXIST_TEXT = "������� � ����� ������� ��� ����������! ����������, ���������� ������.";
const string LOGIN_NOT_CORRECT_TEXT = "��������� ����� �� ������������� �����(�� ����� 4 ��������)! ����������, ���������� ������.";
const string APPLICATION_IS_SENT_TEXT = "���� ������ �� ����������� ����������!";
const string SYSTEM_ACCESS_TEXT = "������� ����� �������� ����� ��������� ����� ������ ���������������";

//Sign in
const string ACCOUNT_NOT_EXIT_TEXT = "������� � ����� ������� �� ����������! ����������, ������� ������.";
const string WAITNG_STATUS_TEXT = "���� ������ �� ����������� ��� �� �������� ���������������!";
const string BLOCKED_STATUS_TEXT = "��� ������� ������������ ���������������!";

//User menu
const string USER_MODE_TEXT = "�� ���������� � ������ ������������!";
const string SYSTEM_TICKETS_SALES_TEXT = "1) ������� ������ ��������� �������";
const string USER_CHANGE_PASSWORD_TEXT = "2) �������� ������";
const string EXIT_OF_ACCOUNT_TEXT = "3) ����� �� ��������";
const string ENTER_PASSWORD_FOR_CHANGE_TEXT = "��� ��������� ������ ������� ���� ������� ������: ";
const string ENTER_NEW_PASSWORD_TEXT = "������� ����� ������: ";
const string PACCWORD_NOT_CORRECT_TEXT = "������������ ���� ������! ����������, ��������� �������.";
const string PASSWORD_CHANGE_NOT_AVALIABLE_TEXT = "������������ ������ ��� ������ ������. ��������� ������ ����������!";

//Admin menu
const string MAIN_ADMIN_MODE_TEXT = "�� ���������� � ������ �������� ��������������!";
const string ADMIN_MODE_TEXT = "�� ���������� � ������ ��������������!";
const string ACCOUNT_MANAGEMENT_TEXT = "2) ���������� ����������";
const string ADMIN_CHANGE_PASSWORD_TEXT = "3) �������� ������";
const string EXIT_FROM_ACCOUNT_TEXT = "4) ����� �� ��������";
const string VALIDATE_EXIT_FROME_ACCOUNT_TEXT = "�� ����� ������ ����� �� ��������?";

//New account settings
const string ENTER_ROLE_OF_ACCOUNT_TEXT = "������� ����: ";
const string ROLE_ADMIN_TEXT = "1) �������������";
const string ROLE_USER_TEXT = "2) ������������";
const string ACCOUNT_ADDED_TEXT = "����� ������� ��������!";

//Accounts manage
const string ACCOUNT_MANAGEMENT_MODE_TEXT = "������ ���������� ���������� �������";
const string VIEW_ACCOUNTS_TEXT = "1) �������� ���������";
const string ADD_NEW_ACCOUNT_TEXT = "2) �������� ����� �������";
const string ACCOUNTS_SETTINGS_TEXT = "3) �������������� ���������";
const string DELETE_ACCOUNT_TEXT = "4) �������� ���������";
const string VIEW_APLICATIONS_TEXT = "5) �������� �������� �� �����������";
const string RETURN_BACK_TEXT = "6) �����";

//Accounts settings
const string CHOCE_ACTION_TEXT = "�������� ��������:";
const string CHANGE_ROLE_TEXT = "1) �������� ����";
const string CHANGE_STATUS_TEXT = "2) �������� ������";
const string RETURN_TO_MENU_TEXT = "3) �����";
const string ENTER_ID_OF_ACCOUNT_TEXT = "������� ID ��������: ";
const string NOT_CHANGE_ROLE_MAIN_ADMIN_TEXT= "�� �� ������ �������� ���� �������� ��������������!";
const string NOT_CHANGE_STATUS_MAIN_ADMIN_TEXT = "�� �� ������ �������� ������ �������� ��������������!";
const string VALIDATE_DELATION_OF_ACCOUNT_TEXT = "�� ������������� ������ ������� �������?";
const string ACOOUNT_IS_DELETED_TEXT = "������� ������!";

//Application settings
const string ACCEPT_APPLICATION_TEXT = "1) ������� ������";
const string BLOCKED_APPLICATION_TEXT = "2) ��������� ������";
const string NOT_APPLICATIONS_TEXT = "��� ������ �� �����������!";
const string ENTER_ID_OF_APPLICATION = "������� ID ������: ";
const string VALIDATE_DELATION_OF_APPLICATION_TEXT = "�� ������������� ������ ��������� ������ �� ����������� ������������?";
const string VALIDATE_ACCEPTANE_OF_APPLICATION_TEXT = "�� ������������� ������ ������� ������ �� ����������� ������������?";
const string YES_TEXT = "1) ��";
const string NOT_TEXT = "2) ���";

//Enum structs text
const string ADMIN_TEXT = "Admin";
const string MAIN_ADMIN_TEXT = "Main admin";
const string USER_TEXT = "User";
const string ACTIVE_TEXT = "Active";
const string BLOCKED_TEXT = "Blocked";
const string WAITING_TEXT = "Waiting";

//Adding new ticket note
const string ADDING_NEW_TICKET_NOTE_TEXT = "���������� ����� ������ ��������� ������� � �������";
const string ENTER_TYPE_OF_TRANSPORT_TEXT = "������� ��� ����������: ";
const string ENTER_MONTH_OF_SALE_TEXT = "������� ����� ������� �������: ";
const string ENTER_YEAR_OF_SALES_TEXT = "������� ��� ������� �������:";
const string ENTER_COST_TICKET_TEXT = "������� ��������� ������ ������:";
const string ENTER_NUMBER_OF_SALE_TICKETS_TEXT = "������� ���������� ��������� �������: ";
const string BUS_TEXT = "0) �������";
const string TRAM_TEXT = "1) �������";
const string TROLLEYBUS_TEXT = "2) ����������";
const string TRAIN_TEXT = "3) �����";
const string PLANE_TEXT = "4) �������";
const string SHIP_TEXT = "5) �������";
const string ENTER_CORRECT_MONTH_TEXT = "���������, ������� ���������� [1 - 12] ��������: ";
const string ENTER_COORECT_YEAR_TEXT = "����������, ������� ���������� [2000 - 2022] ��������: ";
const string NOT_COORECT_COST_OF_TIKCET_TEXT = "������������ ���� ��������� ���������� ������! ����������, ��������� �������";
const string NOT_COORECT_SALE_TICKETS_TEXT = "������������ ���� ���������� ��������� �������! ����������, ��������� �������";
const string TICKET_NOTE_ADDED_TEXT = "����� ������ ���������!";




