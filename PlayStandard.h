#pragma once
#include <iostream>
#include "my_lib.h"
#include <time.h>
#include <ctime>
#include <windows.h>
#include<iomanip>
using namespace std;
struct Player
{
	string name;
	int hours, mins, secs;
};
Player p;
struct square_box
{
	int xleft[126], xright[126], ytop[126], ybot[126], ymid[126];
	int b_tdx[126], b_tdy[126];
};
square_box box;
struct ki_tu
{
	char ch;
	int tdx, tdy;
};
struct Y_Cursor
{
	int xcleft, xcright, yctop, ycbot, ycmid;
	int c_tdx, c_tdy;
};
int lines;
int cols;
ki_tu* kt;
void settings()
{
	do
	{
		cout << "Input number of lines: ";
		cin >> lines;
		cout << "Input number of columns: ";
		cin >> cols;
		if ((cols * lines) % 2 != 0)
		{
			cout << "Please input valid value. (Even number)" << endl;
		}
	} while ((cols * lines) % 2 != 0);

	do
	{
		cin.ignore();
		cout << "Please input your username: (Maximum 13 letters (including space))" << endl;
		getline(cin, p.name);
		if (p.name.length() > 13)
		{
			cout << "Please input valid value: " << endl;
		}
	} while (p.name.length() > 13);
	kt = new ki_tu[cols * lines];
}


// ====== NGUYEN MAU HAM ========
void printBoard(int xleft, int xright, int ytop, int ybot);
void sinh_ngau_nhien_ki_tu();
void printCursor(int xleft, int xright, int ytop, int ybot);
void printboardwithChar();
bool so_sanh_2_cursor(Y_Cursor c1, Y_Cursor c2);
bool ki_tu_2_o(char c1, char c2);
void xoa_o_vuong(int xleft, int xright, int ytop, int ybot, char* a);
bool check_I_doc(int x1, int y1, int x2, int y2);
bool check_I_ngang(int x1, int y1, int x2, int y2);
bool check_L1(int x1, int y1, int x2, int y2);
bool check_L2(int x1, int y1, int x2, int y2);
bool check_U_down(int x1, int y1, int x2, int y2);
bool check_U_up(int x1, int y1, int x2, int y2);
bool check_U_left(int x1, int y1, int x2, int y2);
bool check_U_right(int x1, int y1, int x2, int y2);
bool check_zic_zac_ngang(int x1, int y1, int x2, int y2);
bool check_zic_zac_doc(int x1, int y1, int x2, int y2);
void writeFile();
void read_and_show_File();
void doi_cho(Player* p1, Player* p2);
void xep_thu_tu(Player p[], int num_players);
void highlight_suggestion(int x1, int y1, int x2, int y2);
// ====== NGUYEN MAU HAM ========

void printBoard(int xleft, int xright, int ytop, int ybot)
{
	int left = 0;
	int right = 0;
	int top = 0;
	int bot = 0;
	int mid = 0; 
	system("cls");
	int ymid;
	/*cout << "input lines: ";
	cin >> c_lines;
	cout << "input columns: ";
	cin >> c_cols;*/
	system("cls");
	int slkt = 0;
	for (ytop = 1; ytop <= (3 * (lines - 1)) + 1;) // cái này chạy theo đúng tọa độ y nha
	{
		for (int i = 2; i <= cols * 5 + 1; i++) // cái chỗ này là in mấy cái đường ngang
		{
			gotoXY(i, ytop);
			cout << char(196);
		}
		ymid = ytop + 1;
		// in hết tất cả của hàng trên bao gồm học hộp phải góc hộp trái cột dọc giữa
		// thì nó phải chạy hết 1 hàng qua đi 

		// cái này là mượn "chỗ khác" để có phép tính cho nó tiện 
		// cái chỗ này là thay vì từ 2 tới 91
		// thì thay thế là x nó đi từ 0 đến 89 là đẹp
		for (int i = 0; i <= (5 * cols - 1); i++)
		{
			if (i % 5 == 0) // cái này là những tọa độ điểm của gốc trái
			{
				gotoXY(i + 2, ytop); // tọa độ gốc hộp bên trái
				cout << char(218);
				box.xleft[left++] = i + 2;
				box.ytop[top++] = ytop;
				box.ymid[mid++] = ymid;
				gotoXY(i + 2, ymid); // cái này chỉ cần để 1 lần thoi mà tại góc trái 
				cout << char(179);
			}

			if ((i + 1) % 5 == 0) // cái này là những tọa độ điểm của gốc phải
			{
				gotoXY(i + 2, ytop);
				cout << char(191);
				box.xright[right++] = i + 2;
				gotoXY(i + 2, ymid); // cái này chỉ cần để 1 lần thoi mà tại góc phải
				cout << char(179);
			}
		}



		ybot = ytop + 2;
		for (int i = 2; i <= cols * 5 + 1; i++) // chỗ này là in cái đường thẳng phía dưới của 1 hàng
		{
			gotoXY(i, ybot);
			cout << char(196);
		}
		// in hết tất cả của những hàng dưới gồm gốc hộp trái dưới, gốc hộp phải dưới
		// tọa độ x là phải đều nhau nên nó sẽ không đổi đâu
		for (int i = 0; i <= (5 * cols - 1); i++)
		{
			if (i % 5 == 0) // cái này là những tọa độ điểm của gốc trái
			{
				gotoXY(i + 2, ybot);
				box.ybot[bot++] = ybot;
				cout << char(192);
			}

			if ((i + 1) % 5 == 0) // cái này là những tọa độ điểm của gốc phải
			{
				gotoXY(i + 2, ybot);
				cout << char(217);
			}
		}
		// hết một cái giống như vậy là nó chạy hết 1 hàng ô vuông rồi
		ytop += 3;
	}


	// ============== test ====================
	/*cout << endl;
	for (int i = 0; i < cols * lines; i++)
	{

		if (i % cols == 0)
			cout << endl;

		cout << box.xleft[i] << "   " << box.xright[i] << "   " << box.ytop[i] << "   " << box.ybot[i] <<"  " << box.ymid[i] << endl;
	}*/
	// ============== test ====================
}
void sinh_ngau_nhien_ki_tu()
{
	srand(time(0));

	// chỗ này là sinh ngẫu nhiên các kí tự từ 0 đến bé hơn 1 nửa
	for (int i = 0; i < (cols * lines) / 2; i++)
	{
		kt[i].ch = rand() % 26 + 65;
		/*cout << i << "  " << kt[i].ch << endl;*/
	}
	// chỗ này là sinh ngẫu nhiên các kí tự từ 0 đến bé hơn 1 nửa



	// phần này là sinh phần tử ngẫu nhiên nhưng mà có những giá trị bằng mảng ban đầu
	int slg = 0;
	int j;
	int* idx = new int[(cols * lines) / 2]; // số phần tử nửa mảng còn lại
	int start = (cols * lines) / 2;
	int end = cols * lines - 1;
	do
	{
		// số lượng ô còn lại trên tổng số 
		// cái chỗ này có nghĩa là số thứ tự ô của nửa mảng còn lại
		// thí dụ là 12 phần tử 
		// thì chỗ này random từ 6 đến 12 dưới đây sẽ kiểm tra số nào đã random rồi
		j = rand() % (end - start + 1) + start; // sinh random
		// kiểm tra xem số này đã random ra chưa
		for (int i = 0; i < slg; i++)
		{
			if (j == idx[i])
			{
				j = rand() % (end - start + 1) + start; // sinh random
				i = -1; // để sau khi mà sinh random ra 1 số phải dò lại thêm 1 lần nữa 
				// nên là đi từ phần tử thứ 0 lên 
				// nên i phải chạy về i = - 1
			}
			if (i == slg - 1)
				break;
		}
		// khác hết phần tử phía trên rồi 
		kt[j].ch = kt[slg].ch; // thì lưu vào cái idx của cái mảng sau
		// cái này là nửa mảng còn lại sẽ được lần lượt tương ứng random theo cái mảng đã tạo ban đầu
		idx[slg] = j; // lưu vào cái mảng phụ 
		slg++; // lên cái phần tử tiếp theo
	} while (slg < (lines * cols) / 2);
	// phần này là sinh phần tử ngẫu nhiên nhưng mà có những giá trị bằng mảng ban đầu

	delete[]idx;

	/* dưới đây là in lại để kiểm tra*/
	/*j = (cols * lines) / 2;
	int z = 0;
	for (int i = j; i < (cols * lines); i++)
	{
		cout << i << "  " << kt[i].ch << endl;
	}*/
	/* dưới đây là in lại để kiểm tra*/


	// cái khúc ở dưới đây xem các cặp bằng nhau có bị trùng không
	/*int thu_tu = 0;
	int slkt = 0;
	int so_luong = cols * lines;
	int start_sau = (cols * lines) / 2;
	int* check = new int[cols * lines];
	for (int i = 0; i < cols * lines; i++)
		check[i] = 0;
	for (int i = 0; i < (cols * lines) / 2; i++)
	{
		for (int j = start_sau; j < so_luong; j++)
		{
			if (kt[i].ch == kt[j].ch && check[j] == 0)
			{
				check[j] = 1;
				cout << thu_tu++ << setw(4) << i << " " << kt[i].ch << setw(4) << j <<" " << kt[j].ch << endl;
				break;
			}
		}
	}*/
	// cái khúc ở dưới đây xem các cặp bằng nhau có bị trùng không
}
void printCursor(int xleft, int xright, int ytop, int ybot)
{

	// Phía trên
	// cái này là in cái gốc hộp con trỏ bên trái nè
	gotoXY(xleft, ytop);
	cout << char(218);

	// cái này là in cái gốc hộp con trỏ bên phải nè
	gotoXY(xright, ytop);
	cout << char(191);


	// Phía dưới
	// cái này là in cái gốc hộp con trỏ bên trái
	gotoXY(xleft, ybot);
	cout << char(192);

	gotoXY(xright, ybot);
	cout << char(217);

	for (int i = ytop; i <= ybot;) // cái chỗ này là in mấy cái đường ngang cả trên lẫn dưới
	{
		for (int z = xleft + 1; z <= xright - 1; z++)
		{
			gotoXY(z, i);
			cout << char(196);
		}
		i += 2;
	}

	int ymid = (ytop + ybot) / 2;
	gotoXY(xleft, ymid);
	cout << char(179);

	gotoXY(xright, ymid);
	cout << char(179);
	ShowCur(0);
}
void printboardwithChar()
{
	// ============== set up con trỏ vị trí ban đầu  ==============
	// in vị trí cái con trỏ lúc đầu mới vô game
	Y_Cursor Cursor;
	Y_Cursor OCursor; // con trỏ cũ là nơi cái tọa độ cũ của con trỏ hiện tại
	Y_Cursor sCursor[2]; // các con trỏ chọn
	Cursor.xcleft = box.xleft[0];
	Cursor.xcright = box.xright[0];
	Cursor.yctop = box.ytop[0];
	Cursor.ycbot = box.ybot[0];
	Cursor.ycmid = box.ymid[0];
	Cursor.c_tdx = (Cursor.xcleft + Cursor.xcright) / 2;
	Cursor.c_tdy = Cursor.ycmid;
	
	/*cout << Cursor.xleft << endl;
	cout << Cursor.xright << endl;
	cout << Cursor.ytop << endl;
	cout << Cursor.ybot << endl;*/
	gotoXY(Cursor.xcleft, Cursor.yctop);
	SetColor(13);
	cout << char(218);

	// cái này là in cái gốc hộp con trỏ bên phải nè
	gotoXY(Cursor.xcright, Cursor.yctop);
	SetColor(13);
	cout << char(191);

	// Phía dưới
	// cái này là in cái gốc hộp con trỏ bên trái
	gotoXY(Cursor.xcleft, Cursor.ycbot);
	SetColor(13);
	cout << char(192);

	gotoXY(Cursor.xcright, Cursor.ycbot);
	SetColor(13);
	cout << char(217);

	gotoXY(Cursor.xcleft, Cursor.ycmid);
	SetColor(13);
	cout << char(179);

	gotoXY(Cursor.xcright, Cursor.ycmid);
	SetColor(13);
	cout << char(179);

	for (int i = Cursor.yctop; i <= Cursor.ycbot;) // cái chỗ này là in mấy cái đường ngang cả trên lẫn dưới
	{
		for (int z = Cursor.xcleft + 1; z <= Cursor.xcright - 1; z++)
		{
			gotoXY(z, i);
			SetColor(13);
			cout << char(196);
		}
		i += 2;
	}
	// ============== set up con trỏ vị trí ban đầu  ==============


	/*int xleft = 2, xright = 6, ytop = 1, ybot = 3;
	int ymid = (ytop + ybot) / 2;
	int xmid = (xleft + xright) / 2;*/


	// tọa độ đại diện x y cho mỗi ô vuông cũng chính là cái tọa độ để ghi cái chữ
	// vô giữa ô
	// ================= In chữ cái vô cái ô vuông =================
	int count = 0;
	int flag = 0;
	int over = 0;
	for (int i = 0; i < cols * lines; i++)
	{
		kt[i].tdx = (box.xleft[i] + box.xright[i]) / 2;
		kt[i].tdy = (box.ybot[i] + box.ytop[i]) / 2;
		box.b_tdx[i] = (box.xleft[i] + box.xright[i]) / 2;
		box.b_tdy[i] = (box.ybot[i] + box.ytop[i]) / 2;
		SetColor(15);
		gotoXY(kt[i].tdx, kt[i].tdy);
		cout << kt[i].ch;
	}
	// ================= In chữ cái vô cái ô vuông =================

	p.hours = 0;
	p.mins = 0;
	p.secs = 0;
	int check = -1;
	int suggestion = 0;
	int randomize = 0;
	gotoXY(2, 0);
	cout << "Player: " << p.name;
	while (true)
	{
		SetColor(15);
		gotoXY(40, 0);
		cout << "Help: " << suggestion;
		gotoXY(80, 0);
		cout << "Random: " << randomize;
		bool rand_char = false;
		int tong_so_con_lai = cols * lines - over;
		bool help = false;
		// ================ ĐỒNG HỒ CHẠY NGẦM CHỈ CHO RA KẾT QUẢ KHÔNG HIỂN THỊ ================
		p.secs++;
		if (p.secs == 60)
		{
			p.secs = 0;
			p.mins += 1;
		}

		if (p.mins == 60)
		{
			p.mins = 0;
			p.hours += 1;
		}
		// ================ ĐỒNG HỒ CHẠY NGẦM CHỈ CHO RA KẾT QUẢ KHÔNG HIỂN THỊ ================
		// ================ CÀI ĐẶT ===================
		Cursor.c_tdx = (Cursor.xcleft + Cursor.xcright) / 2;
		Cursor.c_tdy = (Cursor.yctop + Cursor.ycbot) / 2;
		int pos_c = Cursor.c_tdy / 3 * (cols)+Cursor.c_tdx / 5;
		// ================ CÀI ĐẶT ===================


		
		// ================ xóa cũ ====================
		OCursor = Cursor;
		OCursor.c_tdx = (OCursor.xcleft + OCursor.xcright) / 2;
		OCursor.c_tdy = (OCursor.yctop + OCursor.ycbot) / 2;
		int pos_oc = OCursor.c_tdy / 3 * cols + OCursor.c_tdx / 5;

		if (OCursor.c_tdy >= 2 && OCursor.c_tdy <= 3 * lines - 1)
		{
			if (OCursor.c_tdx >= 4 && OCursor.c_tdx <= cols * 5 + 1 - 2)
			{
				if (kt[pos_oc].ch == ' ')
				{
				/*	char c = ' ';*/
					xoa_o_vuong(OCursor.xcleft, OCursor.xcright, OCursor.yctop, OCursor.ycbot, &kt[pos_oc].ch);
				}
				else
				{
					SetColor(15);
					printCursor(OCursor.xcleft, OCursor.xcright, OCursor.yctop, OCursor.ycbot);
				}
			}
		}
		// ================ xóa cũ ====================

		// ===== những cái chỗ mà cái con trỏ đi qua lại là cái chỗ đánh dấu =====
		if (so_sanh_2_cursor(OCursor, sCursor[0]) == true)
		{
			if(kt[pos_oc].ch != ' ' && count != 0)
			{
				SetColor(4);
				printCursor(sCursor[0].xcleft, sCursor[0].xcright, sCursor[0].yctop, sCursor[0].ycbot);
			}
		}

		if (so_sanh_2_cursor(OCursor, sCursor[1]) == true)
		{
			if (kt[pos_oc].ch != ' ' && count != 1 && count != 0 && count != 2)
			{
				SetColor(9);
				printCursor(sCursor[1].xcleft, sCursor[1].xcright, sCursor[1].yctop, sCursor[1].ycbot);
			}
			else if (count == 0 && kt[pos_oc].ch != ' ')
			{
				SetColor(15);
				printCursor(sCursor[1].xcleft, sCursor[1].xcright, sCursor[1].yctop, sCursor[1].ycbot);
			}
		}

		// ===== những cái chỗ mà cái con trỏ đi qua lại là cái chỗ đánh dấu =====
		
		// ============ Xem người dùng có nhập gì hay không ============
		char c;
		bool choose = false;
		if (_kbhit() == true)
		{
			// điều khiển
			c = _getch();
			if (c == 'w')
			{
				check = 1;
				Cursor.yctop = Cursor.yctop - 3;
				Cursor.ycbot = Cursor.ycbot - 3;
				Cursor.ycmid = Cursor.ycmid - 3;
			}

			else if (c == 's')
			{
				check = 2;
				Cursor.yctop = Cursor.yctop + 3;
				Cursor.ycbot = Cursor.ycbot + 3;
				Cursor.ycmid = Cursor.ycmid + 3;
			}

			else if (c == 'a')
			{	
				check = 3;
				Cursor.xcleft = Cursor.xcleft - 5;
				Cursor.xcright = Cursor.xcright - 5;
			}

			else if (c == 'd')
			{
				check = 4;
				Cursor.xcleft = Cursor.xcleft + 5;
				Cursor.xcright = Cursor.xcright + 5;
			}

			else if (c == 13 && kt[pos_oc].ch != ' ')
			{
				choose = true;
				count++;
			}

			else if (c == 'h')
			{
				help = true;
				suggestion++;
			}

			else if (c == 'r')
			{
				rand_char = true;
				randomize++;
			}
		}
		// ============ Xem người dùng có nhập gì hay không ============

		// ============ Khi người chơi cần gợi ý  ============
		if (help == true)
		{
			int i;
			bool suggested;
			do
			{
				suggested = false;
				srand(time(0));
				do
				{
					i = rand() % (cols * lines);
				}while(kt[i].ch == ' ');
				for (int j = 0; j < cols * lines; j++)
				{
					if (kt[j].ch == kt[i].ch)
					{
						if (check_I_doc(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						else if (check_I_ngang(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						else if (check_L1(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						else if (check_L1(box.b_tdx[j], box.b_tdy[j], box.b_tdx[i], box.b_tdy[i]) == true)
						{
							highlight_suggestion(box.b_tdx[j], box.b_tdy[j], box.b_tdx[i], box.b_tdy[i]);
							suggested = true;
							break;
						}
						else if (check_U_down(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						else if (check_U_up(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						else if (check_U_left(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						else if (check_U_right(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						/*else if (check_U_right(box.b_tdx[j], box.b_tdy[j], box.b_tdx[i], box.b_tdy[i]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}*/
						else if (check_zic_zac_doc(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						else if (check_zic_zac_doc(box.b_tdx[j], box.b_tdy[j], box.b_tdx[i], box.b_tdy[i]) == true)
						{
							highlight_suggestion(box.b_tdx[j], box.b_tdy[j], box.b_tdx[i], box.b_tdy[i]);
							suggested = true;
							break;
						}
						else if (check_zic_zac_ngang(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]) == true)
						{
							highlight_suggestion(box.b_tdx[i], box.b_tdy[i], box.b_tdx[j], box.b_tdy[j]);
							suggested = true;
							break;
						}
						else if (check_zic_zac_ngang(box.b_tdx[j], box.b_tdy[j], box.b_tdx[i], box.b_tdy[i]) == true)
						{
							highlight_suggestion(box.b_tdx[j], box.b_tdy[j], box.b_tdx[i], box.b_tdy[i]);
							suggested = true;
							break;
						}
					}
				}
			} while (suggested == false);
			
		}
		// ============ Khi người chơi cần gợi ý  ============

		// ============ Khi người chơi thấy không chơi được nữa thì random  ============
		if (rand_char == true)
		{
			srand(time(0));
			char* c = new char[tong_so_con_lai / 2];
			int mark;
			int count = 0;
			for (int i = 0; i < cols * lines; i++)
			{
				if (kt[i].ch != ' ')
				{
					mark = i;
					kt[i].ch = (rand() % 26 + 65);
					gotoXY(box.b_tdx[i], box.b_tdy[i]);
					cout << kt[i].ch;
					c[count] = kt[i].ch;
					count++;
				}
				if (count == tong_so_con_lai / 2)
					break;
			}
			
			mark += 1;
			int slg = 0;
			
			int* num = new int[tong_so_con_lai / 2];
			for (int i = mark; i < cols * lines; i++)
			{
				if (kt[i].ch != ' ')
				{
					int ngau_nhien = rand() % (tong_so_con_lai / 2);
					for (int j = 0; j < slg; j++)
					{
						if (ngau_nhien == num[j])
						{
							ngau_nhien = rand() % (tong_so_con_lai / 2);
							j = -1;
						}
					}
					kt[i].ch = c[ngau_nhien];
					gotoXY(box.b_tdx[i], box.b_tdy[i]);
					cout << kt[i].ch;
					num[slg++] = ngau_nhien;
				}
				
			}

			delete[]c;
			delete[]num;
		}
		// ============ Khi người chơi thấy không chơi được nữa thì random  ============

		
		
		
		
		// Xét để khi nó chạy xuống dưới thì nó chạy ngược lên trên
		if (Cursor.yctop < 1 && Cursor.ycbot < 3)
		{
			Cursor.ycbot = lines * 3;
			Cursor.yctop = Cursor.ycbot - 2;
			Cursor.ycmid = (Cursor.yctop + Cursor.ycbot) / 2;
		}

		else if (Cursor.ycbot > lines * 3)
		{
			Cursor.ycbot = 3;
			Cursor.yctop = 1;
			Cursor.ycmid = 2;
		}

		else if (Cursor.xcleft < 2 && Cursor.xcright < 6)
		{
			Cursor.xcright = 5 * cols + 1;
			Cursor.xcleft = Cursor.xcright - 4;
		}

		else if (Cursor.xcright > 5 * cols + 1)
		{
			Cursor.xcright = 6;
			Cursor.xcleft = 2;
		}
		// Xét để khi nó chạy xuống dưới thì nó chạy ngược lên trên

		Cursor.c_tdx = (Cursor.xcleft + Cursor.xcright) / 2;
		Cursor.c_tdy = (Cursor.yctop + Cursor.ycbot) / 2;
		pos_c = Cursor.c_tdy / 3 * (cols)+Cursor.c_tdx / 5;
		if (choose == true)
		{
			if (count == 1 && kt[pos_c].ch != ' ')
			{
				sCursor[0] = Cursor;
				SetColor(4);
				printCursor(sCursor[0].xcleft, sCursor[0].xcright, sCursor[0].yctop, sCursor[0].ycbot);
				flag = 1;
				sCursor[0].c_tdx = (sCursor[0].xcleft + sCursor[0].xcright) / 2;
				sCursor[0].c_tdy = Cursor.ycmid;
			}

			else if (count == 2 && kt[pos_c].ch != ' ')
			{
				SetColor(9);
				sCursor[1] = Cursor;
				printCursor(sCursor[1].xcleft, sCursor[1].xcright, sCursor[1].yctop, sCursor[1].ycbot);
				flag = 0;
				sCursor[1].c_tdx = (sCursor[1].xcleft + sCursor[1].xcright) / 2;
				sCursor[1].c_tdy = Cursor.ycmid;
			}
		}

		// Nếu như cái ô count đếm được hai lần
		if (count == 2)
		{
			int pos_0 = sCursor[0].c_tdy / 3 * (cols)+sCursor[0].c_tdx / 5;
			int pos_1 = sCursor[1].c_tdy / 3 * (cols)+sCursor[1].c_tdx / 5;
			int bm = 0;


			if (check_I_doc(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Idoc";*/
				bm = 1;
			}
				
			else if (check_I_ngang(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Ingang";*/
				bm = 1;
			}
			else if (check_L1(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "L1";*/
				bm = 1;
			}
			else if (check_L1(sCursor[1].c_tdx, sCursor[1].c_tdy, sCursor[0].c_tdx, sCursor[0].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "L1";*/
				bm = 1;
			}
			else if (check_U_down(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Udown";*/
				bm = 1;
			}
			else if (check_U_up(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "UUp";*/
				bm = 1;
			}
			else if (check_U_left(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Uleft";*/
				bm = 1;
			}
			else if (check_U_right(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Uright";*/
				bm = 1;
			}
			else if (check_U_right(sCursor[1].c_tdx, sCursor[1].c_tdy, sCursor[0].c_tdx, sCursor[0].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Uright";*/
				bm = 1;
			}
			else if (check_zic_zac_ngang(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Zngang x1 nam tren";*/
				bm = 1;
			}
			else if (check_zic_zac_ngang(sCursor[1].c_tdx, sCursor[1].c_tdy, sCursor[0].c_tdx, sCursor[0].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Zngang x1 nam tren";*/
				bm = 1;
			}
			else if (check_zic_zac_doc(sCursor[0].c_tdx, sCursor[0].c_tdy, sCursor[1].c_tdx, sCursor[1].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Zngang x1 nam trai";*/
				bm = 1;
			}
			else if (check_zic_zac_doc(sCursor[1].c_tdx, sCursor[1].c_tdy, sCursor[0].c_tdx, sCursor[0].c_tdy) == true)
			{
				/*gotoXY(40, 10);
				cout << "Zngang x1 nam trai";*/
				bm = 1;
			}

			if (kt[pos_0].ch == kt[pos_1].ch && bm == 1 && pos_0 != pos_1  && kt[pos_0].ch != ' ' && kt[pos_1].ch != ' ')
			{
				kt[pos_0].ch = ' ';
				kt[pos_1].ch = ' ';
				xoa_o_vuong(sCursor[0].xcleft, sCursor[0].xcright, sCursor[0].yctop, sCursor[0].ycbot, &kt[pos_0].ch);
				xoa_o_vuong(sCursor[1].xcleft, sCursor[1].xcright, sCursor[1].yctop, sCursor[1].ycbot, &kt[pos_1].ch);
				over += 2;
			}

			count = 0;

			if (count == 0 && kt[pos_0].ch != ' ')
			{
				SetColor(15);
				printCursor(sCursor[0].xcleft, sCursor[0].xcright, sCursor[0].yctop, sCursor[0].ycbot);
				printCursor(sCursor[1].xcleft, sCursor[1].xcright, sCursor[1].yctop, sCursor[1].ycbot);
			}
		}
		// =============================== XÉT ĐIỀU KIỆN NẾU ĐI LỐ ===============================

		


		if (over == cols * lines)
		{
			system("cls");
			SetColor(10);
			cout << "Username: " << p.name << "     " << "Times: ";
			cout << setfill('0') << setw(2) << p.hours << ":" << setfill('0') << setw(2) << p.mins << ":" << setfill('0') << setw(2) << p.secs << endl;
			gotoXY(48, 0);
			cout << "Help: " << suggestion << "    " << "Random: " << randomize << endl;
			writeFile();
			read_and_show_File();
			while (true)
			{
				gotoXY(0, 21);
				cout << "Press ESC to exit game";
				gotoXY(0, 21);
				Sleep(1000);
				cout << "                      ";
				Sleep(100);
				if (_kbhit() == true)
				{
					c = _getch();
					if (c == 27)
					{
						cout << "THANKS FOR USING OUR PRODUCT.";
						ShowCur(0);
						return;
					}
				}
				
			}
			delete[]kt;
		}
		SetColor(13);
		printCursor(Cursor.xcleft, Cursor.xcright, Cursor.yctop, Cursor.ycbot);
		ShowCur(0);
		Sleep(100);
	}
}
bool so_sanh_2_cursor(Y_Cursor c1, Y_Cursor c2)
{
	if (c1.c_tdx == c2.c_tdx && c1.c_tdy == c2.c_tdy)
		return true;
	return false;
}
bool ki_tu_2_o(char c1, char c2)
{
	if (c1 == c2)
		return true; 
	
	return false;
}
void xoa_o_vuong(int xleft, int xright, int ytop, int ybot, char * a)
{
	int xmid = (xleft + xright) / 2;
	int ymid = (ytop + ybot) / 2;

	for (int i = ytop; i <= ybot; i++)
	{
		for (int j = xleft; j <= xright; j++)
		{
			gotoXY(j, i);
			cout << " ";
		}
	}
	gotoXY(xmid, ymid);
	cout << *a;
}
// ======== hàm dùng để ghi vào file ========
void writeFile()
{
	fstream fs("GameRecord.txt", ios::out | ios::app);
	fs << p.name << ", " << setw(2) << setfill('0') << p.hours << ":" << setw(2) << setfill('0')
		<< p.mins << ":" << setw(2) << setfill('0') << p.secs << endl;
	fs.close();
}
// ======== hàm dùng để ghi vào file ========

// ======== hàm dùng để đọc file ========
void read_and_show_File()
{
	Player plist[100];
	int i = 0;
	fstream fs("GameRecord.txt", ios::in);
	fs.seekg(0, 0);
	while (!fs.eof())
	{
		getline(fs, plist[i].name, ',');
		fs >> plist[i].hours; fs.ignore();
		fs >> plist[i].mins; fs.ignore();
		fs >> plist[i].secs; fs.ignore();
		i++;
	}
	SetColor(14);
	int num_players = --i;
	//cout << i << endl;
	xep_thu_tu(plist, num_players);
	cout << char(218);
	for (int i = 1; i <= 32; i++)
		cout << char(196);
	cout << char(191) << endl;
	cout << char(179) << "        LEADERBOARD             " << char(179) << endl;
	cout << char(192);
	for (int i = 1; i <= 31; i++)
	{
		if (i == 7)
			cout << char(191);
		else if (i == 20)
			cout << char(218);
		cout << char(196);
	}
	gotoXY(0, 3);
	cout << char(218);
	gotoXY(33, 3);
	cout << char(191) << endl;
	cout << char(179) << "Rank  " << char(179) << "    Name:    " << char(179) << "   Times:  " << char(179) << endl;
	cout << char(192);
	for (int i = 1; i <= 30; i++)
	{
		if (i == 7)
			cout << char(191);
		else if (i == 20)
			cout << char(218);
		cout << char(196);
	}
	cout << char(217) << endl;
	for (int z = 0; z < num_players; z++)
	{
		int length = plist[z].name.length();
		if (z + 1 < 10)
			cout << char(179) << z + 1 << "     " << char(179) << plist[z].name;

		else
			cout << char(179) << z + 1 << "    " << char(179) << plist[z].name;
		int space = 13 - plist[z].name.length();
		for (int i = 1; i <= space; i++)
			cout << " ";
		cout << char(179) << "  ";
		cout  << setw(2) << setfill('0') << plist[z].hours << ":" << setw(2) << setfill('0')
			<< plist[z].mins << ":" << setw(2) << setfill('0') << plist[z].secs <<" " << char(179) << endl;
		cout << char(192);
		for (int i = 1; i <= 30; i++)
		{
			if (i == 7)
				cout << char(191);
			else if (i == 20)
				cout << char(218);
			cout << char(196);
		}
		cout << char(217) << endl;
	}
	fs.close();
}
// ======== hàm dùng để đọc file ========

// ======== hàm dùng để đọc xếp hạng người chơi từ nhất đến cuối ========
void xep_thu_tu(Player p[], int num_players)
{
	for (int i = 0; i < num_players - 1; i++)
	{
		// có phải là so sánh thời gian là giờ là cái đầu tiên
		// sau đó so sánh tới bậc thấp hơn đó chính là phút 
		// sau đó cuối cùng là so sánh với giây
		for (int j = 0; j < num_players - 1 - i; j++)
		{
			if (p[j].hours > p[j + 1].hours)
				doi_cho(&p[j], &p[j + 1]);
			if (p[j].hours == p[j + 1].hours)
				if (p[j].mins > p[j + 1].mins)
					doi_cho(&p[j], &p[j + 1]);
				else if (p[j].mins == p[j + 1].mins)
					if (p[j].secs > p[j + 1].secs)
						doi_cho(&p[j], &p[j + 1]);
		}
	}
}
// ======== hàm dùng để đọc xếp hạng người chơi từ nhất đến cuối ========


// ======== hàm dùng để đổi chỗ hai cái struct ========
void doi_cho(Player* p1, Player* p2)
{
	Player temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}
// ======== hàm dùng để đổi chỗ hai cái struct ========

// ======== hàm dùng để lấp lánh hai cái gợi ý ========
void highlight_suggestion(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x1 / 5 + y1 / 3 * cols;
	for (int i = 0; i < 3; i++)
	{
		SetColor(4);
		gotoXY(x1, y1);
		cout << " ";
		Sleep(50);
		gotoXY(x1, y1);
		cout << kt[pos1].ch;
		gotoXY(x2, y2);
		cout << " ";
		Sleep(50);
		gotoXY(x2, y2);
		cout << kt[pos2].ch;
	}
	SetColor(15);
	gotoXY(x1, y1);
	cout << kt[pos1].ch;
	SetColor(15);
	gotoXY(x2, y2);
	cout << kt[pos2].ch;
}
// các hàm dùng để kiểm tra matching
bool check_I_doc(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int vt_start;
	int vt_end;
	if (x1 == x2)
	{
		/*if (abs(y1 - y2) == 3)
			if (kt[pos1].ch == kt[pos2].ch && kt[pos1].ch != ' ' && kt[pos2].ch != ' ')
				return true;*/


		if (y1 < y2)
		{
			vt_start = x1 / 5 + y1 / 3 * cols;
			vt_end = x2 / 5 + y2 / 3 * cols;
			for (int i = vt_start + cols; i <= vt_end - cols; )
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}
			/*if (kt[vt_start].ch == kt[vt_end].ch && kt[vt_start].ch != ' ' && kt[vt_end].ch != ' ')*/
				return true;
			/*else
				return false;*/
		}
		else if (y1 > y2)
		{
			vt_start = x2 / 5 + y2 / 3 * cols;
			vt_end = x1 / 5 + y1 / 3 * cols;
			for (int i = vt_start + cols; i <= vt_end - cols; )
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}
			/*if (kt[vt_start].ch == kt[vt_end].ch && kt[vt_start].ch != ' ' && kt[vt_end].ch != ' ')*/
				return true;
			/*else
				return false;*/
		}
	}
}
bool check_I_ngang(int x1, int y1, int x2, int y2)
{
	int vt_start;
	int vt_end;
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	if (y1 == y2)
	{
		/*if (abs(x1 - x2) == 5)
			if (kt[pos1].ch == kt[pos2].ch && kt[pos1].ch != ' ' && kt[pos2].ch != ' ')
				return true;*/

		if (x1 < x2)
		{
			vt_start = x1 / 5 + y1 / 3 * cols;
			vt_end = x2 / 5 + y2 / 3 * cols;
			for (int i = vt_start + 1; i <= vt_end - 1;i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
		else if (x1 > x2)
		{
			vt_start = x2 / 5 + y2 / 3 * cols;
			vt_end = x1 / 5 + y1 / 3 * cols;
			for (int i = vt_start + 1; i <= vt_end -1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
	}
}
bool check_L1(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols; 
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int tdgdy = y2;
	int tdgdx = x1;
	int posgd = x1 / 5 + y2 / 3 * cols;
	if (kt[posgd].ch != ' ')
		return false;
	else if (x1 < x2)
	{
		if (y1 < y2)
		{
			for (int i = pos1 + cols; i <= posgd - cols;)
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}

			for (int i = posgd + 1; i <= pos2 - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else
		{
			for (int i = posgd + cols; i <= pos1 - cols;)
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}

			for (int i = posgd + 1; i <= pos2 - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	else
	{
		if (y1 < y2)
		{
			for (int i = pos1 + cols; i <= posgd - cols;)
			{
				if (kt[i].ch != ' ')
					return false;
				i += cols;
			}
			for (int i = pos2 + 1; i <= posgd - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else
		{
			for (int i = pos2 + 1; i <= posgd - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			for (int i = posgd + cols; i <= pos1 - cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	
}
bool check_L2(int x1, int y1, int x2, int y2)
{
	int tdgdy = y1;
	int tdgdx = x2;
	int posgd = x2 / 5 + y1 / 3 * cols;
	if (kt[posgd].ch != ' ')
		return false;
	if (check_I_doc(x2, y2, tdgdx, tdgdy) == true)
	{
		if (check_I_ngang(x1, y1, tdgdx, tdgdy) == true)
			return true;
	}
	return false;
}
bool check_U_down(int x1, int y1, int x2, int y2)
{	
	/* =======   MẶC ĐỊNH    =======   */
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int y1chay = y1 + 3; 
	int y2chay = y2 + 3;
	int stt_gd1 = pos1 + cols;
	int stt_gd2 = pos2 + cols;
	/* =======   MẶC ĐỊNH    =======   */
	
	if (y1 == 3 * lines - 1 && y2 == 3 * lines - 1)
	{
		/*kt[stt_gd1].ch = ' ';
		kt[stt_gd2].ch = ' ';*/
		return true;
	}
		
	if (kt[stt_gd1].ch != ' ' && stt_gd1 != 3 * lines + 2)
		return false;
	else if (kt[stt_gd2].ch != ' ' && stt_gd2 != 3 * lines + 2)
		return false;

	if (y1 == 3 * lines - 1 || y2 == 3 * lines - 1)
	{
		if (y1 == 3 * lines - 1)
		{
			for (int i = stt_gd2; i <= x2 / 5 + y1 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}

		else if (y2 == 3 * lines - 1)
		{
			for (int i = stt_gd1; i <= x1 / 5 + y2 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	else
	{
		while (kt[stt_gd1].ch == ' ')
		{
			stt_gd1 += cols;
			y1chay += 3;
			if (y1chay >= 3 * lines + 2)
			{
				/*kt[stt_gd1].ch = ' ';*/
				break;
			}
		}
		while (kt[stt_gd2].ch == ' ')
		{
			stt_gd2 += cols;
			y2chay += 3;
			if (y2chay >= 3 * lines + 2)
			{
				/*kt[stt_gd2].ch = ' ';*/
				break;
			}
		}

		if (y1chay >= 3 * lines + 2 && y2chay >= 3 * lines + 2)
			return true;

		stt_gd1 -= cols;
		stt_gd2 -= cols;
		y1chay -= 3;
		y2chay -= 3;

		if (y1chay < y2 || y2chay < y1) return false;

		if (y1chay == 3 * lines - 1)
		{
			for (int i = pos2 + cols; i <= x2 / 5 + y1chay / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}


		else if (y2chay == 3 * lines - 1)
		{
			for (int i = pos1 + cols; i <= x1 / 5 + y2chay / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		
		if (x1 <= x2)
		{
			for (int i = stt_gd1 + 1; i <= x2 / 5 + y1chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x2 / 5 + y1chay / 3 * cols)
					return true;
			}

			for (int i = x1 / 5 + y2chay / 3 * cols; i <= stt_gd2 - 1; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd2 - 1)
					return true;
			}
			return false;
		}

		else if (x1 >= x2)
		{
			for (int i = stt_gd2 + 1; i <= x1 / 5 + y2chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x1 / 5 + y2chay / 3 * cols)
					return true;
			}

			for (int i = x2 / 5 + y1chay / 3 * cols; i <= stt_gd1 - 1; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd1 - 1)
					return true;
			}
			return false;
		}
	}
}
bool check_U_up(int x1, int y1, int x2, int y2)
{
	/* =======   MẶC ĐỊNH    =======   */
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int y1chay = y1 - 3;
	int y2chay = y2 - 3;
	int stt_gd1 = pos1 - cols;
	int stt_gd2 = pos2 - cols;
	/* =======   MẶC ĐỊNH    =======   */

	if (y1 == 2 && y2 == 2)
	{
		/*kt[stt_gd1].ch = ' ';
		kt[stt_gd2].ch = ' ';*/
		return true;
	}

	if (kt[stt_gd1].ch != ' ' && stt_gd1 != 3 * lines + 2)
		return false;
	else if (kt[stt_gd2].ch != ' ' && stt_gd2 != 3 * lines + 2)
		return false;

	if (y1 == 2 || y2 == 2)
	{
		if (y1 == 2)
		{
			for (int i = stt_gd2; i >= x2 / 5 + y1 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i -= cols;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else if (y2 == 2)
		{
			for (int i = stt_gd1; i >= x1 / 5 + y2 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i -= cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	else
	{
		while (kt[stt_gd1].ch == ' ')
		{
			stt_gd1 -= cols;
			y1chay -= 3;
			if (y1chay == -1)
				break;
		}
		while (kt[stt_gd2].ch == ' ')
		{
			stt_gd2 -= cols;
			y2chay -= 3;
			if (y2chay == -1)
				break;
		}

		if (y1chay == -1 && y2chay == -1)
			return true;

		stt_gd1 += cols;
		stt_gd2 += cols;
		y1chay += 3;
		y2chay += 3;

		if (y1chay > y2 || y2chay > y1) return false;

		if (y1chay == 2)
		{
			for (int i = pos2 - cols; i <= x2 / 5 + y1chay / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i -= cols;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}


		else if (y2chay == 2)
		{
			for (int i = pos1 - cols; i <= x1 / 5 + y2chay / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					return false;

				i -= cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}

		if (x1 <= x2)
		{
			for (int i = stt_gd1 + 1; i <= x2 / 5 + y1chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x2 / 5 + y1chay / 3 * cols)
					return true;
			}

			for (int i = x1 / 5 + y2chay / 3 * cols; i <= stt_gd2 - 1; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd2 - 1)
					return true;
			}
			return false;
		}

		else if (x1 >= x2)
		{
			for (int i = stt_gd2 + 1; i <= x1 / 5 + y2chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x1 / 5 + y2chay / 3 * cols)
					return true;
			}

			for (int i = x2 / 5 + y1chay / 3 * cols; i <= stt_gd1 - 1; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd1 - 1)
					return true;
			}
			return false;
		}
	}
}
bool check_U_left(int x1, int y1, int x2, int y2)
{
	/* =======   MẶC ĐỊNH    =======   */
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int x1chay = x1 - 5; 
	int x2chay = x2 - 5;
	int stt_gd1 = pos1 - 1;
	int stt_gd2 = pos2 - 1;
	/* =======   MẶC ĐỊNH    =======   */
	if (x1 == 4  && x2 == 4)
		return true;

	if (kt[stt_gd1].ch != ' ' && stt_gd1 != -1)
		return false;
	if (kt[stt_gd2].ch != ' ' && stt_gd2 != -1)
		return false;


	else if (x1 == 4 || x2 == 4)
	{
		if (x1 == 4)
		{
			for (int i = stt_gd2; i >= x1 / 5 + y2 / 3 * cols; i--)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}


		else if (x2 == 4)
		{
			for (int i = stt_gd1; i >= x2 / 5 + y1 / 3 * cols; i--)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}

	else
	{
		while (kt[stt_gd1].ch == ' ')
		{
			stt_gd1 -= 1;
			x1chay -= 5;
			if (x1chay <= -1)
				break;
		}
		
		while (kt[stt_gd2].ch == ' ')
		{
			stt_gd2 -= 1;
			x2chay -= 5;
			if (x2chay <= -1)
				break;
		}

		if (x1chay <= -1 && x2chay <= -1)
			return true;


		stt_gd1 += 1;
		stt_gd2 += 1;
		x1chay += 5;
		x2chay += 5;


		if (y1 <= y2)
		{
			for (int i = stt_gd1 + cols; i <= x1chay / 5 + y2 / 3 * cols ; )
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else if (y1 >= y2)
		{
			for (int i = stt_gd2 + cols; i <= x2chay / 5 + y1 / 3 * cols; )
			{
				if (kt[i].ch != ' ')
					return false;

				i += cols;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
}
bool check_U_right(int x1, int y1, int x2, int y2)
{
	/* =======   MẶC ĐỊNH    =======   */
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int x1chay = x1 + 5;
	int x2chay = x2 + 5;
	int stt_gd1 = pos1 + 1;
	int stt_gd2 = pos2 + 1;
	/* =======   MẶC ĐỊNH    =======   */

	if (x1 == 5 * cols - 1 && x2 == 5 * cols - 1)
	{
		/*kt[stt_gd1].ch = ' ';
		kt[stt_gd2].ch = ' ';*/
		return true;
	}

	if (kt[stt_gd1].ch != ' ' && stt_gd1 != 5 * cols + 4)
		return false;
	else if (kt[stt_gd2].ch != ' ' && stt_gd2 != 5 * cols + 4)
		return false;

	if (x1 == 5 * cols - 1 || x2 == 5 * cols - 1)
	{
		if (x1 == 5 * cols - 1)
		{
			for (int i = stt_gd2; i <= x1 / 5 + y2 / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
		else if (x2 == 5 * cols - 1)
		{
			for (int i = stt_gd1; i <= x2 / 5 + y1 / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}
	}
	else
	{
		while (kt[stt_gd1].ch == ' ')
		{
			stt_gd1 += 1;
			x1chay += 5;
			if (x1chay == 5 * cols + 4)
			{
				/*kt[stt_gd1].ch = ' ';*/
				break;
			}
		}
		while (kt[stt_gd2].ch == ' ')
		{
			stt_gd2 += 1;
			x2chay += 5;
			if (x2chay == 5 * cols + 4)
			{
				/*kt[stt_gd2].ch = ' ';*/
				break;
			}
		}

		if (x1chay == 5 * cols + 4 && x2chay == 5 * cols + 4)
			return true;

		stt_gd1 -= 1;
		stt_gd2 -= 1;
		x1chay -= 5;
		x2chay -= 5;

		if (x1chay < x2 || x2chay < x1) return false;

		if (x1chay == 5 * cols - 1)
		{
			for (int i = pos2 + 1; i <= x1chay / 5 + y2 / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}


		else if (x2chay == 5 * cols - 1)
		{
			for (int i = pos1 + 1; i <= x2chay / 5 + y1 / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}

			if (kt[pos1].ch == kt[pos2].ch)
				return true;
			else
				return false;
		}

		if (y1 <= y2)
		{
			for (int i = stt_gd1 + cols; i <= x1chay / 5 + y2 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x1chay / 5 + y2 / 3 * cols)
					return true;

				i += cols;
			}

			for (int i = x2chay / 5 + y1 / 3 * cols; i <= stt_gd2 - cols;)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == stt_gd2 - cols)
					return true;

				i += cols;
			}
			return false;
		}

		else if (y1 >= y2)
		{
			for (int i = stt_gd2 + cols; i <= x2chay / 5 + y1 / 3 * cols;)
			{
				if (kt[i].ch != ' ')
					break;
				if (i == x2chay / 5 + y1 / 3 * cols)
					return true;
				i += cols;
			}

			for (int i = x1chay / 5 + y2 / 3 * cols; i <= stt_gd1 - cols;)
			{
				if (kt[i].ch != ' ')
					break;
				if (i == stt_gd1 - cols)
					return true;
				i += cols;
			}
			return false;
		}
	}
}
bool check_zic_zac_ngang(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int posleft = pos1 + 1;
	int posright = pos2 - 1;
	int xlchay = x1 + 5;
	int xrchay = x2 - 5;

	/*if (kt[posleft].ch != ' ' || kt[posright].ch != ' ')
		return false;*/

	if (y1 < y2)
	{
		if (kt[posleft].ch == ' ' && kt[posright].ch == ' ')
		{
			if (xlchay == xrchay)
			{
				for (int i = posleft + cols; i <= posright - cols; )
				{
					if (kt[i].ch != ' ')
						return false;

					if (i == posright - cols)
						return true;
					i += cols;
				}
			}
			else
			{
				while (kt[posleft].ch == ' ')
				{
					xlchay += 5;
					posleft += 1;
					if (xlchay >= 5 * cols + 4)
						break;
				}

				while (kt[posright].ch == ' ')
				{
					xrchay -= 5;
					posright -= 1;
					if (xrchay <= -1)
						break;
				}

				xlchay -= 5;
				posleft -= 1;
				xrchay += 5;
				posright += 1;

				if (xlchay < xrchay) return false;

				if (xlchay == xrchay)
				{
					for (int i = posleft + cols; i <= xlchay / 5 + y2 / 3 * cols;)
					{
						if (kt[i].ch != ' ')
							return false;

						i += cols;
					}

					return true;
				}
				else
				{
					for (int i = xrchay / 5 + y1 / 3 * cols; i <= posright - cols;)
					{
						if (kt[i].ch != ' ')
							break;

						if (i == posright - cols)
							return true;

						i += cols;
					}

					for (int i = posleft + cols; i <= xlchay / 5 + y2 / 3 * cols;)
					{
						if (kt[i].ch != ' ')
							break;

						if (i == xlchay / 5 + y2 / 3 * cols)
							return true;

						i += cols;
					}

					return false;
				}
			}
		}
	}

	else if (y1 > y2)
	{
		if (kt[posleft].ch == ' ' && kt[posright].ch == ' ')
		{
			if (xlchay = xrchay)
			{
				for (int i = posright + cols; i <= posleft - cols; )
				{
					if (kt[i].ch != ' ')
						return false;

					if (i == posleft - cols)
						return true;

					i += cols;
				}
			}
			else
			{
				while (kt[posleft].ch == ' ')
				{
					xlchay += 5;
					posleft += 1;
					if (xlchay >= 5 * cols + 4)
						break;
				}

				while (kt[posright].ch == ' ')
				{
					xrchay -= 5;
					posright -= 1;
					if (xrchay <= -1)
						break;
				}

				xlchay -= 5;
				posleft -= 1;
				xrchay += 5;
				posright += 1;

				if (xlchay < xrchay) return false;

				if (xlchay == xrchay)
				{
					for (int i = posright + cols; i <= xrchay / 5 + y1 / 3 * cols;)
					{
						if (kt[i].ch != ' ')
							return false;

						i += cols;
					}

					return true;
				}
				else
				{
					for (int i = posright + cols; i <= xrchay / 5 + y1 / 3 * cols;)
					{
						if (kt[i].ch != ' ')
							break;

						if (i == xrchay / 5 + y1 / 3 * cols)
							return true;

						i += cols;
					}

					for (int i = xlchay / 5 + y2 / 3 * cols; i <= pos1 - cols;)
					{
						if (kt[i].ch != ' ')
							break;

						if (i == pos1 - cols)
							return true;

						i += cols;
					}

					return false;
				}
			}
		}
	}
}
bool check_zic_zac_doc(int x1, int y1, int x2, int y2)
{
	int pos1 = x1 / 5 + y1 / 3 * cols;
	int pos2 = x2 / 5 + y2 / 3 * cols;
	int postop = pos1 + cols;
	int posbot = pos2 - cols;
	int y1chay = y1 + 3;
	int y2chay = y2 - 3;

	/*if (kt[postop].ch != ' ' || kt[posbot].ch != ' ')
		return false;*/


	if (x1 < x2)
	{
		if (kt[postop].ch == ' ' && kt[posbot].ch == ' ')
		{
			if (y1chay == y2chay)
			{
				for (int i = postop + 1; i <= posbot - 1; i++)
				{
					if (kt[i].ch != ' ')
						return false;
				}
				return true;
			}
		}

		

		while (kt[postop].ch == ' ')
		{
			y1chay += 3;
			postop += cols;
			if (y1chay >= 3 * lines + 3)
				break;
		}
		while (kt[posbot].ch == ' ')
		{
			y2chay -= 3;
			postop -= cols;
			if (y2chay <= -1)
				break;
		}

		y1chay -= 3;
		postop -= cols;
		y2chay += 3;
		posbot += cols;


		if (y1chay == y2chay)
		{
			for (int i = postop + 1; i <= posbot - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
		else
		{
			for (int i = postop + 1; i <= x2 / 5 + y1chay / 3 * cols; i++ )
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x2 / 5 + y1chay / 3 * cols)
					return true;
			}

			for (int i = x1 / 5 + y2chay / 3 * cols; i <= posbot - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
	}
	else if (x1 > x2)
	{
		if (kt[postop].ch == ' ' && kt[posbot].ch == ' ')
		{
			if (y1chay == y2chay)
			{
				for (int i = posbot + 1; i <= postop - 1; i++)
				{
					if (kt[i].ch != ' ')
						return false;
				}
				return true;
			}
		}

		if (kt[postop].ch != ' ' || kt[posbot].ch != ' ')
			return false;

		while (kt[postop].ch == ' ')
		{
			y1chay += 3;
			postop += cols;
			if (y1chay >= 3 * lines + 3)
				break;
		}
		while (kt[posbot].ch == ' ')
		{
			y2chay -= 3;
			posbot -= cols;
			if (y2chay <= -1)
				break;
		}

		y1chay -= 3;
		postop -= cols;
		y2chay += 3;
		posbot += cols;

		if (y1chay == y2chay)
		{
			for (int i = posbot + 1; i <= postop - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
		else
		{
			for (int i = posbot + 1; i <= x1 / 5 + y2chay / 3 * cols; i++)
			{
				if (kt[i].ch != ' ')
					break;

				if (i == x1 / 5 + y2chay / 3 * cols)
					return true;
			}

			for (int i = y1chay / 3 * cols + x2 / 5; i <= postop - 1; i++)
			{
				if (kt[i].ch != ' ')
					return false;
			}
			return true;
		}
	}
	
}
// các hàm dùng để kiểm tra matching
void xoa_phan_tu(ki_tu* arr, int vt, int& n)
{
	for (int i = vt; i < n - 1; i++)
	{
		arr[i].ch = arr[i + 1].ch;
	}
	n--;
}
// cái hàm này để kiểm soát coi lượng kí tự đúng ko 
void printChar(ki_tu* kt)
{
	/*for (int i = 0; i < 126; i++)
		cout << i << " " <<  kt[i].ch << endl;*/
		/*int thu_tu = 0;
		int slkt = 0;
		int so_luong = cols * lines;
		int start_sau = (cols * lines) / 2;
		int* check = new int[cols * lines];
		for (int i = 0; i < cols * lines; i++)
			check[i] = 0;
		for (int i = 0; i < (cols * lines) / 2; i++)
		{
			for (int j = start_sau; j < so_luong; j++)
			{
				if (kt[i].ch == kt[j].ch && check[j] == 0)
				{
					check[j] = 1;
					cout << thu_tu++ << setw(4) << i << " " << kt[i].ch << setw(4) << j << " " << kt[j].ch << endl;
					break;
				}
			}
		}*/
}