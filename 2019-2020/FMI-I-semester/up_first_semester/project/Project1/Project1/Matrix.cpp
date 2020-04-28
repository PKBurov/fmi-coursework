#include <iostream>
#include <windows.h>	
#include <stdlib.h>	
#include <ctime>
#include <chrono>
#include <thread>		

using namespace std;
HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
const int MATRIX_WIDTH = 120,MATRIX_HEIGHT = 24,SLEEP = 75, GREEN = 10,DARKGREEN = 2,DARKWHITE = 7,WHITE = 15;

void XyCoord(int x, int y) {
	COORD axis_coordinates;
	axis_coordinates.X = x;
	axis_coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), axis_coordinates);
}
void printElement(int x,int y, int RandStop, char first_element, char second_element, int mainColor, int contrastColor)
{
	COORD axis_coordinates;
	axis_coordinates.X = x;
	axis_coordinates.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), axis_coordinates);

	if (y == RandStop - 1) {
		SetConsoleTextAttribute(color, contrastColor);
		cout << first_element;
	}
	else if (y == MATRIX_HEIGHT);
	else {
		SetConsoleTextAttribute(color, mainColor);
		cout << second_element;
		this_thread::sleep_for(chrono::milliseconds(SLEEP - 50));
	}
}
int main() {

	srand(time_t(NULL));
	int x,y,RandStop,bonusElement; //we use RandStop to end the column at random moment
	const char element[] = "QWERTYUIOPLKJHGFDSAZXCVBNM [];'1234567890!@#$%^&*()_+";
	int len = strlen(element);
	while (true) {
		for (int i = 0; i < MATRIX_WIDTH; i++) {
			bonusElement = rand() % MATRIX_HEIGHT; // 0-23
			x = rand() % MATRIX_WIDTH; //Random number from 0-119;
			y = rand() % MATRIX_HEIGHT; // Random number from 0 - 23;
			RandStop = rand() % MATRIX_HEIGHT; // Rand number from 0-23;
			int clear = rand() % MATRIX_WIDTH; // Rand number 0-129
			int FSMinRandMatrix = y-bonusElement;
			int SMinRandMatrix = x-bonusElement;
			int FMaxRandMatrix = x+bonusElement;
			int SMaxRandMatrix = y+bonusElement;

			while (y < MATRIX_HEIGHT) {
				int randomElements = element[rand() % len];
				printElement(x, y, RandStop, randomElements, randomElements, DARKGREEN, DARKWHITE);
				if (y >= bonusElement && x >= bonusElement) {
					int randomElements = element[rand() % len];
					printElement(SMinRandMatrix, FSMinRandMatrix, RandStop, randomElements, randomElements, DARKGREEN, DARKWHITE);
				}else if (y >= bonusElement && x <= MATRIX_WIDTH - bonusElement) {
					int randomElements = element[rand() % len];
					printElement(FMaxRandMatrix, FSMinRandMatrix, RandStop, randomElements, randomElements, DARKGREEN, DARKWHITE);
				}if (x <= MATRIX_WIDTH - bonusElement && y <= MATRIX_HEIGHT - bonusElement) {
					int randomElements = element[rand() % len];
					printElement(FMaxRandMatrix, SMaxRandMatrix, RandStop, randomElements, randomElements, DARKGREEN, DARKWHITE);
				}else if (x >= bonusElement && y <= MATRIX_HEIGHT - bonusElement) {
					int randomElements = element[rand() % len];
					printElement(SMinRandMatrix, SMaxRandMatrix, RandStop, randomElements, randomElements, DARKGREEN, DARKWHITE);
				}
				//Clear
				XyCoord(clear, y);
				printElement(clear, y, RandStop, ' ', ' ', DARKGREEN, DARKWHITE);
				y++;
				if (y == RandStop)
					break;
			}
			this_thread::sleep_for(chrono::milliseconds(SLEEP));
		}
	}
	return 0;
}