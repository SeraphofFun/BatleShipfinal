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
void clearConsole() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
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

void botcreateboard(int(*arr)[10]) {
	srand(unsigned int(time(NULL)));

	int max = 10;
	int d;
	int ship;
	int randomx = 0;
	int randomy = 0;
	int po = 0;
	for (int i = 0; i < 1;)
	{
		ship = 4;
		d = 1 + rand() % (2);
		if (d == 1)
		{
			int max_index = 10 - ship;
			randomy = rand() % (max_index + 1);
			randomx = rand() % (max);

		}
		else
		{
			int max_index = 10 - ship;
			randomy = rand() % (max);
			randomx = rand() % (max_index + 1);

		}
		if (rules(randomx, randomy, arr, 4, d) && rules2(randomx, randomy, d, ship)) {

			for (int j = 0; j < ship; j++)
			{
				if (d == 1)
					arr[randomx][randomy + j] = ship + po * 10;
				else
					arr[randomx + j][randomy] = ship + po * 10;
			}

			i++;
		}
	}
	for (int i = 0; i < 2; )
	{
		ship = 3;
		d = 1 + rand() % (2);
		if (d == 1)
		{
			int max_index = 10 - ship;
			randomy = rand() % (max_index + 1);
			randomx = rand() % (max);

		}
		else
		{
			int max_index = 10 - ship;
			randomy = rand() % (max);
			randomx = rand() % (max_index + 1);

		}
		if (rules(randomx, randomy, arr, 3, d) && rules2(randomx, randomy, d, ship)) {

			for (int j = 0; j < ship; j++)
			{
				if (d == 1)
					arr[randomx][randomy + j] = ship + po * 10;
				else if (randomx + j < 10)
					arr[randomx + j][randomy] = ship + po * 10;
			}
			i++;
			po++;

		}
	}


	for (int i = 0; i < 4; )
	{

		ship = 1;
		randomy = rand() % max;
		randomx = rand() % max;
		d = 1;
		if (rules(randomx, randomy, arr, 1, d) && rules2(randomx, randomy, d, ship)) {
			arr[randomx][randomy] = ship + po * 10;
			i++;
			po++;
		}
	}
	for (int i = 0; i < 3; )
	{

		ship = 2;
		d = 1 + rand() % (2);
		if (d == 1)
		{
			int max_index = 10 - ship;
			randomy = rand() % (max_index + 1);
			randomx = rand() % (max);

		}
		else
		{
			int max_index = 10 - ship;
			randomy = rand() % (max);
			randomx = rand() % (max_index + 1);

		}

		if (rules(randomx, randomy, arr, ship, d) && rules2(randomx, randomy, d, ship)) {

			for (int j = 0; j < ship; j++)
			{
				if (d == 1)
					arr[randomx][randomy + j] = ship + po * 10;
				else
					arr[randomx + j][randomy] = ship + po * 10;
			}
			i++;
			po++;
		}
	}

}

enum selectship {
	oneMship = 1,
	twoMship,
	threeMship,
	fourMship
};
bool correct(int(*arr)[10], int(*arr2)[10]) {
	int say = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ((arr[i][j] == 8 || arr[i][j] >= 1) && arr[i][j] != 5)
			{
				say++;
			}

		}

	}
	if (say == 20)
		return true;
	else
		return false;
}
void comparer(int(*arrg)[10], int(*arr)[10], int x, int y) {
	int ship = arr[x][y] % 10;
	int chckguess = 0;
	int chck = 0;
	if (arr[x][y] % 10 > 1)
	{
		arrg[x][y] = arr[x][y];
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (arr[x][y] == arr[i][j])
				{
					chck++;
				}
				if (arr[x][y] == arrg[i][j])
				{
					chckguess++;
				}

			}

		}
		if (chck == chckguess)
		{
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{


					if (arr[x][y] == arrg[i][j])
					{
						arrg[i][j] = 8;
					}

				}

			}
		}

	}
	else
		arrg[x][y] = 8;

}
void shipguess(int& x, int& y, int go, int(*arrg)[10], int(*arr)[10]) {

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arrg[i][j] < 0)
			{
				arrg[i][j] = 0;
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
		if (arr[x][y] == 0)
			arrg[x][y] = 5;
		else
			comparer(arrg, arr, x, y);
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
	if (!(arrg[x][y] > 0))
		arrg[x][y] = -1;


}

int comparehuman(int(*arr)[10], int(*arrg)[10], int& x, int& y) {
	int go = getch();
	shipguess(x, y, go, arrg, arr);
	return go;
}

bool isValidMove(int x, int y, int(*arr)[10], int(*arrg)[10]) {
	return x >= 0 && x < 10 && y >= 0 && y < 10 && arrg[x][y] == 0;
}


int comparerobot(int(*arr)[10], int(*arrg)[10], int& xf, int& yf, int* xpoint, int* ypoint) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(0, 9);

	int b = 0;
	int randomx = 0, randomy = 0;


	if (*xpoint != -1 && *ypoint != -1) {
		int x = *xpoint, y = *ypoint;

		if (arrg[x][y] > 0 && arrg[x][y] != 8 && arrg[x][y] != 5) {
			if (isValidMove(x + 1, y, arr, arrg)) { randomx = x + 1; randomy = y; }
			else if (isValidMove(x - 1, y, arr, arrg)) { randomx = x - 1; randomy = y; }
			else if (isValidMove(x, y + 1, arr, arrg)) { randomx = x; randomy = y + 1; }
			else if (isValidMove(x, y - 1, arr, arrg)) { randomx = x; randomy = y - 1; }
			else {
				do {
					randomx = distr(gen);
					randomy = distr(gen);
				} while (arrg[randomx][randomy] != 0);
			}
		}
	}
	else {
		do {
			randomx = distr(gen);
			randomy = distr(gen);
		} while (arrg[randomx][randomy] != 0);
	}

	xf = randomx;
	yf = randomy;

	if (arr[randomx][randomy] > 0 && arrg[randomx][randomy] == 0) {
		comparer(arrg, arr, randomx, randomy);

		if (arrg[randomx][randomy] == 8) {
			*xpoint = -1;
			*ypoint = -1;
		}
		else if (arrg[randomx][randomy] > 0 && arrg[randomx][randomy] != 5) {
			*xpoint = randomx;
			*ypoint = randomy;
		}
		b = 1;
	}
	else if (arrg[randomx][randomy] > 0) {
		b = 2;
	}
	else {
		b = 0;
		arrg[randomx][randomy] = 5;
	}

	return b;
}
void boardcreatecomp(int(*arrO)[10], int(*arr1)[10], int(*arr2)[10], int x, int y) {
	cout << "\033[31mPlayer 1\t\t\t\t\tPlayer 2\n\n\033[0m";

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{

			if (arr1[i][j] == 5)
				cout << "\033[34mxx\033[0m";
			else if (arr1[i][j] == 8)
				cout << "\033[35mux\033[0m";
			else if (arr1[i][j] > 0)
				cout << "\033[32muu\033[0m";
			else if (arr1[i][j] < 0) {
				cout << "uu";
			}

			else
				cout << "[]";
		}
		cout << "\t\t\t\t";
		for (int j = 0; j < 10; j++)
		{

			if (arr2[i][j] == 5)
				cout << "\033[34mxx\033[0m";
			else if (arr2[i][j] < 0)
				cout << "\033[36m[]\033[0m";
			else if (arr2[i][j] == 8)
				cout << "\033[35mux\033[0m";
			else if (arr2[i][j] > 1) {
				cout << "\033[96mux\033[0m";
			}
			else
				cout << "[]";
		}
		cout << endl;

	}


}
void sndpartofthegame(int(*arr)[10], int(*arr2)[10]) {
	clearConsole();
	int arrguess[10][10] = { 0 };
	int arrguess2[10][10] = { 0 };
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int fx = 0;
	int fy = 0;
	int& fx_ref = fx;
	int& fy_ref = fy;
	int kol = 0;
	int link = 0;
	int* dlenx = new int(-1);
	int* dleny = new int(-1);
	while (!(correct(arrguess, arr) || correct(arrguess2, arr2)))
	{

		int y = 0;

		do {
			y = comparehuman(arr2, arrguess, x1, y1);
			clearConsole();
			boardcreatecomp(arr, arrguess2, arrguess, x1, y1);
			if (arrguess[x1][y1] == 5 && y == 13)
				break;
			cout << "Your turn" << endl;
			cout << "\nTurn = " << ++link << endl << "Go = " << y << endl;
		} while (true);
		if (correct(arrguess, arr))
			break;

		do {
			comparerobot(arr, arrguess2, fx_ref, fy_ref, dlenx, dleny);
			clearConsole();
			boardcreatecomp(arr, arrguess2, arrguess, x1, y1);
			cout << "Machine turn" << endl;
			cout << "\nTurn = " << link << endl << "Go = " << y << endl;

		} while (arrguess2[fx][fy] != 5);

	}
	if (correct(arrguess, arr))
		cout << "HUMAN WON!!!" << endl;
	else
		cout << "Machine won!" << endl;
	cout << endl << endl << "Are you done?" << endl << endl << "\033[33mPRESS ENTER TO END\033[0m";
	int win = 0;
	do
	{
		win = getch();
	} while (win != 13);


}
void goongame(int(*arr)[10], int(*arr2)[10]) {
	cout << endl << endl << "Are you ready?" << endl << endl << "\033[33mPRESS ENTER\033[0m";

	int i = getch();
	if (i == 13) {
		sndpartofthegame(arr, arr2);
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


void gamebeginhvsrr() {
	int arrhumancreate[10][10] = { 0 };
	int arrbotcreate[10][10] = { 0 };
	botcreateboard(arrbotcreate);
	botcreateboard(arrhumancreate);
	clearConsole();
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (arrhumancreate[i][j] > 0)
				cout << "\033[32muu\033[0m";
			else if (arrhumancreate[i][j] < 0) {
				cout << "uu";
			}


			else
				cout << "[]";
		}
		cout << endl;

	}
	cout << endl << "Continue? Press Enter";
	while (true) {
		int t = getch();
		if (t == 13)
			break;
	}
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

