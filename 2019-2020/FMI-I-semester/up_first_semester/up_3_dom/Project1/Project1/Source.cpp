#include<iostream>
using namespace std;
//Prototypes
struct Num {
	bool isPositive = true;
	char* number = new char[1];
};
int SymToDec(char num);
char DecToSym(int num);
void NumToRight(int lenght, char* number);
void NumToLeft(int numLenght, char* number);

size_t StrLenght(char* firstArr);
Num SubstactNum(Num, Num);
Num GatherNum(Num, Num);
bool InputForNumber(char& op, Num& number1, Num& number2);

int main() {
	Num input1, input2, result;
	char inputOperator = ' ';
	while (1) {
		if (!InputForNumber(inputOperator, input1, input2)) {
			cout << "Invalid input";
			continue;
		}
		switch (inputOperator) {
		case '-':
			if (input2.isPositive)
				input2.isPositive = false;
			else if (!input2.isPositive)
				input2.isPositive = true;
			result = SubstactNum(input1, input2);
			break;
		case '+':
			result = GatherNum(input1, input2);
			break;
		case '*':
			//
		default:
			cout << "Invalid" << endl;
			continue;
		}
		break;
	}
	if (!result.isPositive) {
		cout << '-';
	}
	cout << result.number;

	delete[] input1.number;
	delete[] input2.number;
	delete[] result.number;
}

Num SubstractNum(Num firstNum, Num secondNum, int Case1 = 0, int Case2 = 1) {
	const int DIFFRENCE = 10;
	int flag = 1;
	Num Nresult;
	delete[] Nresult.number;

	//Checks if negative
	if (!firstNum.isPositive && !secondNum.isPositive) {
		Nresult = GatherNum(firstNum, secondNum);
		Nresult.isPositive = Case1;
		return Nresult;
	}
	//Checks if possitive
	if (firstNum.isPositive && secondNum.isPositive) {
		Nresult = GatherNum(firstNum, secondNum);
		Nresult.isPositive = Case2;
		return Nresult;
	}
	int firstNumLenght = (int)StrLenght(firstNum.number);
	int secondNumLenght = (int)StrLenght(secondNum.number);

	int biggerNumLenght = firstNumLenght;
	int smallerNumLenght = secondNumLenght;

	Nresult.isPositive = firstNum.isPositive;
	bool NeedSwapping = Case1;
	//Bigger Num
	if (firstNumLenght == secondNumLenght) {
		for (int i = firstNumLenght; i >= 0; i--) {
			if (flag == 1) { i = firstNumLenght - 1; flag = 0; }
			if (firstNum.number[i] < secondNum.number[i])
				NeedSwapping = Case2;
			else if (firstNum.number[i] > secondNum.number[i])
				NeedSwapping = Case1;
		}
	}
	//Swap
	if (firstNumLenght < smallerNumLenght || NeedSwapping) {
		biggerNumLenght = secondNumLenght;
		smallerNumLenght = firstNumLenght;
		swap(firstNum, secondNum);
		Nresult.isPositive = firstNum.isPositive;
	}
	Nresult.number = new char[biggerNumLenght + 2];
	int smallerNumIndex = smallerNumLenght - 1;
	//We are iterating by biggernum
	for (int i = biggerNumLenght - 1; i >= 0; i--) {
		int digitFromBiggerNum = SymToDec(firstNum.number[i]);
		int result = digitFromBiggerNum;
		//Checks if the small num has more digits.
		if (smallerNumIndex >= 0) {
			int digitFromSmallerNum = SymToDec(secondNum.number[smallerNumIndex--]);
			if (result - digitFromSmallerNum < 0 && i > 0) {
				result = (result + DIFFRENCE) - digitFromSmallerNum;
				for (int j = i - 1; j >= 0; j--) {
					//If we find digit bigger than 0 we will substract 1 of it.
					if (firstNum.number[j] > '0') {
						firstNum.number[j]--;
						break;
					}
					else {
						//While searching for digit bigger than 10 we are placing on every 0 9 so when it finds bigger digit it will simulate taking 1 of every digit and passing it to right.
						firstNum.number[j] = '9';
					}
				}
			}
			else {
				result = abs(result - digitFromSmallerNum);
			}
		}
		Nresult.number[i] = DecToSym(result);
	}
	Nresult.number[biggerNumLenght] = '\0';
	while (Nresult.number[0] == '0' && Nresult.number[1] != '\0') {
		NumToLeft(biggerNumLenght, Nresult.number);
	}
	return Nresult;
}
Num GatherNum(Num firstNum, Num secondNum) {
	const int DIFFRENCE = 10;
	Num resultNum;

	delete[] resultNum.number;
	//Checking if one of the number is negative to substract them.
	if (!firstNum.isPositive && secondNum.isPositive || firstNum.isPositive && !secondNum.isPositive) {
		return SubstactNum(firstNum, secondNum);
	}
	int firstNumLenght = (int)StrLenght(firstNum.number);
	int secondNumLenght = (int)StrLenght(secondNum.number);

	int biggerNumLenght = firstNumLenght;
	int smallerNumLenght = secondNumLenght;

	//Checking if the second num is bigger to swap them.
	if (firstNumLenght < secondNumLenght) {
		swap(firstNum, secondNum);
		swap(firstNumLenght, secondNumLenght);

		biggerNumLenght = firstNumLenght;
		smallerNumLenght = secondNumLenght;
	}
	resultNum.number = new char[biggerNumLenght + 2];
	int remainder = 0;
	int end = biggerNumLenght - smallerNumLenght;
	int smallerNumIndex = smallerNumLenght - 1;

	for (int i = biggerNumLenght - 1; i >= 0; i--) {
		int digitFromBigNum = SymToDec(firstNum.number[i]);
		int result = digitFromBigNum + remainder;
		//Checks if the smaller num has digits.
		if (smallerNumIndex >= 0) {
			int digitFromSmallerNum = SymToDec(secondNum.number[smallerNumIndex--]);
			result += digitFromSmallerNum;
		}
		if (remainder > 0) {
			remainder = 0;
		}
		if (result >= DIFFRENCE) {
			result -= DIFFRENCE;
			remainder++;
		}
		resultNum.number[i] = DecToSym(result);
	}
	if (remainder > 0) {
		NumToRight(biggerNumLenght, resultNum.number);
		resultNum.number[0] = DecToSym(remainder);
	}
	else {
		resultNum.number[biggerNumLenght] = '\0';
	}
	while (resultNum.number[0] == '0' && resultNum.number[1] != '\0') {

		NumToLeft(biggerNumLenght, resultNum.number);
	}
	return resultNum;
}
int SymToDec(char num) {
	return num - '0';
}
char DecToSym(int num) {
	return num + '0';
}
bool InputForNumber(char& op, Num& number1, Num& number2) {
	char* input = new char[408];
	number1.number = new char[102];
	number2.number = new char[102];
	//Take in Input
	cin.getline(input, 408);
	if (input[0] != '<' || input[1] != '<')
		return false;
	int inputLenght = (int)StrLenght(input);
	int startFrom = 0;
	//Checks for valid operators
	if ((input[2] != '+' && input[2] != '-' && input[2] != '*') || input[3] != ' ' || input[3] == '\0')
		return false;
	//Taking the operator from the input.
	op = input[2];
	if (input[4] == ' ' || '\0')
		return false;
	//If we find - infront of a num we add 1 to the variable so we can use it latter to substract the - from the size of the array.
	int removeIndex = 0;
	//Taking the firstNum from the input
	for (int i = 4; i < inputLenght; i++) {
		if (input[i] == ' ') {
			startFrom = i + 1;
			number1.number[i - (2 + removeIndex + 2)] = '\0';
			break;
		}
		if (input[i] == '-') {
			number1.isPositive = false;
			removeIndex++;
			continue;
		}
		if (input[i] < '0' || input[i] > '9')
			return false;
		number1.number[i - (2 + removeIndex + 2)] = input[i];
	}
	if (input[startFrom - 1] != ' ' || input[startFrom - 1] == '\0')
		return false;
	removeIndex = 0;
	//Taking the secondNum from the input
	for (int i = startFrom; i < inputLenght; i++) {
		if (i + 1 == inputLenght) {
			return false;
		}
		if (input[i] == '>' && i > startFrom) {
			if (input[i + 1] != '>') {
				return false;
			}
			break;
		}
		if (input[i] == '-') {
			number2.isPositive = false;
			removeIndex++;
			continue;
		}
		if (input[i] < '0' || input[i] > '9')
			return false;

		number2.number[i - (startFrom + removeIndex)] = input[i];
	}
	number2.number[inputLenght - (startFrom + removeIndex + 2)] = '\0';
	return true;
}
size_t StrLenght(char* first_Arr) {
	size_t index = 0;
	while (first_Arr[index++] != '\0');
	return index - 1;
}
void NumToLeft(int numLenght, char* number) {
	int counter = 0;
	for (int i = 1; i < numLenght; i++) {
		number[i - 1] = number[i];
		counter++;
	}
	number[counter] = '\0';
}
void NumToRight(int lenght, char* number) {
	for (int i = lenght - 1; i >= 0; i--) {
		number[i + 1] = number[i];
	}
	number[lenght + 1] = '\0';
}