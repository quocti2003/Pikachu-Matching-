#include <iostream>
#include "my_lib.h"
#include "Intro.h"
#include "PlayStandard.h"
using namespace std; 
void main()
{
	printPikachu();
	selectionMenu();
	/*_getch();*/
	/*printBoard(2, 91, 1, 21);*/
	if (menu_choice == 1)
	{
		ifstream fi;
		SetColor(15);
		settings();
		printBoard(2, cols * 5 + 1, 1, lines * 3);
		sinh_ngau_nhien_ki_tu();
		/*for (int i = 0; i <= (5 * cols - 1) / 5; i++)
			kt[i - cols].ch = ' ';
		for (int i = cols * lines - cols; i <= cols * lines - 1; i++)
			kt[i + cols].ch = ' ';*/
		printboardwithChar();
		ShowCur(0);
		_getch();
	}
	else if (menu_choice == 3)
	{
		cout << "THANKS FOR USING OUR PRODUCT.";
		ShowCur(0);
		return;
	}
}

