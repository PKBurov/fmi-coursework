#include <iostream.h>
#include <iomanip.h>

const int MAX = 100;

// въвеждане на системата
int init(double a[][MAX])
{
    int n;
    do
    { 
        cout << "n= ";
        cin >> n;
    } while(n <= 0 || n > MAX);

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cout << "a[" << i << "][" << j << "]= ";
            cin >> a[i][j];
        }
    }
    return n;
}

// извеждане на системата
void print(double a[][MAX], int n)
{
    cout << setprecision(4);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << setw(8) << a[i][j];
        }
        cout << " | " << setw(8) << a[i][n];
        cout << endl;
    }
    cout << endl;
}

// извеждане на решението
void print_sol(double x[], int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << "X" << i << " = " << x[i] << endl;
    }
    cout << endl;
}

// намиране на първия ненулев елемент в редицата
// a[i][i], a[i+1][i], …, a[n-1][i]
int locate_no_zero(double a[][MAX], int n, int i)
{
    for(int k = i; k < n; k++)
    {
        if(a[k][i] != 0)
        {
            return k;
        }
       
    } 
		  return -1;
}

// размяна на стойностите на две реални променливи
void swap(double& a, double& b)
{
    double t = a;
    a = b;
    b = t;
}

// размяна на i-ти и j-ти редове на системата
void swap_rows(double a[][MAX], int n, int i, int j)
{
    for(int k = 0; k <= n; ++k)
        swap(a[i][k], a[j][k]);
}

// нормализиране на i-ти ред на системата
void normalize_row(double a[][MAX], int n, int i)
{
    double elem = a[i][i];
    for(int k = 0; k <= n; ++k)
        a[i][k] /= elem;
}

// нулиране на коефициентите пред x[i]
// в уравненията от i+1-ви до n-1-ви редове
void eliminate_element(double a[][MAX], int n, int i)
{
    for(int k = i+1; k < n; k++)
    {
        double elem = a[k][i];
        for(int j = i; j <= n; j++)
        {
            a[k][j] -= elem * a[i][j];
        }
        a[k][n] -= a[k][i] * a[i][n];
    }
}

// преобразуване на системата като се нормализира i-ти ред
// и се нулират коефициентите пред x[i] в уравненията
// от i+1-ви до n-1-ви редове, ако е възможно и връщане на
// false, ако преобразуването не е възможно
bool transform(double a[][MAX], int n, int i)
{
    int j;
    j = locate_no_zero(a, n, i);
    if(j < 0)
        return false;
    if(i != j)
        swap_rows(a, n, i, j);
    normalize_row(a, n, i);
    eliminate_element(a, n, i);
    return true;
}

// намиране на решение на трансформираната
// в триъгълен вид система
void solve(double a[][MAX], double x[], int n, int i)
{ 
    double sum = a[i][n];
    for(int k = n-1; k > i; k--)
        sum -= a[i][k] * x[k];
    x[i] = sum / a[i][i];
}

int main()
{
    int n, i;
    double A[MAX][MAX];
    double x[MAX];
    n = init(A);
    print(A, n);

    for(i = 0; i < n; i++)
    {
        if(!transform(A, n, i))
        { 
            cout << "Няма еднозначно решение" << endl;
            return 1;
        }
        print(A, n);
    }

    for(i = n-1; i >= 0 ; i--)
    {
        solve(A, x, n, i);
    }

    print_sol(x, n);
    return 0;
}
