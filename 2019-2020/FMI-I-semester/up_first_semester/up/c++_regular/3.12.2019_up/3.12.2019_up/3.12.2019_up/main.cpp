#include<iostream>
using namespace std;

const int MAX_SIZE = 5;

void inp(int m[][MAX_SIZE], int n)
{
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++)
			cin >> m[i][j];
	}
}
void diagonalPrint(int m[][MAX_SIZE], int n) {
	int element = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i+1; j++){
			element = m[i][j];
			cout << endl << endl;
			cout << element;
		}
	}
	
}
void arrEqual(int m[],int size) {
	
	while (size != 0) {
		int digit = size % 10;
		m[digit]++;
		size /= 10;
	}
}
int sumArr(int m[], int size) {
	int sum = 0;
	for (int i = 0; i < size; i++){
		cin >> m[i];
	}
	for (int j = 0; j < size; j++){
		sum += m[j];
	}
	return sum;
}
void bigSmall(int p[], int size){
	int big = 0, small = 0;
	for (int i = 0; i < size; i++) {
		cin >> p[i];
	}
	for (int j = 0; j < size; j++){
		int i = 0;
		if (p[i]>p[size-1]){
			
		}else{
			big =
		}
	}
}
int average(int m[], int size){
	int sum = 0;
	for (int i = 0; i < size; i++) {
		cin >> m[i];
	}
	for (int j = 0; j < size; j++) {
		sum += m[j];
	}
	return sum / size;
}
int reversearr();
int nechetenindexakoechetnochilsodagoizvejda()
int main()
{
	int arr[10];
	//cout << sumArr(arr, 10) << endl;
	bigSmall(arr, 10);
	//cout << average(arr, 10);
	return 0;
}


/*----------Записки---------------

1.пойнтър може да се променя, референцията не;
2.Първи елемент на масива е пойнтър към следващия и са последователност към паметта;
3.Двумерен (масив от масиви) arr[4][3] 4ти ред и 3ти индекс;

 int a =5 ; int &b = a;
 cout<<  b -> ст на а;
 cout<< *b -> не се компилира;
 cout<< &b -> адреса на а; (макар, че b има място в паметта, но компилатора не ни дава да я видим, защото оптимизира кода);

 Подаване на Двумерен, Едномерен масив:

 Едномерен - Подаване : 

 int p[4]
 int func(int p[],int size);
 int func(int p[4]);
 void func(int *p,int size) -> също става;
 function(p);
 function(&p,3) ->подаваш реверенция към p, което е първоначален адрес на масива или адрес , по точно;
 fucntion(&p[0],3)  и променим void function(int*p,int size) -> ще работи;

 Двумерен как се подава:  Преглеждаме за статичен масив!!!

 void func(int*p[],int size x, int size y)-> това не работи;
 void func(int p[][4],int x ,int y) -> това работи; {сигнатура} -> помощ на компилатора;
 void func(int(*p)[4]) -> това работи, защото подаваш пойнтър към първия елеемент на масива и взимаш 4тия елемент;

 int k[3][3] = {....}

 В мейна:

 function(k,3,3)

 void function(int p[][3], int X, int Y){

 for (int i,i<x , i++)
	for(int j,j<y;j++)
	cout<<k[i][j]<<" ";

cout<< endl;
 }
 */