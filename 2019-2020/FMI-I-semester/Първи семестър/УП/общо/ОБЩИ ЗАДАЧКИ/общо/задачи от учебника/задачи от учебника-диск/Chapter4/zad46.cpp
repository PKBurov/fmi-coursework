#include <iostream.h>
#include <math.h>

const int MAX_SIZE = 30;

double Distance(double x1, double y1, double x2, double y2)
{ 
    return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}

void ReadPoints(int k, double x[][2])
{
    for(int i = 0; i < k; i++)
    {
        cout << "Координати на " << i << "-та точка: ";
        cin >> x[i][0] >> x[i][1];
    }
}

int main()
{
    cout << "Въведете броя на точките n от 1 до "
         << MAX_SIZE << " : ";
    int n; 
    cin >> n;

    cout << "Въведете точките: \n";
    double P[MAX_SIZE][2]; 
    ReadPoints(n, P);

    // намиране и извеждане на разстоянието
    // между всеки две точки
    for(int i = 0; i < n-1; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            cout << "d(" << i << ", " << j << ")= "
                 << Distance(P[i][0], P[i][1], P[j][0], P[j][1])
                 << endl;
        }
    }
    return 0;
}
