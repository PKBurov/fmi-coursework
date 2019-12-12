#include<iostream>

using namespace std;

int main()
{
	//Задача от изпита void encode(char*s) в s= аB1d-/f нещо всяка буква да се замени с аски кода им;
	// int* a,b - a е пойнтър, b e int;
	
	char str[1000];
	cin >> str;
	encode(str);
	cout << str;

	return 0;
}
int Strlen(const char* s) {
	int i = 0;
	while (s[i]) i++;
	return i;
}
int NumberToString(char* buf, int n ) { // Kolko cifri ima chisloto автоматично всеки char влиза в инт, прави си го само когато се извиква долу
	int p = 0;
	do
	{
		buf[p++] = n % 10 + '0';//заделя двете числа по отделно и ги вкарвам в масива примерно: b-97 искаме да стане 9 и 7 и да ги вкараме p++ увеличава и връща стария резултат;
		n /= 10;
	} while (n != 0);
	buf[p] = '\0';
	for (int i = 0, j=p-1; i < j; i++,j--){
		swap(buf[i], buf[j]); // Pak trqbva da se pishe swapa;
	}
	return p;
}
char* Strcpy(char* dest, const char* src)//Не е довършена;
{
	for (int i = 0; src[i] != '\0'; i++){
		dest[i] = src[i];

	}
}
void encode(char* s)
{
	if (s == nullptr) return; // Проверка;
	//aB1d-/F
	int len = strlen(s);
	char *temp = new char[4*len];
	int pos = 0;
	
	for (int i = 0; i <= len; i++){
		//char buf[4];//Три цифри с завършващата 0  ако взимахме _ трябваше да са 5;
		pos += NumberToString(temp+pos, s[i]);
		temp[pos++] = '_'; // Така сложено слагаме една долна черта повече, затова слагаме завършващата 0 върху нея
	}
	temp[pos - 1] = '0';
	Strcpy(s, temp);
	delete[] temp;

}


// Подаване на двумерен масив, void f(int a[][10],int n, int n) където int n[3][10]
// може да се повика int a[12][10] защото игнорира първите скобички, става и да се подаде void f( int (*a)[10] и така може да се подаде;

// int (*a)[10] -  един указател който сочи към масив
// int *a[] - масив от указатели 

// int arr[8]; не е уйазатек към 0левия елемент, то може да стане на указател, но само по себе си не е. Ако беше sizeof ще изведе размера на указателя, а не размера на масива;
// BSS - Не инициализираните променливи сегмента в дата (под хйпа) под него е code(което е low adress), а stecka ти е high adress;
/* 
Ако декларираме една промененлива в глобалния скоуп(в датата (живее е exeto на диска, докато не иде в рама) по време на компилация се пълни с 0 => глобалната променлива ще има стойност 0?), тя ще живее другате , като памет от колкото тези променливи който са локални(в стека)
int x;
cin>>x;
 е много по бързо от колкото int x =0; cin>> x; защото не губи един такт на процесора; C++ търси макс скорос, и заради това;

 Как да го накараме да връща nullptr вместо exeption, 
 while(true){
 int *p = new(nothrow) int [100];
 if(p==nullptr)
 {
 cout<<...No memory <<endl;
 return 0;
 }
{

Toва вече ще върне No memory ;

Delete връща памет от new;

Ако сме взимали масив delete [] p; така я връщаме;
Ако взимаме 1 елемент връщаме паметта с delete p;
 
 */