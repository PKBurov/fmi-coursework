#include <iostream.h>

// намира дължината на символен низ
int leng(const char* s)
{ 
    int l = 0;
    while (*s)
    { 
        l++; 
        s++;
    }
    return l;
}

// връща първия символ (елемент) на низа x;
char car(const char* x) 
{ 
    return x[0];
}

// връща останалата част от низа x след
// отделянето на първия елемент на низа x;
char* cdr(char* x)
{ 
    return x+1;
}

// връща указател към символен низ, разположен в 
// динамичната памет и съдържащ конкатенацията
// на символa x със символния низ y;
char* cons(char x, const char* y)
{ 
    int len1 = leng(y);
    char* z = new char[1+len1+1];
    int i;

    z[0] = x;
    for(i = 0; i <= len1; i++)
        z[1 + i] = y[i];
    return z;
}

// помощна функция
// връща указател към символен низ, разположен в
// динамичната памет и съдържащ конкатенацията
// на символния низ x със символния низ y;
char* append(const char* x, const char* y)
{ 
    int len1 = leng(x),
        len2 = leng(y);
    char* z = new char[len1+len2+1];
    int i;

    for(i = 0; i <= len1-1; i++)
        z[i] = x[i];

    for(i = 0; i <= len2; i++)
        z[len1+i] = y[i];
    return z;
}

// установява дали низовете x и y са равни
bool eq(const char* x, const char* y)
{ 
    int i, l1 = leng(x), l2 = leng(y);

    if(l1 != l2) 
        return false;

    bool flag = true;
    for(i = 0; x[i] && flag; i++)
    {
        if(x[i] != y[i]) 
            flag = false;
    }
    return flag;
}

// връща указател към символен низ, разположен в
// динамичната памет и съдържащ символите на x,
// записани в обратен ред
char* reverse(char* x)
{ 
    char *y = "\0";
    if(*x == '\0')
    { 
        y = new char; 
        *y = '\0';
    }
    else
    { 
        char *old = NULL; 
        while(*x != '\0')
        { 
            char first = car(x);
            y = cons(first, y);
            delete old;
            old = y;
            x = cdr(x);
        }
    }
    return y;
}

// връща указател към символен низ, разположен в
// динамичната памет и съдържащ копие на символния низ x
char* copy(char* x)
{ 
    char *y = "\0";
    char *old = NULL;

    while(*x != '\0')
    { 
        char first = car(x);
        y = cons(first, y);
        delete old;
        old = y;
        x = cdr(x);
    }
    y = reverse(y);
    delete old;
    return y;
}

// връща указател към символен низ, разположен в
// динамичната памет и съдържащ първите n символа
// на символния низ x
char* car_n(char* x, int n)
{ 
    char* y = "\0";
    char *old = NULL;
    if(leng(x) < n) 
        return copy(x);

    for(int i = 1; i <= n; i++)
    { 
        char first = car(x);
        y = cons(first, y);
        delete old;
        old = y;
        x = cdr(x);
    }
    y = reverse(y);
    delete old;
    return y;
}

// връща останалата част от низа x след отделянето
// на първите n елемента на низа x;
char* cdr_n(char* x, int n)
{
    return x+n;
}

// връща броя на срещанията на символа ch
// в символния низ x;
int number_of_char(char* x, char ch)
{ 
    int l = 0;
    while(*x != '\0')
    {
        char p = car(x);
        if(p == ch)
            l++;
        x = cdr(x);
    }
    return l;
}

// връща броя на срещанията на символния низ y
// в символния низ x;
int number_of_substr(char* x, char* y)
{ 
    int l1 = leng(x), l2 = leng(y);
    if (l1 < l2) 
        return 0;

    int l = 0;
    for(int i = 0; i <= l1-l2+1; i++)
    {
        char* p = car_n(x, l2);
        if(eq(p, y))
            l++;
        x = cdr(x);
        delete p;
    }
    return l;
}

// връща указател към символен низ, разположен в
// динамичната памет и съдържащ символите на
// дадения низ x, от който са изтрити
// всички срещания на символния низ y
char* delete_substr(char* x, char* y)
{ 
    int l1 = leng(x), l2 = leng(y);
    char *z = new char[l1+1];
    z[0] = '\0';
    char *old = NULL;

    if (l1 < l2)
    {
        z = copy(x);
    }
    else
    {
        while(*x)
        { 
            char* p = car_n(x, l2);
            if(eq(p, y)) 
            {
                x = cdr_n(x, l2); 
            }
            else
            {
                char* first = car_n(x, 1);
                z = append(z, first);
                delete old;
                old = z;
                delete first;
                x = cdr(x);
            }
        }
    }
    return z;
}

int main()
{ 
    cout << "Въведете символен низ: ";
    char str[50];
    cin.getline(str, 50);

    char* p = reverse(str);
    cout <<  p << endl;
    delete p;

    p = copy(str);
    cout << p << endl;
    delete p;

    p = car_n(str,1);
    cout << p << endl;
    delete p;

    cout << number_of_char(str, 'p') << endl;
    cout << number_of_substr(str, "xyz") << endl;
    p = delete_substr(str, "xyz");
    cout << p << endl;
    delete p;

    return 0;
}
