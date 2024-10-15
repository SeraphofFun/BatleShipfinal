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
bool rules(int x, int y, int(*arr)[10], int ship, int d) {
	if (d == 1) {
		if (y + ship > 10) return false;
	}
	else {
		if (x + ship > 10) return false;
}

	for (int i = 0; i < ship; i++) {
		int currentX = (d == 1) ? x : x + i;
		int currentY = (d == 1) ? y + i : y;

		if (arr[currentX][currentY] == 1) return false;


		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				int newX = currentX + dx;
				int newY = currentY + dy;
				if (newX >= 0 && newX < 10 && newY >= 0 && newY < 10) {
					if (arr[newX][newY] > 0) return false;
				}
			}
		}
	}

	return true;
}

bool rules2(int x, int y, int d, int ship) {
	bool b;
	if (d == 1)
	{
		if (y + ship > 10)
			b = false;
		else
			b = true;
	}
	else {
		if (x + ship > 10)
			b = false;
		else
			b = true;
	}
	return  b;
}
void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}
void enteringship(int x, int y, int ship, int d, int(*arr)[10]) {

	if (rules(x, y, arr, ship, d) && rules2(x, y, d, ship))
	{
		for (int i = 0; i < ship; i++)
		{
			if (d == 1)
				arr[x][y + i] = ship + po * 10;

			else
				arr[x + i][y] = ship + po * 10;

		}
		po++;
	}


}
void shipcordinates(int& x, int& y, int go, int ship, int& d, int(*arr)[10]) {

	int tx = x;
	int ty = y;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] < 0)
			{
				arr[i][j] = 0;
			}

		}
	}
	switch (go)
	{

	case(72):
		x--;
		break;
	case(80):
		x++;
		break;
	case(75):
		y--;
		break;
	case (77):
		y++;
		break;
	case (13):
		if (rules(x, y, arr, ship, d))
			enteringship(tx, ty, ship, d, arr);
		break;
	case(32):
		d == 1 ? d = 2 : d = 1;
		break;
	default:
		break;
	}
	if (x >= 10)
		x = 0;
	if (y >= 10)
		y = 0;
	if (x < 0)
		x = 9;
	if (y < 0)
		y = 9;

	if (arr[tx][ty] <= 0)
	{
		arr[tx][ty] = 0;


		for (int i = 0; i < ship; i++)
		{
			if (d == 1) {

				if (arr[x][y + i] > 0)
					break;
				else
					arr[x][y + i] = -1;
			}

			else {
				if (arr[x + i][y] > 0)
					break;
				else
					arr[x + i][y] = -1;
			}
		}
	}

}

bool findelement(int num, int op, int(*arr)[10]) {
	int l = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] % 10 == num)
			{
				l++;
			}

		}

	}
	if (op * num == l)
		return true;
	else
		return false;
}
void shipcordinates(int& x, int& y, int go, int ship, int& d, int(*arr)[10]) {

	int tx = x;
	int ty = y;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] < 0)
			{
				arr[i][j] = 0;
			}

		}
	}
	switch (go)
	{

	case(72):
		x--;
		break;
	case(80):
		x++;
		break;
	case(75):
		y--;
		break;
	case (77):
		y++;
		break;
	case (13):
		if (rules(x, y, arr, ship, d))
			enteringship(tx, ty, ship, d, arr);
		break;
	case(32):
		d == 1 ? d = 2 : d = 1;
		break;
	default:
		break;
	}
	if (x >= 10)
		x = 0;
	if (y >= 10)
		y = 0;
	if (x < 0)
		x = 9;
	if (y < 0)
		y = 9;

	if (arr[tx][ty] <= 0)
	{
		arr[tx][ty] = 0;


		for (int i = 0; i < ship; i++)
		{
			if (d == 1) {

				if (arr[x][y + i] > 0)
					break;
				else
					arr[x][y + i] = -1;
			}

			else {
				if (arr[x + i][y] > 0)
					break;
				else
					arr[x + i][y] = -1;
			}
		}
	}

}
void board(int x, int y, int ship, int d, int(*arr)[10]) {

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arr[i][j] > 0)
				cout << "\033[32muu\033[0m";
			else if (arr[i][j] < 0) {
				cout << "uu";
			}


			else
				cout << "[]";
		}
		cout << endl;

	}






}

void gamebegin() {
	int arrhumancreate[10][10] = { 0 };
	int arrbotcreate[10][10] = { 0 };
	int x = 0;
	int y = 0;
	arrhumancreate[x][y] = -1;
	int say = 0;
	int d = 1;
	int battleshipsize = 1;
	while (battleshipsize < 5)
	{
		int times = 5 - battleshipsize;
		while (!findelement(battleshipsize, times, arrhumancreate)) {
			int go = getch();
			clearConsole();
			cout << go << endl;
			shipcordinates(x, y, go, battleshipsize, d, arrhumancreate);
			board(x, y, battleshipsize, d, arrhumancreate);
			cout << endl;
			cout << x << ":" << y << endl << endl << endl;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					cout << arrhumancreate[i][j] << " ";
				}
				cout << endl;
			}
			cout << d << endl;
			cout << findelement(times, battleshipsize, arrhumancreate) << endl;


		}
		battleshipsize++;
	}
	botcreateboard(arrbotcreate);
	goongame(arrhumancreate, arrbotcreate);
}

void selection(int b) {
	switch (b)
	{
	case 1:
		gamebegin();
		break;
	case 2:
		gamebeginrvsr();
		break;
	case 3:
		gamebeginhvsrr();
		break;
	default:
		break;
	}


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

