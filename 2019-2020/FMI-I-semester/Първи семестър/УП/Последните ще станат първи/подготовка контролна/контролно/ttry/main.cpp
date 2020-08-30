#include <iostream>
#include<cstring>

using namespace std;

int main()
{
    char s1[80]="IvaPetur";
    char a2[80];

    strncpy(a2,s1);

    strcpy(a2,s1);


    cout<< a2<< endl;

char s1[20]= "012345or not to be";
char s2[20]="tb";
int b;
b= strcspn(s1,s2);
cout<< b<< endl;
char s3[20]="be";
b= strcspn(s1,s3);
cout<< b<< endl;

    return 0;
}
