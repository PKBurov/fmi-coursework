//////#include<iostream>
//////using namespace std;
//////int main()
//////{
//////	char Ch1; // ne znam kak da izrazq chislata sled F i + 2ta chara;
//////	char Ch2;
//////	int a = 30;
//////	int num1 = 0, num2 = 0, num3 = 0;
//////	if (a <= 16){	
//////		do{
//////			switch (a % 16){
//////			case 0:
//////				Ch1 = '0';
//////			case 1:
//////				Ch1 = '1';
//////				break;
//////			case 2:
//////				Ch1 = '2';
//////				break;
//////			case 3:
//////				Ch1 = '3';
//////				break;
//////			case 4:
//////				Ch1 = '4';
//////				break;
//////			case 5:
//////				Ch1 = '5';
//////				break;
//////			case 6:
//////				Ch1 = '6';
//////				break;
//////			case 7:
//////				Ch1 = '7';
//////				break;
//////			case 8:
//////				Ch1 = '8';
//////				break;
//////			case 9:
//////				Ch1 = '9';
//////				break;
//////			case 10:
//////				Ch1 = 'A';
//////				break;
//////			case 11:
//////				Ch1 = 'B';
//////				break;
//////			case 12:
//////				Ch1 = 'C';
//////				break;
//////			case 13:
//////				Ch1 = 'D';
//////				break;
//////			case 14:
//////				Ch1 = 'E';
//////				break;
//////			case 15:
//////				Ch1 = 'F';
//////				break;
//////			}
//////		} while (a%16 == 0);
//////		
//////	}else if (a>= 16 && a<=31){
//////		do {
//////			switch (a % 16) {
//////			case 0:
//////				Ch1 = '0';
//////			case 1:
//////				Ch1 = '1';
//////				break;
//////			case 2:
//////				Ch1 = '2';
//////				break;
//////			case 3:
//////				Ch1 = '3';
//////				break;
//////			case 4:
//////				Ch1 = '4';
//////				break;
//////			case 5:
//////				Ch1 = '5';
//////				break;
//////			case 6:
//////				Ch1 = '6';
//////				break;
//////			case 7:
//////				Ch1 = '7';
//////				break;
//////			case 8:
//////				Ch1 = '8';
//////				break;
//////			case 9:
//////				Ch1 = '9';
//////				break;
//////			case 10:
//////				Ch1 = 'A';
//////				break;
//////			case 11:
//////				Ch1 = 'B';
//////				break;
//////			case 12:
//////				Ch1 = 'C';
//////				break;
//////			case 13:
//////				Ch1 = 'D';
//////				break;
//////			case 14:
//////				Ch1 = 'E';
//////				break;
//////			case 15:
//////				Ch1 = 'F';
//////				break;
//////			}
//////		} while (a % 16 == 0);
//////		
//////	}
//////	cout << "THE value is : " << Ch1;
//////}
////
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	long int decimal;
//	long int z;
//	long int dn = 0;
//	long int a;
//	long int b;
//	int i = 1;
//	int tmp;
//	char hex;
//
//	cout << "Enter number:";
//	cin >> decimal;
//	a = decimal;
//	for (b = a; b > 0; b = b / 16)
//	{
//		tmp = b % 16; // ostatuk na chisloto a<16=> a%16=a
//		if (tmp < 10)
//			tmp = tmp + 48; // za da izkarame stoinosta v char 0-9
//		else
//			tmp = tmp + 55; // za da izkarama stoinosta v char A-F
//		dn = dn * 100 + tmp; // umnojavash po 100 i subirash s predishnoto chislo, za da moje da prestavish 2ta chara v 4teri cifreno chislo,kudet poslednite dve chisla vikagi sa 00 i subirash s drugite int koito e pravilnata stoinost v chara;
//		// pravi se za da moje da raboti s poveche ot 1 chislo vzima 65(int) == A (char) 
//		}
//	cout << "Number is: ";
//	for (z = dn; z > 0; z = z / 100)
//	{
//		hex = z % 100; // prevrushta stoinosta v char;
//		cout << ("%c", hex); //pechata char;
//	}
//	cout << ("\n\n");
//}