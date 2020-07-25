#include <iostream.h>

void func(int &a, int b, int& c)
{
  int x;
  x = a;
  a = 4;
  c = b;
  b = x;	
  cout << "func: a = " << a << endl;
  cout << "func: b = " << b << endl;
  cout << "func: c = " << c << endl;
  return;
}

int main()
{ 
  int a = 1;
  int b = 2;
  int c = 3;
  cout << "main: a = " << a << endl;
  cout << "main: b = " << b << endl;
  cout << "main: c = " << c << endl;
  func(a, b, c);
  func(b, c, a);
  func(c, a, b);
  cout << "main: a = " << a << endl;
  cout << "main: b = " << b << endl;
  cout << "main: c = " << c << endl;
  return 0;
}
