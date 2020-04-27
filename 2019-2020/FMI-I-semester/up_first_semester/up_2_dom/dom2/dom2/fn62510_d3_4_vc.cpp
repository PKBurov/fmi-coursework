#include<iostream>
#include<iomanip>
using namespace std;

void shortestWord(char* arr);
int Strlen(const char* s);

int main()
{
	char arr[] = "The best students are from FMI";
	/*char arr[] = "t_p";
	char arr[] = "a/3";
	char arr[] = "The     FMI \t  rullzz_";*/
	
	int lenght = Strlen(arr);
	if (lenght==0){
		cout << "Invalid Input:The array is empty" << endl;
	}else{
		//Local Input
		shortestWord(arr);
		cout << endl;
	}
	return 0;
}
void shortestWord(char* arr) {
	int maxCharLength = strlen(arr);
	int i = 0, z = 0, wordInterval = 0, validWord = 0, inValWord = 0, flag = 0, flag2 = 0, shortestWord = 0, count = 0;
	//Find shortest valid word;
	for (; wordInterval <= maxCharLength; ) {
		for (; arr[i] != ' '; i++) {
			if (arr[maxCharLength] == arr[i]) { break; }
			if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] == '-' || arr[i] == '_')) {
				validWord++; //Find the total valid characters in the wordInterval
			}else { inValWord++; }
		}
		if (arr[i-1] == ' ' && arr[i] == ' ') { flag = 1; }
		//Jump to next possision after ' ';
		wordInterval = i + 1;
		i = wordInterval;
		//Finding Shortest valid word
		if (flag == 0) {
			if (inValWord == 0) {
				if (shortestWord > validWord) {
					shortestWord = validWord;
					validWord = 0;
				}else {
					if (flag2 == 0) { shortestWord = validWord; flag2 = 1; }
				}
				validWord = 0;
			}else if (inValWord != 0) {
				inValWord = 0;
				validWord = 0;
			}
			flag = 0;
		}
	}
	//Input Check
	if (shortestWord == 0) { cout << "There are no Valid words!" << endl; }
	//Reset values;
	i = 0; wordInterval = 0; validWord = 0, inValWord = 0, count = 0;
	//Print number of shortest valid word
	for (; wordInterval <= maxCharLength;) {
		for (; arr[i] != ' '; i++) {
			if (arr[maxCharLength] == arr[i]) { break; }
			if ((arr[i] >= 'A' && arr[i] <= 'Z') || (arr[i] >= 'a' && arr[i] <= 'z') || (arr[i] == '-' || arr[i] == '_')){
				//if (arr[i] == '-' || arr[i] == '_') { flag = 1; }
				validWord++;
			}else { inValWord++; }
		//Print Shortest word;
		}if (inValWord == 0 && validWord == shortestWord) {
			count++;
		}
		wordInterval = i + 1;
		i = wordInterval;
		//Reset
		validWord = 0;
		inValWord = 0;
	}
	cout << "Number of shortest words: " << count << endl; //Output
}
int Strlen(const char* s) {
	int i = 0;
	while (s[i] != '\0') i++;
	return i;
}