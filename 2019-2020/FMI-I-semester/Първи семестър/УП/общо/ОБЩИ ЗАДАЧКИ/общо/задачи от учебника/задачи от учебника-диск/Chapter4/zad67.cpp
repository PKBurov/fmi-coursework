#include <iostream.h>
#include <math.h>

const int MAX = 100;

// въвежда едномерен масив X с k елемента
void Read(double X[], int k)
{ 
    for(int i = 0; i < k; i++)
    {
        cout << "X[" <<i << "]= ";
        cin >> X[i];
    }
}

// извежда едномерен масив X с k елемента
void Write(double X[], int k)
{ 
    for(int i = 0; i < k; i++)
    {
        cout << X[i] << " ";
    }
    cout << endl;
}

// прилага реалната функция f към всеки елемент на X
void Map(double X[], int k, double (*f)(double))
{ 
    for(int i = 0; i < k; i++)
        X[i] = (*f)(X[i]);	    // или X[i] = f(X[i]);
}

int main()
{ 
    cout << "n= ";
    int n; cin >> n;
    double A[MAX];
    Read(A, n);
    Write(A, n);

    // прилага функцията fabs над всеки елемент на
    // едномерния масив A
    Map(A, n, fabs);
    Write(A, n);

    // прилага функцията sqrt над всеки елемент на
    // едномерния масив A, получен след прилагането
    // на функцията fabs над първоначалния масив A
    Map(A, n, sqrt);
    Write(A, n);
    return 0;
}
