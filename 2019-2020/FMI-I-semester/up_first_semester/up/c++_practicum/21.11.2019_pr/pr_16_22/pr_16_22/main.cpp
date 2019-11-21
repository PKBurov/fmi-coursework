#include<iostream>
#include<vector>

//using namespace std;
//void swapp(int &arr1, int &arr2 ){
//	arr1 = arr1 + arr2;
//	arr2 = arr1 - arr2;
//	arr1 = arr1 - arr2;
//}
//// [20] ше се компилира, но или ше вземе памет която не е наша, иле ще гръпмне;
//
//int main()
//{
//	//Enter something into an array and print it out:
//	//const int SIZE = 100;
//	//int arr[SIZE], user_input = 0, reverse_value = 0, i = 0, j = 0;
//
//	//cout << "Enter number of brackets to be used:"; cin >> user_input;
//	//for ( i = 0; i < user_input; i++){
//	//	cout << "Enter number:"; cin >> arr[i];
//	//}
//	//j = i - 1; 
//	//i = 0;
//	//while (i<j){
//
//	//	swapp(arr[i], arr[j]);
//	//	i++;
//	//	j--;
//	//}
//	//cout << "Reverse array:";
//	//for ( i = 0; i < user_input; i++){
//	//	cout << arr[i] << " ";
//	//}
//
//	//cin >> user_input;
//	//for  (i = 0; i < user_input; i++){
//	//	cout << "Number:"; cin >> arr[i]; ///////Po dobroto reshenie;
//	//}
//	//for ( i = user_input-1; i>=0 ;i--)
//	//{
//	//	cout<<arr[i];
//	//}
//
//	//Dadeno e cqlo chislo n i n simvola da se proveri dali dadena redica ot simvoli e malindrom;
//	//primer 6 - a1bb1a - true; 4 abcd - false; 3 - ? 5?
//	/*const int CSIZE = 1000, SSIZE = 80;
//	char palindrom[CSIZE], pali = 0;
//	int user_input2=0,j2=0,i=0,counter=0;
//	cout << "How many letters you gonna be entering: ";
//	cin >> user_input2;
//	for ( i = 0; i < user_input2; i++){
//		cin >> palindrom[i];
//	}
//	for ( i = user_input2-1; i >= 0; i--){
//		if (palindrom[j2]==palindrom[i]){
//			counter++;
//		}
//		j2++;
//	}
//	if (counter == user_input2) {
//		cout << "Its a palindrom!";
//	}else {
//		cout << "It's not a palindrom!";
//	}*/
//
//
//	//Da suzdadem dynamichen masiv: (Pointeri) Constructor new i destructor delete, zadelqne pamet na hepa kakto i oturvavane ot neq;
//
//	/*int SIZE = 0;
//	int	*ptr;
//
//	cout << "Enter the number of fields you will be needing: " << endl;
//		cin >> SIZE;
//	ptr = new int[SIZE];
//	cout << "Enter the values of the array: " << endl;
//	for (int i = 0; i < SIZE; i++){
//		cin >> ptr[i];
//	}
//	cout << "These are your elements: " << endl;
//	for (int i = 0;  i < SIZE; i++){
//		cout << ptr[i] << endl;
//	}*/
//
//	//Pri proba s size cin>>size arr[size] ще върне arry must have a const value;
//
//	//Dynamic arrays with vectors;
//	
//	//int size = 0;
//	//cin >> size;
//	//vector<int>arr(size);
//	//for (int i = 0; i < size; i++){
//	//	cout << "Here:" << endl;
//	//	cin>>arr[i];
//	//}
//	//for (int i = 0; i < size; i++) {
//	//	//cout << "there:" << endl;
//	//	cout << arr[i];
//	//}
//
//
//	/*int SIZE = 0, counter = 0;
//	cin >> SIZE;
//	vector<int>v(SIZE);
//	for (int i = 0; i < SIZE; i++) { cin >> v[i]; }
//	for (int i = 0; i < SIZE; i++){
//		if (v.front() -i == v.back() -i){
//			counter++;
//		}
//	}
//	if (counter==SIZE){ cout << "Polindrom!" << endl;}
//	else { cout << "Not a Polindrom"; }*/
//
//	//Exerciese: All odd numbers at the back of the array; Ne raboti;
//
//	const int SIZE = 10;
//	//vector<int> arr(size);
//	int arr[SIZE];
//	int n = sizeof(arr) / sizeof(int);
//	for (int i = 0; i < n; i++) { cin >> arr[i]; }
//	n = n - 1;
//	for (int k = 0; k < n/2+1; k++){
//		int c = n - k;
//		if (arr[k] % 2 != 0 && arr[c] % 2 == 0){
//			swap(arr[k], arr[c]);
//		}
//		if (arr[k] % 2 == 0 && arr[c] % 2 == 0) {
//			for (int i = c-1; i >= 0; i--){
//				if (arr[i]%2!=0){
//					c = c - i;
//					swap(arr[k], arr[i]);
//					break;
//				}
//			}
//		}
//
//	}
//	for (int i = 0; i < n; i++) { cout << arr[i]; }
//
//	return 0;
//
//}
int main()
{
	int arr[100];

	int* pt;

	*pt = &arr;

	strlen(*pt);

	return 0;
}
