//#include <iostream>
//using namespace std;
//
//int Strlen(const char* s)
//{
//	int i = 0;
//	while (s[i]) i++; // while(s[i] != '\0') i++;
//	return i;
//}
//
//void Swap(char& a, char& b)
//{
//	char c = a;
//	a = b;
//	b = c;
//}
//
//int NumberToString(char* buf, int n)
//{
//	int p = 0;
//	do
//	{
//		buf[p++] = n % 10 + '0';
//		n /= 10;
//	} while (n);
//	buf[p] = '\0';
//	for (int i = 0, j = p - 1; i < j; i++, j--)
//		Swap(buf[i], buf[j]);
//	return p;
//}
//
//char* Strcpy(char* dest, const char* src)
//{
//	int i;
//	for (i = 0; src[i] != '\0'; i++)
//		dest[i] = src[i];
//	dest[i] = '\0';
//	return dest;
//}
//
//void encode(char* s)
//{
//	int len = Strlen(s);
//	char* temp = new char[4 * len];
//	int pos = 0;
//	for (int i = 0; i < len; i++)
//	{
//		pos += NumberToString(temp + pos, s[i]);
//		temp[pos++] = '_';
//	}
//	temp[pos - 1] = '\0';
//
//	Strcpy(s, temp);
//	delete[] temp;
//}
//
//int main()
//{
//	char str[1000];
//	cin >> str;
//	encode(str);
//	cout << str << endl;
//}
