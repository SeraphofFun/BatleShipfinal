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

int main()
{
    cout << "Hello World!\n";
}

