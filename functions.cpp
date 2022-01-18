#include"head.h"

typedef struct STUDENT		//学生结构体
{
    char number[STUDENT_NUMBER_MAX_LEN];
    char name[NAME_MAX_LEN];
    char sex[SEX_MAX_LEN];
    char birth[BIRTH_MAX_LEN];
}STUDENT;

int i = 0;
int j = 0;

STUDENT st[1001];
FILE* fp = NULL;

void if_file_exist()
{
    fp = fopen("STUDENT MANAGEMENT SYSTEM DATA.txt", "r+");
    if (fp == NULL)
    {
        gotoxy(85, 26);
        printf("Open file fail,create new file?");
        gotoxy(85, 27);
        printf("Y/N?");
        char c;
        while (1)
        {
            c = _getch();
            if (c == 'Y' || c == 'y')
            {
                printf("Y");
                gotoxy(85, 28);
                fp = fopen("STUDENT MANAGEMENT SYSTEM DATA.txt", "w+");
                if (fp != NULL)
                {
                    printf("Create file successfully.");
                    break;
                }
                else
                {
                    printf("Create file error.End openning file.");
                }
            }
            else if (c == 'N' || c == 'n')
            {
                printf("N");
                gotoxy(85, 28);
                printf("Successfully quit.");
                return;
            }
            else
            {
                printf("%c", c);
                printf("\b");
            }
        }
    }
    return;
}

void add_student_message()
{
    hide_cursor(0);

    system("cls");
    if_file_exist();
    system("cls");

    gotoxy(85, 18);
    printf("Student namber:");
    assert(scanf("%s", st[0].number) == 1);
    gotoxy(85, 20);
    printf("Name:");
    assert(scanf("%s", st[0].name) == 1);
    gotoxy(85, 22);
    printf("Sex:");
    assert(scanf("%s", st[0].sex) == 1);
    gotoxy(85, 24);
    printf("Birth:");
    assert(scanf("%s", st[0].birth)==1);
    gotoxy(85, 26);

    fseek(fp, 0, SEEK_END);

    if (fwrite(&st[0], sizeof(STUDENT), 1, fp) != 1)
        printf("file write error.");
    else
        printf("Successfully added.");

    fclose(fp);             //使文件内容从缓冲区保存到文件中

    hide_cursor(1);
    gotoxy(85, 28);
    system("pause");
    system("cls");
    menu();
}

void modify_student_message()
{
    hide_cursor(0);
    system("cls");
    list();

    printf("Please enter the student number of the person you want to modify:\n");
    search();
    if (j != -1)
    {
        int type=-1;
        printf("What type of information do you want to modify?\n");
        printf("1.Student number\n2.Student name\n3.Student sex\n4.Student birth\n0.Cancle\nYour chioce:");
        while (1)
        {
            assert(scanf("%d", &type) == 1);
            if (type != 1 && type != 2 && type != 3 && type != 4&&type!=0)
            {
                printf("Wrong number.Please retry.\n");
            }
            else if (type == 0)
            {
                return;
            }
            else
            {
                break;
            }
        }

        printf("Change it to?\n");
        switch (type)
        {
        case 1:
            assert(scanf(" %s", st[j].number) == 1);
        case 2:
            assert(scanf(" %s", st[j].name) == 1);
            break;
        case 3:
            assert(scanf(" %s", st[j].sex) == 1);
        case 4:
            assert(scanf(" %s", st[j].birth) == 1);
        default:
            break;
        }printf("Successfully changed.\n");

        fseek(fp, 0, SEEK_SET);
        for (j = 1; j <= i; j++)
        {
            fwrite(&st[j], sizeof(STUDENT), 1, fp);
        }

        fclose(fp);

    }
    hide_cursor(1);
    system("pause");
    menu();
}

void delete_student_messge()
{
    hide_cursor(0);
    system("cls");
    list();

    printf("Please enter the student number of the person you want to delete:\n");
    search();
    if (j != -1)
    {

        fp = fopen("STUDENT MANAGEMENT SYSTEM DATA.txt", "w+");
        fseek(fp, 0, SEEK_SET);

        for (int k = 1; k <= i; k++)
        {
            if (k == j)
                continue;

            fwrite(&st[k], sizeof(STUDENT), 1, fp);
        }

        fclose(fp);

    }

    hide_cursor(1);
    system("pause");
    menu();
}

void search()
{
    char search_number[STUDENT_NUMBER_MAX_LEN + 1];
    search_number[STUDENT_NUMBER_MAX_LEN] = '\0';

    assert((scanf(" %s", &search_number)) == 1);

    for (j = 1; j <= i; j++)
    {
        if (strcmp(search_number, st[j].number) == 0)
        {
            printf("Search successfully.\n");
            printf("%s %s %s %s\n", st[j].number, st[j].name, st[j].sex, st[j].birth);
            break;
        }
        if (j == i)
        {
            printf("Search failed.Student does not exist\n");
            j = -1;
            return;
        }
    }
}

void search_student_message()
{
    hide_cursor(0);
    system("cls");
    list();

    printf("Please enter the student number of the person you want to search:\n");
    search();
    
    hide_cursor(1);
    system("pause");
    menu();
}

void list()
{
    if_file_exist();

    system("cls");

    i = 0;              //防止i无限自增
    fseek(fp,0,SEEK_SET);
    while (!feof(fp))                              //一直读取知道文件尾结束
    {
        ++i;
        fread(&st[i], sizeof(STUDENT), 1, fp);  //以2进制方式将文件信息读到数组内存中//一次读取一个//
    }
    for ( j = 0; j < SEX_MAX_LEN + NAME_MAX_LEN + STUDENT_NUMBER_MAX_LEN + BIRTH_MAX_LEN; j++) { printf("~"); }printf("~~~~~~~\n");
    printf("%-11s %-9s %-5s %-8s\n", "Stu number", "Name", "Sex", "Birth");
    for ( j = 1; j <= i; j++)
    {
        printf("%-11s %-9s %-5s %-8s\n", st[j].number, st[j].name, st[j].sex, st[j].birth);
    }
}

void list_students_message()
{
    hide_cursor(0);

    list();

    hide_cursor(1);
    system("pause");
    menu();
}

void about()
{
    hide_cursor(1);
    system("cls");

    gotoxy(80, 14);
    printf("Program name:STUDENT MANAGEMENT SYSTEM");
    gotoxy(80, 16);
    printf("Version information:1.0");
    gotoxy(80, 18);
    printf("Development time:2022.01.03");
    gotoxy(80, 20);
    printf("Developer information list:");
    gotoxy(80, 22);
    printf("-----------------------------");
    gotoxy(80, 24);
    printf("Name:       xiè     fēi    ");
    gotoxy(80, 26);
    printf("Student number:  8008121104");
    gotoxy(80, 28);
    printf("Major: Software Engineering");
    gotoxy(80, 30);
    printf("Class:         2104         ");
    gotoxy(80, 32);
    printf("-----------------------------");
    gotoxy(80, 34);

    system("pause");
    menu();
}

void helps()
{
    hide_cursor(1);
    system("cls");

    gotoxy(80, 18);
    printf("-----------------------------");
    gotoxy(80, 20);
    printf("Input corresponding number to use the functions.");
    gotoxy(80, 22);
    printf("All functions are just as the name.");
    gotoxy(80, 24);
    printf("-----------------------------");
    gotoxy(80, 26);

    system("pause");
    menu();
}
