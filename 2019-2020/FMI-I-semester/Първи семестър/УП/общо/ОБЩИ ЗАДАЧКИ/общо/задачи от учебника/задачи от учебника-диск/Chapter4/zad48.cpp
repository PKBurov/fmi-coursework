#include <iostream.h>
#include <math.h>

const int MAX_SIZE = 20;

// определя дали a, b и c са страни на триъгълник
bool Triangle(double a, double b, double c)
{
    return (a > 0 && b > 0 && c > 0) &&
           (a+b > c && a+c > b && b+c > a);
}

// въвежда координатите на k триъгълника
void ReadMatrix(int k, double x[][3])
{
    for(int i = 0; i < k; i++)
    {
        do
        {
            cout << "Въведете елементите на " << i
                 << "-тия ред на матрицата: ";
            cin >> x[i][0] >> x[i][1] >> x[i][2];
        } while(!Triangle(x[i][0], x[i][1], x[i][2]));
    }
}

// намира лицето на триъгълник
double Area(double a, double b, double c)
{
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

// намира максималното лице на k триъгълника
double MaxArea(int k, double x[][3])
{
    int i;
    double max = Area(x[0][0], x[0][1], x[0][2]), d;

    for(i = 1; i < k; i++)
    {
        d = Area(x[i][0], x[i][1], x[i][2]);
        if(d > max)
            max = d;
    }
    return max;
}

int main()
{
    cout << "Въведете стойност на n от 1 до "
         << MAX_SIZE << " : ";
    int n; 
    cin >> n;

    cout << "Въведете страните на " << n << " триъгълника: \n";
    double A[MAX_SIZE][3]; 
    ReadMatrix(n, A);

    cout << MaxArea(n, A) << endl;
    return 0;
}
