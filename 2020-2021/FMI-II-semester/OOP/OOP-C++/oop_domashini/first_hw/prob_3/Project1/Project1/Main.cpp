#include "Rectangle.h"
#include "Storage.h"
#include <iostream>

using namespace std;
int main() {
	cout << "Welcome." << endl;
	cout << "For each rectangle enter coordinates of Point A and Point B.Enter any symbol to continue." << endl;
	char* neW = new char[1000];
	std::cin >> neW;
	if (neW != " ") {
		char Menu;
		Storage Storage;
		while (true) {
			cout << "Choice" << endl;
			cout << "1:   Add new rectangle." << endl;
			cout << "2:   Display rectangle." << endl;
			cout << "3:   Quit." << endl;
			cin >> Menu;
			switch (Menu) {
			case '1':
			{
				Shape first;
				cout << "Enter the details of the rectangle you want to add." << endl;
				first.Create();
				Storage.Add(first);
				break;
			}
			case '2':
				Storage.Display();
				break;
				
			case '3':
				cin.get();
				break;
			}
		}
	}
}