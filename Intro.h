#pragma once
#include <iostream>
#include "my_lib.h"
#include <fstream>
#include <string>
#include <thread>
#include <mutex>
int menu_choice = 0;
using namespace std;
mutex m;
// NGUYEN MAU HAM
void printLoadingBar();
void printPikachu();
void box_draw(int xleft, int xright, int ytop, int ybot, string board);
void selectionMenu();
// NGUYEN MAU HAM
void selectionMenu()
{
	char c;
	int ymove = 0;
	while (true)
	{
		SetColor(15);
		box_draw(41, 52, 11, 13, "Play");
		box_draw(41, 52, 14, 16, "Settings");
		box_draw(41, 52, 17, 19, "Exit");
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == 'w')
			{
				ymove--;
			}
			else if (c == 's')
			{
				ymove++;
			}
			else if (c == '\r')
			{
				if (ymove == 0)
				{
					menu_choice = 1;
					system("cls");
					break;
				}
				else if (ymove == 1)
				{
					menu_choice = 2;
					system("cls");
					break;
				}
				else if (ymove == 2)
				{
					menu_choice = 3;
					system("cls");
					/*cout << "EXIT" << endl;
					cout << "THANKS FOR USING OUR PRODUCT.";*/
					return;
				}
			}

		}
	

		if (ymove < 0)
			ymove = 2;

		else if (ymove > 2)
			ymove = 0;

		if (ymove == 0)
		{
			SetColor(11);
			box_draw(41, 52, 11, 13, "Play");
		}

		if (ymove == 1)
		{
			SetColor(11);
			box_draw(41, 52, 14, 16, "Settings");
		}

		if (ymove == 2)
		{
			SetColor(11);
			box_draw(41, 52, 17, 19, "Exit");
		}
		Sleep(200);
		/*_getch();*/
		/*ShowCur(0);*/
	}
}
void printPikachu()
{
	// cái chỗ này in con pikachu bên trái
	int x =1, y = 0;
	string str;
	fstream fs("pikachu left.txt", ios::in);
	while (!fs.eof())
	{
		SetColor(6);
		getline(fs, str, '\n');
		gotoXY(x, y);
		cout << str << endl;
		y++;
	}
	fs.close();

	// cái chỗ này in con pikachu bên phải
	x = 69, y = 0;
	fs.open("pikachu right.txt", ios::in);
	while (!fs.eof())
	{
		SetColor(6);
		getline(fs, str, '\n');
		gotoXY(x, y);
		cout << str << endl;
		y++;
	}
	fs.close();

	// cái chỗ này in matching game
	x = 24; y = 2;
	int i = 1;
	
	while (true)
	{
		SetColor(i);
		gotoXY(24, 2);
		cout << "  __  __        _        _     _             ";
		gotoXY(24, 3);
		cout << " |  \\/  | __ _ | |_  __ | |_  (_) _ _   __ _ ";
		gotoXY(24, 4);
		cout << " | |\\/| |/ _` ||  _|/ _|| ' \\ | || ' \\ / _` |";
		gotoXY(24, 5);
		cout << " |_|  |_|\\__,_| \\__|\\__||_||_||_||_||_|\\__, |";
		gotoXY(24, 6);
		cout << "   __ _  __ _  _ __   ___              |___/ ";
		gotoXY(24, 7);
		cout << "  / _` |/ _` || '  \\ / -_)                   ";
		gotoXY(24, 8);
		cout << "  \\__, |\\__,_||_|_|_|\\___|                   ";
		gotoXY(24, 9);
		cout << "  |___/                                      ";
		i++;
		if (i % 16 == 0)
		{
			i = 1;
		}
		
		gotoXY(35, 11);
		SetColor(15);
		cout << "Press Enter to continue";
		ShowCur(0);
		Sleep(500);
		gotoXY(35, 11);
		SetColor(15);
		cout << "                       ";
		ShowCur(0);
		Sleep(500);
		ShowCur(0);
		if (_kbhit() == true)
		{
			char c = _getch();
			if (c == 13)
				break;
		}
	}
	printLoadingBar();
	SetColor(15);
}
void box_draw(int xleft, int xright, int ytop, int ybot, string board)
{
	//cout << char(218) << endl; // xleft
	//cout << char(191) << endl; // xright
	//cout << char(192) << endl; // yleft
	//cout << char(217) << endl; // yright
	//cout << char(196); // cái này là dấu gạch ngang
	//cout << char(179); // cái này là dấu gạch đứng

	// stat_x là tọa độ gốc trái phía trên
	// strat_y là tọa độ gốc trái phía trên luôn
	// xleft 41   xright 52
	// ytop  11	  ybot   13
	gotoXY(xleft, ytop); // ve goc hop trai tren  // xleft ytop
	cout << char(218);
	gotoXY(xright, ytop); // ve goc hop phai tren  // xright ytop 
	cout << char(191); 
	gotoXY(xleft, ybot); // ve goc hop trai duoi  // xleft  ybot
	cout << char(192); 
	gotoXY(xright, ybot); // ve goc hop phai duoi  // xright ybot
	cout << char(217);
	// =========================================
	// đi từ xleft + 1 đến xright - 1 với y top
	for (int i = xleft + 1; i < xright; i++)
	{
		gotoXY(i, ytop);
		cout << char(196);
	}

	// đi từ xleft + 1 đến xright - 1 với y top
	for (int i = xleft + 1; i < xright; i++)
	{
		gotoXY(i, ybot);
		cout << char(196);
	}
	// =========================================

	// cái này là cái cạnh đứng hai bên cạnh
	gotoXY(xleft, (ybot + ytop) / 2); // canh doc dung trai
	cout << char(179);
	gotoXY(xright, (ybot + ytop) / 2); // canh doc dung phai
	cout << char(179);

	// bắt đầu in chữ ở phía trong
	// ô thứ nhất
	
	int mid_x = ((xright + xleft) - board.length()) / 2 + 1;
	int mid_y = (ybot + ytop) / 2;

	for (int i = xleft + 1; i <= 44; i++)
	{
		gotoXY(i, mid_y);
		cout << " ";
	}

	gotoXY(mid_x, mid_y);
	cout << board;
	for (int i = mid_x + board.length(); i <= xright - 1; i++)
	{
		gotoXY(i, mid_y);
		cout << " ";
	}
	ShowCur(0);
}
void printLoadingBar()
{
	SetColor(11);
	gotoXY(18, 12);
	cout << "LOADING..";
	char x = 219;
	int r = 0;
	for (int i = 28; i <= 71; i++)
	{
		
		gotoXY(27, 12);
		cout << ".";
		
		Sleep(40);
		
		gotoXY(27, 12);
		cout << " ";
		gotoXY(i, 12);
		
		if (i <= 44)
		{
			Sleep(20);
		}
		else
		{
			Sleep(10);
		}
		cout << x;
		
		gotoXY(73, 12);
		if (i == 71)
		{
			cout << 100 << "%";
			gotoXY(27, 12);
			cout << ".";
			break;
		}
		else
		{
			cout << r << "%";
			r+=2;
		}
		ShowCur(0);
	}

	gotoXY(18, 12);
	for (int i = 18; i <= 76; i++)
		cout << " ";
	ShowCur(0);
	
}

