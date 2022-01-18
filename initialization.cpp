/*******************************************************************************
 * 全屏控制台窗口
 * 取消标题栏及边框
 ******************************************************************************/
#include"head.h"
void full_screen()
{
    HWND hwnd = GetForegroundWindow();
    int cx = GetSystemMetrics(SM_CXSCREEN);            /* 屏幕宽度 像素 */
    int cy = GetSystemMetrics(SM_CYSCREEN);            /* 屏幕高度 像素 */

    LONG l_WinStyle = GetWindowLong(hwnd, GWL_STYLE);   /* 获取窗口信息 */
    /* 设置窗口信息 最大化 取消标题栏及边框 */
    SetWindowLong(hwnd, GWL_STYLE, (l_WinStyle | WS_POPUP | WS_MAXIMIZE) 
        & ~WS_CAPTION & ~WS_THICKFRAME & ~WS_BORDER);

    SetWindowPos(hwnd, HWND_TOP, 0, 0, cx, cy, 0);
}

//————————————————
//版权声明：本文为CSDN博主「linuxwuj」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/linuxwuj/article/details/81165885
void hide_cursor(bool if_hide)      //  隐藏光标
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO CursorInfo;
    GetConsoleCursorInfo(handle, &CursorInfo);      //获取控制台光标信息
    CursorInfo.bVisible = !if_hide;                  //隐藏控制台光标
    SetConsoleCursorInfo(handle, &CursorInfo);      //设置控制台光标状态
//————————————————
//    版权声明：本文为CSDN博主「其实我不胖_csdn」的原创文章，遵循CC 4.0 BY - SA版权协议，转载请附上原文出处链接及本声明。
//    原文链接：https ://blog.csdn.net/nocomment_84/article/details/53992730
}

void gotoxy(int x, int y)       //指定位置输出文本
{
    COORD c;
    c.X = x - 1;
    c.Y = y - 1;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

int input()
{
    int i = 1;
    char choice;
    while (1)
    {
        gotoxy(111, 32);
        printf("%c",choice = _getch());
        if (choice == '0')
        {
            hide_cursor(true);
			gotoxy(180, 34);
            exit(0);
        }
        if (choice >= '1' && choice <= '7')
        {
            return choice;
        }
		gotoxy(85, 34);
        printf("Error data+%d!Please retry!",i);
        i++;
    }
}

void welcome()
{
	full_screen();
	SetConsoleTitle(L"STUDENT MANAGEMENT SYSTEM");
	hide_cursor(true);

	gotoxy(80, 21);
	printf("-----------------*-----------------");
	gotoxy(80, 22);
	printf("---------------*---*---------------");
	gotoxy(80, 23);
	printf("------------*-WELCOME-*------------");
	gotoxy(80, 24);
	printf("--------------*-T O-*--------------");
	gotoxy(80, 25);
	printf("---------------*USE*---------------");
	gotoxy(80, 26);
	printf("-----STUDENT MANAGEMENT SYSTEM-----");
	gotoxy(80, 27);
	printf("-----------------*-----------------");
	Sleep(1000);
	system("cls");

	printf(
		"\n\n\n\n\n\n\n\n\n\n\n\n"
		"									  Copyright <YEAR> <COPYRIGHT HOLDER>\n\n"
		"						Redistributionand use in sourceand binary forms, with or without modification,\n"
		"						are permitted provided that the following conditions are met :\n\n"
		"							1. Redistributions of source code must retain the above copyright notice,\n"
		"							this list of conditionsand the following disclaimer.\n\n"
		"							2. Redistributions in binary form must reproduce the above copyright notice,\n"
		"							this list of conditionsand the following disclaimer in the documentation\n"
		"							and /or other materials provided with the distribution.\n\n"
		"							3. Neither the name of the copyright holder nor the names of its contributors may be used\n"
		"							to endorse or promote products derived from this software without specific prior written permission.\n\n"
		"						THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS \"AS IS\"\n"
		"						AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,\n"
		"						THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.\n"
		"						IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR\n"
		"						ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES\n"
		"						(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;\n"
		"						OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,\n"
		"						WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT(INCLUDING NEGLIGENCE OR OTHERWISE)\n"
		"						ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n");
	Sleep(2000);
	system("cls");
	bool is_first = true;
}

bool is_first = true;

void menu()
{
	hide_cursor(true);
	system("cls");
	printf("Version 1.0");
	gotoxy(83, 14);
	printf("【STUDENT MANAGEMENT SYSTEM】\n");
	gotoxy(85, 16);
	printf("1.ADD NEW STUDENT MESSAGE\n");
	gotoxy(85, 18);
	printf("2.DELETE STUDENTS MASSAGE\n");
	gotoxy(85, 20);
	printf("3.SEARCH STUDENTS MESSAGE\n");
	gotoxy(85, 22);
	printf("4.MODIFY STUDENTS MASSAGE\n");
	gotoxy(85, 24);
	printf("5.LIST   STUDENTS MESSAGE\n");
	gotoxy(85, 26);
	printf("6.---------ABOUT---------\n");
	gotoxy(85, 28);
	printf("7.---------HELPS---------\n");
	gotoxy(85, 30);
	printf("8.----input 0 to quit.---\n");
	gotoxy(84, 32);
	printf("Please input your choice:[   ]");
	gotoxy(85, 34);
	//printf("Please input your choice:[_]");
	if (is_first)
		system("pause");
	is_first = false;
	hide_cursor(false);
	switch (input())
	{
	case '1':
		add_student_message();
	case '2':
		delete_student_messge();
	case '3':
		search_student_message();
	case '4':
		modify_student_message();
	case '5':
		list_students_message();
	case '6':
		about();
	case '7':
		helps();
	default:
		break;
	}
}
