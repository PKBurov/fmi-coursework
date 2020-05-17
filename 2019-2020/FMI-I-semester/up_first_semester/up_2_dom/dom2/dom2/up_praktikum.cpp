//#include<iostream>
//# define BUFFER 6
//using namespace std;
//
//char* getTime(unsigned int hh, unsigned int mm, char *buff) ;
//int main()
//{
//	int c, p;
//	cin >> c >> p;
//	char fullTime[BUFFER];
//	getTime(c, p, fullTime);
//	if (fullTime[0] == '\0')
//		cout << "Invalid time\n";
//	else
//		cout << fullTime << endl;
//
//	return 0;
//}
//char* getTime(unsigned int hh, unsigned int mm, char* buff){
//	if (hh>23||mm>59){
//		buff[0] = '\0';
//		return buff;
//	}
//	buff[0] = hh / 10 + '0';
//	buff[1] = hh % 10 + '0';
//	buff[2] = ':';
//	buff[3] = mm/ 10 + '0';
//	buff[4] = mm % 10 + '0';
//	buff[5] = '\0';
//	return buff;
//
//}
//
//// От десетична в Н ична char* DecToP(long long num,int base(kakva sistema),char*buf) връща карактер пойнтер;
//// DecToP(255,16,buf)->"FF";