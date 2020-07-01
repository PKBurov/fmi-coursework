#include <iostream.h>

int main()
{
    int a, b;
    double avg;
    cout << "a= ";
    cin >> a;
    cout << "b= ";
    cin >> b;
    avg = (a + b)/2.0;
    // Алтернативният вариант е:
    // avg = (double)(a + b)/2;
    cout << "avg (" << a << ", "<< b  << ") = " << avg << endl;
    return 0;
}
