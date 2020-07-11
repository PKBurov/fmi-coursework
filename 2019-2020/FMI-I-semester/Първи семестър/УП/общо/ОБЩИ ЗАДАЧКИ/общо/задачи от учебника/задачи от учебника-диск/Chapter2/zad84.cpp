#include <iostream.h>
#include <iomanip.h>

int main() 
{
    cout  << setw(8) << "a" << setw(8) << "b" 
          << setw(8) << "c" << setw(8) << "f\n";
    for(int i = 1; i >= 0; i--)
    {
        for(int j = 1; j >= 0; j--)
        {
            for(int k = 1; k >= 0; k--)
            { 
                cout << setw(8);
                if(i) 
                    cout << "true"; 
                else
                    cout << "false";

                cout << setw(8);
                if(j)
                    cout << "true";
                else
                    cout << "false";

                cout << setw(8);
                if(k)
                    cout << "true"; 
                else
                    cout << "false"; 

                cout << setw(8);
                if(i && j || !(j || k))
                    cout << "true\n"; 
                else
                    cout << "false\n";
            }
									}
				}
    return 0;
}
