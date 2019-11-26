#include<iostream>
using namespace std;

void spaw(int& a, int& b)
{
	a = a + b;
	b = a - b;
	a = a - b;

}

int main()
{
	/*int a = 5;
	int *p = &a;
	

	cout << p << endl;
	cout<<	&p << endl;
	cout << *p << endl;

	int& b = a;
	cout << &a << endl;
	cout << b << endl;

	int c = 6;

	b = c;
	cout << "a: " << a << endl;
	*p = b;
	cout << "a: " << a << endl;


	
	cout << a;*/
	
	//cout << &b << endl;

	int a = 5;
	int b = 6;

	spaw(a, b);
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;


	system("pause");



		
	return 0;
}

// delete []<- adress massive difference delete and delete[]
//delete kum int*p, *p-> adress->5 koito e zadelen v heapa ->new int (primitivnata pamet int) osvobojdavash pamet koqto e zadelena za 1element v 1 pointer;
//delete[]->int*p  sochi kum element na masiv, koito vutre ima mnogo elementi -> sledovatelno ako imame massiv ot pointeri gi turkame s delete[];
