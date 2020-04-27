#include<iostream>

using namespace std;

//Function Prototype
char* function(char* firstarr, char* secondarr);
int Strlen(const char* s);

int main()
{
	//Local Input
	char arr[] = "123";
	char arr2[] = "123 \t567";
	int len1 = 0, len2 = 0;
	// Input Check
	len1 = Strlen(arr);
	len2 = Strlen(arr2);
	if (len1 == 0 || len2 == 0){
		cout << '\a' <<"Invalid Input: Array is empty!" << endl;
	}else{

		//Output
		cout << arr << endl << arr2 << endl;
		cout << function(arr, arr2);
		cin.get();
	}
	return 0;
}
char* function(char* firstarr, char* secondarr) {
	int arrLength1 = 0, arrLength2 = 0, i = 0, j = 0;
	//Get Lenght
	arrLength1 = Strlen(firstarr);
	arrLength2 = Strlen(secondarr);
	//Output
	if (arrLength1 > arrLength2) {
		for (i = 0; firstarr[i] != '\0'; i++) {
			firstarr[i] = secondarr[j];
			j++;
			if (secondarr[j] == '\0') { j = 0; }
		}
		return firstarr;
	}else if (arrLength2 > arrLength1) {
		for (i = 0; secondarr[i] != '\0'; i++) {
			secondarr[i] = firstarr[j];
			j++;
			if (firstarr[j] == '\0') { j = 0; }
		}
		return secondarr;
	}
	return firstarr;
}
int Strlen(const char* s) {
	int i = 0;
	while (s[i] != '\0') i++;
	return i;
}