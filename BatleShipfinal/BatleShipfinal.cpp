#include <iostream>
#include <stdio.h>
#include <windows.h>  
#include <conio.h>
#include<cstdlib>
#include<ctime>
#include <random>
using namespace std;
using namespace std;
void ResetColor() { cout << "\033[0m"; }
void SetColor(int textColor)
{
	cout << "\033[" << textColor << "m";
}

int key_up = 72;
int key_down = 80;
int key_left = 75;
int key_right = 77;
int po = 0;

void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
void menu() {

	int i = 0;
	bool select = false;
	while (true)
	{
		po = 0;
		int f = getch();

		switch (f)
		{
		case (72):
			i--;
			break;
		case (80):
			i++;
			break;
		case (13):
			selection(i);
			break;
		default:
			break;
		}
		if (i == 0)
		{
			i = 3;
		}
		if (i == 4)
			i = 1;
		switch (i)
		{
		case(1):

		default:




			break;
		}
		clearConsole();
		cout << "\033[34mBatle Ships!\033[0m\n\n";
		cout << "\tBot Vs Human";
		i == 1 && cout << "\033[32m<\033[0m";
		cout << endl;
		cout << "\tBot Vs Bot"; i == 2 && cout << "\033[32m<\033[0m";
		cout << endl;
		cout << "\tHuman VS Bot Random"; i == 3 && cout << "\033[32m<\033[0m";

	}

}

int main()
{
	menu();
	return 0;
}

