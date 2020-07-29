#include <iostream.h>
const int MAX_SIZE = 20;

bool Triangle(double a, double b, double c)
{ 
    return (a > 0 && b > 0 && c > 0) &&
           (a+b > c && a+c > b && b+c > a);
}

void ReadMatrix(int k, double x[][3])
{
    for(int i = 0; i < k; i++)
    {
        cout << "Въведете елементите на " << i
             << "-тия ред на матрицата: ";
        cin >> x[i][0] >> x[i][1] >> x[i][2];
    }
}

int main()
{
    cout << "Въведете стойност на n от 1 до "
         << MAX_SIZE << " : ";
    int n; 
    cin >> n;

    cout << "Въведете матрицата: \n";
    double A[MAX_SIZE][3]; 
    ReadMatrix(n, A);

    for(int i = 0; i < n; i++)
    {
        if(Triangle(A[i][0], A[i][1], A[i][2]))
        {
            cout << "(" << A[i][0] << ", " << A[i][1] << ", " << A[i][2]
                 << ") могат да са страни на триъгълник.\n";
            
        }
    }
		 return 0;
}

