#include<iostream>
#define BUFFER 4

using namespace std;
int function(char* characters);
int Strlen(const char* s);

int main()
{
	char characters[BUFFER];
	int count = 0;
	cout << "Enter max 3 characters: ";
	//Input
	cin.getline(characters, BUFFER);
	int len = Strlen(characters);
	//Input Check
	for (int i = 0; i < len; i++){
		if (characters[i] >= 'A' && characters[i] <= 'Z') { count++; }
	}if (count==len){
		cout << function(characters) << endl;
	}else {
		cout << "Invalid iput" << endl;
	}
	return 0;
}
int function(char *characters){
	int char1 = 0, char2 = 0, char3 = 0, lenght = 0;
	lenght = Strlen(characters);
	// 64 == '0' in char
	if (lenght==1){
		char1 = (int)characters[0] - 64;
		return char1;
	}else if (lenght==2){
		char1 = (int)characters[0] - 64;
		char2 = (int)characters[1] - 64;
		char3 = (26 * char1) + char2;
		return char3;
	}else if (lenght==3){
		char1 = (int)characters[0] - 64;
		char1 = char1 * 676;
		char2 = (int)characters[1] - 64;
		char3 = (int)characters[2] - 64;
		char3 = char1 + (26 * char2) + char3;
		return char3;
	}
	return 0;
}
int Strlen(const char* s) {
	int i = 0;
	while (s[i] != '\0') i++;
	return i;
}
