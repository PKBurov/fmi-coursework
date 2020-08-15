#include <iostream.h>
#include <string.h>

// Пренареждане на масива от низове s с n елемента така,
// че всички по-малки от x елементи да са в лявата част,
// а всички по-големи или равни на x елементи -
// в дясната част на масива, относно x.
// Резултатът от изпълнението на функцията е индексът 
// на първия по-голям или равен на x елемент.
int splitBy(char **s, int n, char* x)
{
    int left = 0,
        right = n-1;
    char *tmp = 0;
    // Обхождане на масива от две страни едновременно.
    // На всяка стъпка се осигурява елементите
    // отляво на left да са по-малки от x,
    // а елементите отдясно на right, да са по-големи
    // или равни на x.
    while(left < right)
    {
        while(left <= right && strcmp(s[left],x) < 0)
        {
            left++;
        }
        while(left < right && strcmp(s[right],x) >= 0)
        {
            right--;
        }

        // s[left] е най-левият по-голям или равен на x елемент,
        // а s[right] - най-десният по-малък от x елемент.
        // Следователно могат да бъдат разменени.
        if(left < right)
        {
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
        }
    }

    if(left == right)
    {
        return right+(strcmp(s[right], x) < 0);  
    }
    else 
    {
        return n;    //няма такива елементи
    }
}

// Преместване на елементите на масива от
// низове s с 1 елемент наляво
void shiftLeft(char **s, int n)
{ 
    int i = 0;
    for(i = 0; i < n-1; i++)
    {
        s[i]=s[i+1];
    }
}

// Сортиране на масива от низове s с n елемента
void quickSort(char **s, int n)
{ 
    // дъно на рекурсията - няма какво да се сортира
    if(n <= 1)
        return;

    char *first = s[0];

    // Разделяне на масива на
    // лява и дясна част отностно first
    int middle = splitBy(s+1, n-1, first);

    // Сортиране на лявата част
    quickSort(s+1, middle);

    // Сортиране на дясната част
    quickSort(s+1+middle, n-1-middle);

    // Освобождаване на място за first
    shiftLeft(s, middle+1);
    s[middle] = first;
}

int main()
{
    char s1[10][10], *s[10];
    int n, i;
    cout << "n= "; 
    cin >> n;

    for(i = 0; i < n; i++)
    {
        cin >> s1[i];
        s[i] = s1[i];
    }

    quickSort(s, n);
    for(i = 0; i < n; i++)
    {
        cout << " " << s[i];
    }
    cout << endl;
    return 0;
}
