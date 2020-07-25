#include <iostream.h>
#include <math.h>

const int MAX_SIZE = 20;

void ReadSequence(int k, double x[])
{
    for (int i = 0; i < k; i++)
    {
        cout << i << "-и елемент: ";
        cin >> x[i];
    }
}

void WriteSequence(int k, double x[])
{
    for(int i = 0; i < k; i++)
    {
        cout << x[i] << " ";
    }
    cout << endl;
}

void Expressions(int k, double x[], double& xr1, double& xr2)
{
    xr1 = 0; int i;
    for(i = 0; i < k; i++)
    {
        xr1 = xr1 + x[i];
    }
    xr1 = xr1/k;
    xr2 = 0;
    for(i = 0; i < k; i++)
    {
        xr2 = xr2 + (x[i]-xr1)*(x[i]-xr1);
    }
    xr2 = sqrt(xr2)/k;
    return;
}

int main()
{
    cout << "Въведете дължината на редицата a (n>0): ";
    int n;
    cin >> n;

    cout << "Въведете елементите на редицата a: \n";
    double a[MAX_SIZE];
    ReadSequence(n, a);

    cout << " Въведете дължината на редицата b (m>0): ";
    int m; 
    cin >> m;

    cout << " Въведете елементите на редицата b: \n";
    double b[MAX_SIZE];
    ReadSequence(m, b);

    cout << " Въведете дължината на редицата c (p>0): ";
    int p; 
    cin >> p;

    cout << " Въведете елементите на редицата c: \n";
    double c[MAX_SIZE];
    ReadSequence(p, c);

    double y1, y2;
    cout << "Средно аритметичната стойност и "
            "стандартното отклонение на:\n";
    WriteSequence(n, a);
    Expressions(n, a, y1, y2);
    cout << "са: " << y1 << " и " << y2 << endl;

    cout << "Средно аритметичната стойност и "
            "стандартното отклонение на:\n";
    WriteSequence(m, b);
    Expressions(m, b, y1, y2);
    cout << "са: " << y1 << " и " << y2 << endl;

    cout << "Средно аритметичната стойност и "
            "стандартното отклонение на:\n";
    WriteSequence(p, c);
    Expressions(p, c, y1, y2);
    cout << "са: " << y1 << " и " << y2 << endl;

    return 0;
}
