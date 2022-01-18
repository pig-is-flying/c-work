#pragma once

#define SEX_MAX_LEN 5
#define NAME_MAX_LEN 9
#define BIRTH_MAX_LEN 8
#define STUDENT_NUMBER_MAX_LEN 11
#define _CRT_SECURE_NO_WARNINGS

//#include<graphics.h>
#include<ctime>
#include<cstdio>
#include<cstring>
#include<assert.h>
//#include<iomanip>
#include<conio.h>
#include<iostream>
#include<Windows.h>

int input();		//函数声明

void menu();

void list();

void about();

void helps();

void search();

void welcome();

void full_screen();

//void rewrite_file();

void if_file_exist();

void gotoxy(int x, int y);

void add_student_message();

void delete_student_messge();

void list_students_message();

void modify_student_message();

void search_student_message();

void hide_cursor(bool if_hide);
