/**
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2019/2020
*
* @author Petar Burov
* @idnumber 62510
* @task 1
* @compiler VC
*/
#include<iostream>
#include<time.h>
using namespace std;
unsigned short int Choice = 0, PlayOrExit = 0,RandomNumber = 0;

//Prototypes
int Randomize();
void Menu();
void PlayerDecision();
const char* QuestionChoosing();

//Global Arrays
const char* QUESTIONS[10] = {

		"Who started their first day at Dunder Mifflin Scranton, In S1E1 " "Pilot" " ?",
		"Who is the patron saint of Spain? ",
		"Which of the following men does not have a chemical element named for him?",
		"Which insect shorted out an early supercomputerand inspired the term " "computer bug" " ?",
		" " "Nephelococcygia" " is the practice of doing what?",
		"Who delivered the less famous two-hour speech that preceded Abraham Lincoln's two-minute Gettysburg Address? ",
		"What letter must appear at the beginning of the registration number of all non-military aircraft in the U.S.?",
		"In the children's book series, where is Paddington Bear originally from? ",
		"Which of these ships was not one of the three taken over by colonists during the Boston Tea Party?",
		"Which First Lady was a ninth-generation descendant of Pocahontas?",
};
const char* ANSWERS[10] = {
	"" "\n" " 1.Jim Halpert " "\n" " 2.Ryan Howard  " "\n" " 3.Michael Scott " "\n" " 4.Erin Hannon",//2 //Correct Answers
	"" "\n" " 1.Sain James  " "\n" " 2.Saint Peter  " "\n" " 3.Saint John    " "\n" " 4.Saint Percy",//1
	"" "\n" " 1.Albert Einstein " "\n" " 2.Niels Bohr  " "\n" " 3.Isaac Newton " "\n" " 4.Enrico Fermi",//3
	"" "\n" " 1.Moth" "\n" " 2.Roach  " "\n" " 3.Fly " "\n" " 4.Japanese beetle",//1
	"" "\n" " 1.Finding shapes in clouds " "\n" " 2.Sleeping with your eyes open  " "\n" " 3.Breaking glass with your voice " "\n" " 4.Swimming in freezing water",//1
	"" "\n" " 1.Wendell Phillips " "\n" " 2.Daniel Webster  " "\n" " 3.Robert G.Ingersoll " "\n" " 4.Edward Everett",//4
	"" "\n" " 1.N " "\n" " 2.A  " "\n" " 3.U " "\n" " 4.L",//1
	"" "\n" " 1.India " "\n" " 2.Peru  " "\n" " 3.Canada " "\n" " 4.Iceland",//2
	"" "\n" " 1.Eleanor " "\n" " 2.Dartmouth  " "\n" " 3.Beaver " "\n" " 4.William",//4
	"" "\n" " 1.Helen Taft " "\n" " 2.Edith Wilson " "\n" " 3.Bess Truman " "\n" " 4.Mamie Eisenhower", //2
};
const char* FIFTY_FIFTY[10] = {
	"" "\n" " " "\n" " 2.Ryan Howard  " "\n" "\n" " 4.Erin Hannon",//2
	"" "\n" " 1.Sain James  " "\n" " 2.Saint Peter  " ,//1
	"" "\n" " 1.Albert Einstein " "\n" "\n" " 3.Isaac Newton ",//3
	"" "\n" " 1.Moth" "\n" "\n"  "\n" " 4.Japanese beetle",//1
	"" "\n" " 1.Finding shapes in clouds " "\n" "\n" " 3.Breaking glass with your voice " "\n",//1
	"" "\n" " " "\n" " 2.Daniel Webster  " "\n"  "\n" " 4.Edward Everett",//4
	"" "\n" " 1.N " "\n" "\n" " 3.U " "\n" ,//1
	"" "\n" " 1.India " "\n" " 2.Peru  " "\n" "\n",//2
	"" "\n" " 1.Eleanor " "\n"  "\n"  "\n" " 4.William",//4
	"" "\n"  "\n" " 2.Edith Wilson " "\n" "\n" " 4.Mamie Eisenhower", //2
};
int main()
{
	int answer = 0, YourAnswer = 0;
	do {
		//Function
		Menu();
		switch (Choice) {
		case 1:
			//First Label:
		jmp:
			PlayOrExit = 0;
			Randomize();
			//Answers
			if (RandomNumber == 1) { answer = 1; }	if (RandomNumber == 6) { answer = 1; }
			if (RandomNumber == 2) { answer = 3; }	if (RandomNumber == 7) { answer = 2; }
			if (RandomNumber == 3) { answer = 1; }	if (RandomNumber == 8) { answer = 4; }
			if (RandomNumber == 4) { answer = 1; }	if (RandomNumber == 9) { answer = 2; }
			if (RandomNumber == 5) { answer = 4; }	if (RandomNumber == 0) { answer = 2; }
			//Output
			cout << endl << "QUESTION IS: \t" << endl << QuestionChoosing() << endl;
			cout << endl << "AVAILABLE ANSWERS: \t" << ANSWERS[RandomNumber] << endl << endl;
			cout << "\t" << "\t" << "\t" << "\t" << "50/50-- Enter number 5" << endl << endl;
			//Second Label:
		second_jmp:
			//Input
			do{
				cout << "Enter your answer:";
				cin >> YourAnswer;
				if (!cin) {
					cin.clear();
					cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				}
			} while (YourAnswer != 1 && YourAnswer != 2 && YourAnswer != 3 && YourAnswer != 4 && YourAnswer != 5 );
			
			if (YourAnswer == 5) {
				cout << endl << "QUESTION IS: \t" << endl << QuestionChoosing() << endl;
				cout << endl << "AVAILABLE ANSWERS AFTER 50/50 : \t" << FIFTY_FIFTY[RandomNumber] << endl << endl;
				//Jump to Second
				goto second_jmp;
			}else if (answer == YourAnswer) {
				cout << endl << "Congratulations,you are right!" << endl << endl;
				PlayerDecision();    //Jump to First
				if (PlayOrExit == 1) { goto jmp; }
				else { exit(1); }
			}else {
				cout << endl << "Incorrect answer!" << endl << endl;
				PlayerDecision();	//Jump to First
				if (PlayOrExit == 1) { goto jmp; }
				else { exit(1); }
			}
			break;
		case 2: exit(1);
		}
	} while (Choice !=1 && Choice !=2);
	_fcloseall();
	return 0;
}
int Randomize() {
	srand((unsigned int)time(NULL));
	RandomNumber = rand() % 10;
	return RandomNumber;
}
void Menu() {
	cout << endl << "\t"
		<< " -----WHO WANTS TO BE A MILLIONAIRE----.\n"
		<< " 1 - START......\n"
		<< " 2 - EXIT.......\n"
		<< " Enter your choice and press return: ";
	//Input Label
Input:
	cin >> Choice;
	//Input Check
	if (!cin) {
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		cout <<" Enter your choice and press return: ";
		goto Input;
	}
}
void PlayerDecision() {
	do{
		cout << "If you wish to Play again enter: 1" << endl;
		cout << "If you wish to Exit enter: 2" << endl;
		//Input
	Input:
		cin >> PlayOrExit;
		//Input Check
		if (!cin) {
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "If you wish to Play again enter: 1" << endl;
			cout << "If you wish to Exit enter: 2" << endl;
			goto Input;
		}
	} while (PlayOrExit !=1 && PlayOrExit !=2);
}
const char* QuestionChoosing() {
	const char* variable;
	variable = QUESTIONS[RandomNumber];

	return variable;
};