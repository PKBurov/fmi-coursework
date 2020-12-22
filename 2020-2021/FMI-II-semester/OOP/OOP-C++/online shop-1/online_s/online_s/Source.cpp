#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
#include "product.h"
#include "Inventory.h"
#include "ShoppingCart.h"
#include "Laptop.h"
#pragma warning(disable: 4996)
using namespace std;

void login();
void registr();
void forgot();

int main() {
	ShoppingCart shoppingCart;
	Inventory inventory;
	/*Item first("Glass", 20, 10, "CategoryGlass", 1);
	Item second("Soup", 30, 10, "SoupInc", 2);
	inventory.addItem(first);
	inventory.addItem(second);*/
	//Tests

	vector<Laptop> laptop;
	vector<SmartPhones> smartp;
	vector<Watches> watch;

	Item futureAdd;
	Item Sc;
	Item Therd;

	SmartPhones smp;
	//
	smp.setName("Iphone X");
	smp.SetBattery(7);
	smp.SetColor("Black");
	smp.setID(32156);
	smp.setCategory("Apple");
	smp.SetOperative_System("IOS");
	smp.setPrice(1234);
	smp.setQuantity(40);
	smp.SetRam(8);
	smp.SetRess(6);
	smp.SetWeight(200);

	smartp.push_back(smp);
	inventory.addSmartPhone(smp);
	//
	Watches wch;
	wch.setName("OMEGA III");
	wch.setCategory("Omega");
	wch.setID(67213);
	wch.setPrice(6599);
	wch.setQuantity(40);

	wch.SetWatchGlass("Fiber");
	wch.SetWatchMaterial("Titanium");
	wch.SetWatchMovement("Analog");
	wch.SetWatchWaterRess("Yes-To 120 ft");

	watch.push_back(wch);
	inventory.addWatch(wch);
	//
	Laptop lap;
	lap.setName("XPS");
	lap.setBattery(8);
	lap.setCategory("Dell");
	lap.setPrice(2304);
	lap.SetProcesor("Intel Core I9");
	lap.setQuantity(20);
	lap.setRess(15);
	lap.setID(45123);
	laptop.push_back(lap);
	inventory.addLaptop(lap);
	


	int choice = 0;
	int adminChoice = 0;
	int login_yn = 0;
	int regChoice = 0;
	int customerChoice = 0;
						/////////////////////////////////////////////MAIN MENU///////////////////////////////////
	for (;;) {
	MainMenu:
		std::cout<<":: MAIN MENU ::"<<"\n";
		std::cout<<"1. Customer"<<"\n";
		std::cout<<"2. Exit" << "\n";
		do{
			std::cout<< "Enter your choice: ";
			std::cin >> choice;
			fflush(stdin);
		} while (!(choice >= 1 && choice <= 3));
		std::cout <<"Your choice: "<< choice << "\n" << "\n"; //избор
		switch (choice){
			case 1:
			{
				/////////////////////////////////////////////CUSTOMER MENU/////////////////////////////////////////////////
				for (;;) {
					std::cout << ":: CUSTOMER MENU :: " << "\n";
					std::cout << "1. Register/LogIn *not Made* " << "\n";
					std::cout << "2. Continue as guest" << "\n";
					std::cout << "3. Back" << "\n";
					do {
						std::cout << "Enter your choice: ";
						std::cin >> regChoice;
						fflush(stdin);
					} while (!(regChoice >= 1 && regChoice <= 3));
					std::cout << "Your choice: " << regChoice << "\n" << "\n"; //избор
					switch (regChoice) {
					case 1:
					RegisteredCustomer: ///////////////////////////////////////////////////
					{
						int choice;
						cout << "***********************************************************************\n\n\n";
						cout << "                      Welcome to login page                               \n\n";
						cout << "*******************        MENU        *******************************\n\n";
						cout << "1.LOGIN" << endl;
						cout << "2.REGISTER" << endl;
						cout << "3.FORGOT PASSWORD (or) USERNAME" << endl;
						cout << "4.Exit" << endl;
						cout << "\nEnter your choice :";
						cin >> choice;
						cout << endl;
						switch (choice)
						{
						case 1:
							login();
							break;
						case 2:
							registr();
							break;
						case 3:
							forgot();
							break;
						case 4:
							cout << "Thanks for using this login menu";
							if (login_yn == 1) { goto CostumerMenu; }
							break;
						default:
							system("cls");
							cout << "You've made a mistake , give it a try again\n" << endl;
							main();
						}
					}
					////////////////////////////////////////////REGISTER////////////////////////////////////
					break;
					case 2:
						///////////////////////////////////////CONTINUE AS GUESST////////////////////////////////////////
					CostumerMenu:
						std::cout << ":: CUSTOMER MENU ::" << "\n";
						std::cout << "1. List items" << "\n";
						std::cout << "2. Add item to cart" << "\n";
						std::cout << "3. Remove item from cart" << "\n";
						std::cout << "4. List items in cart" << "\n";
						std::cout << "5. Search engine *for sup menus of the categories* *not ready* " << "\n";
						std::cout << "6. Purchase" << "\n";
						std::cout << "7. Back" << "\n";
						// Search by category & purchase;
						do {
							std::cout << "Enter your choice: ";
							std::cin >> customerChoice;
							fflush(stdin);
						} while (!(customerChoice >= 1 && customerChoice <= 7));
						std::cout << "Your choice: " << customerChoice << "\n" << "\n";
						switch (customerChoice)
						{
						case 1:
							cout << "::ITEMS::" << "\n";
							inventory.Display();
							cout << "\n" << "\n";
							goto CostumerMenu;
						case 2:
						{
							std::cout << "Enter code of item: ";
							int code;
							cin >> code;
							futureAdd = inventory.searchLaptop(code);
							/*futureAdd = inventory.searchSmartp(code);
							futureAdd = inventory.searchWatch(code);*/

							shoppingCart.addItem(futureAdd, lap);
							/*shoppingCart.addItem(Sc, smp);
							shoppingCart.addItem(Therd, wch);*/

							shoppingCart.Display(futureAdd, lap);
							/*shoppingCart.Display(Sc, smp);
							shoppingCart.Display(Therd, wch);*/
							cout << "\n" << "\n";
							goto CostumerMenu;
						}
						case 3:
							cout << "Items in cart:" << endl;
							shoppingCart.Display(futureAdd, lap);
							/*shoppingCart.Display(Sc, smp);
							shoppingCart.Display(Therd, wch);*/
							int index;
							cout << "Enter: ";
							cin >> index;
							shoppingCart.RemoveItem(index);
							shoppingCart.Display(futureAdd, lap);
							cout << "\n";
							goto CostumerMenu;
						case 4:
						{
							//Needs to be In one func
							shoppingCart.Display(futureAdd, lap);
							/*shoppingCart.Display(Sc, smp);
							shoppingCart.Display(Therd, wch);*/
							goto CostumerMenu;
						}
						case 5:
						{
							/*
							int id;
							cout << "Enter item Id" << "\n";
							cin >> id;
							int pos = shoppingCart.searchItem(id);
							std::cout << "position: " << pos << endl;
							cout << "\n";
							*/
						}
						case 6:
							cout << "Do you have an account? " << endl << endl;
							if (login_yn == 1) {

							}
							else {
								goto RegisteredCustomer;
							}
						case 7:
							break;
						}

					case 3:
						goto MainMenu;
					}
				}
			}
			case 2:
			{
				exit(3);
			}
		}
	}
	return 0;
}

void login()
{
	int count;
	string user, pass, u, p;
	system("cls");
	cout << "please enter the following details" << endl;
	cout << "USERNAME :";
	cin >> user;
	cout << "PASSWORD :";
	cin >> pass;

	ifstream input("database.txt");
	while (input >> u >> p)
	{
		if (u == user && p == pass)

		{
			count = 1;
			system("cls");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nHello" << user << "\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
		cin.get();
		cin.get();
		main();
	}
	else
	{
		cout << "\nLOGIN ERROR\nPlease check your username and password\n";
		main();
	}
}
void registr()
{

	string reguser, regpass, ru, rp;
	system("cls");
	cout << "Enter the username :";
	cin >> reguser;
	cout << "\nEnter the password :";
	cin >> regpass;

	ofstream reg("database.txt", ios::app);
	reg << reguser << ' ' << regpass << endl;
	system("cls");
	cout << "\nRegistration Sucessful\n";
	main();


}
void forgot()
{
	int ch;
	system("cls");
	cout << "Forgotten ? We're here for help\n";
	cout << "1.Search your id by username" << endl;
	cout << "2.Search your id by password" << endl;
	cout << "3.Main menu" << endl;
	cout << "Enter your choice :";
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		int count = 0;
		string searchuser, su, sp;
		cout << "\nEnter your remembered username :";
		cin >> searchuser;

		ifstream searchu("database.txt");
		while (searchu >> su >> sp)
		{
			if (su == searchuser)
			{
				count = 1;
			}
		}
		searchu.close();
		if (count == 1)
		{
			cout << "\n\nHurray, account found\n";
			cout << "\nYour password is " << sp;
			cin.get();
			cin.get();
			system("cls");
			main();
		}
		else
		{
			cout << "\nSorry, Your userID is not found in our database\n";
			cout << "\nPlease kindly contact your system administrator for more details \n";
			cin.get();
			cin.get();
			main();
		}
		break;
	}
	case 2:
	{
		int count = 0;
		string searchpass, su2, sp2;
		cout << "\nEnter the remembered password :";
		cin >> searchpass;

		ifstream searchp("database.txt");
		while (searchp >> su2 >> sp2)
		{
			if (sp2 == searchpass)
			{
				count = 1;
			}
		}
		searchp.close();
		if (count == 1)
		{
			cout << "\nYour password is found in the database \n";
			cout << "\nYour Id is : " << su2;
			cin.get();
			cin.get();
			system("cls");
			main();
		}
		else
		{
			cout << "Sorry, We cannot found your password in our database \n";
			cout << "\nkindly contact your administrator for more information\n";
			cin.get();
			cin.get();
			main();
		}

		break;
	}

	case 3:
	{
		cin.get();
		main();
	}
	default:
		cout << "Sorry, You entered wrong choice. Kindly try again" << endl;
		forgot();
	}
}