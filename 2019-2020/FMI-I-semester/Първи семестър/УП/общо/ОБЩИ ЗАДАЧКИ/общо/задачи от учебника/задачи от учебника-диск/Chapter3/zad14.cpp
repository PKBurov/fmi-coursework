#include <iostream.h>
#include <string.h>
const int MAX_SIZE = 80;

int main()
{
    char s[MAX_SIZE], 	 // сортиран символен масив
         c = 0;         // търсения символ
    cout << "s= ";
    cin >> s;
    cout << "c= ";
    cin >> c;

    // текущо разглеждана част от масива
    int left = 0,				        // ляв край на частта
        right = strlen(s)-1,	// десен край на частта
        middle;		  		        // среда на частта

    while(left <= right)
    {
        middle = (left+right)/2;
        if(c == s[middle]) 
            break;
        if(c < s[middle])  
            right = middle-1;
        else 
            left = middle+1;
    }
    if(s[middle] != c)
    {
        cout << "Символът не е намерен!\n";
    }
    else
    {
        cout << "Позицията на срещането е: "
             << middle << endl;
    }
    return 0;
}
