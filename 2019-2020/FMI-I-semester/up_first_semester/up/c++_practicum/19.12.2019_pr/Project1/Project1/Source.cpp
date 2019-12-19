#include<iostream>
using namespace std;

unsigned long long fact(unsigned n)
{
	if (!n) return 1;
	return (unsigned long long)n * fact(n - 1);
}
unsigned long long fib(unsigned n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	return fib(n - 1) + fib(n - 2);
}
int* newArr(int n)
{
	int* p = new int[n];
	for (int i = 0; i < n; i++)
		p[i] = i;
	return p;
}
void allocateByrows(int n, int m) {
	int** m = new int* [n];
	for (int i = 0; i < n; i++)
		m[i] = new int[m];
	return m;
}
void deallocateByrows(int** mat, int n) {
	for (int i = 0; i < n; i++)
		delete[] mat[i];
		delete[] mat;
}
void inp(int** mat, int n, int m)
{
	for ( i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cout << a[i][j] << ' ';
			cout << endl;
		}
}
struct Point 
{
	double x, y; // Те са последователно в паметта;
};
//Тук point e тип;
double dist(Point a, Point b)// Вместо double dist(double x, double y, double x1, double y1)

int main()
{
	unsigned n;
	cin >> n;
	/*cout << fact(n) << endl;*/
	/*cout << fib(n) << endl;*/
	
	////Показване как се заема памет чрез task manаger
	//int* p = newArr(300000000);
	//system("pause");
	//delete[] p;
	//system("pause");

	//Двумерен масив Пример:

	int n, m;
	cin >> n >> m;

	Point p;
	p.x = 5;
	p.y = 2;

	return 0;
}
/*


sizeof(int*) == 8 или 4byta, но на този ОС е 4 ==> можем да адресираме 2^32 байта, следователно колко ГБ е това?
- 2^32 B=2^22 KB=2^12 MB = 2^2 GB = 4 GB

Ако сменим на 64 битова архитектура, вече пойнтура ще е с големина 8 байта;

Съществува функ newArr( по горе)


Двумерен Динамичен масив:


първо 1номерен:
int *p=new int[n]; - динамичен масив с големина n и връща указател към началото;
new int[n] - връша инт пойнтър
new int*[n] - връща двоен указател ==> int**m = new int*[n];

for	(int i = 0; i<n; i++)
{
	m[i]= new int[m] == тук сме заделили м на м

	m[1][2] = 5;
	..
	...
	....
}
	// Освобождаване 

	for (int i = 0, i<n; i++)
{
	delete[] m[i];
	delete[] m;

}

II Начин

Взимаме указатели по същия начин:
int** m= new int*[n]; и всеки указател го насочваме куъдето трябва;

m[1][3] = 7;



//предимствa и недостатаци: 

Не е нужно да са всички от една и съща дължина в другот трябва
на 2рото, сигурнисме,че всеки блок към който сочи пойнтъра е последователно в памета, в първото не е;
В 1вото можем да изтрием ред, без да трием другите, в 2торото трием целия масив
2рия работи много по бързо, защото е подредена памет;
в 1вия, можем да разменим два реда, в 2тория също можем да разменим пойнтърите, но губим добрите свохства на това че са наредени
2рия взима цялата памет на веднъж, а първия взима малко по малко;
Но ако взимаме малко по малко памет, все едно за 1вия ред има за 2рия ред има но за 3тия няма, тогава трябва да се погрижим да освободим предишно заделената памет func void allocatebyrows() там където има nothrow в for'a 
ако не е успял, връща nullptr а не хвърля еxeption, след това в if'a се освобождава всичко; втория for длетва до подаденото място и връща че не е успяло да задели памет;


другия случай където е с блока int** AllocateBlock() пак с nothrow; чистим и връщаме nullptr




Структури Нов тип, които си ги задаваме ние: Разстояние между 2 точки(примерно);

struct Point




*/