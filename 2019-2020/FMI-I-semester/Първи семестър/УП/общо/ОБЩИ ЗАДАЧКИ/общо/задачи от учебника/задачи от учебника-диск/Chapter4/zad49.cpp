#include <iostream.h>
const int MAX_SIZE = 20;

// въвеждане на квадратна матрица по редове
void ReadMatrix(int k, int x[][20])
{
    cout << "Въведете " << k << " реда с по " 
         << k << " цели числа!\n";
    for(int i = 0; i < k; i++)
    {
        for(int j = 0; j < k; j++)
        {
            cin >> x[i][j];
        }
    }
}

// извеждане на матрица по редове
void WriteMatrix(int k, int x[][20])
{ 
    for(int i = 0; i < k; i++)
    { 
        for(int j = 0; j < k; j++)
        {
            cout << x[i][j] << " ";
        }
        cout << endl;
    }
}

// проверяване дали редицата x[0], x[1], …, x[k-1]
// има два последователни нулеви елемента
bool Zero(int k, int x[])
{
    int i = -1;
    do
    {
        i++;
    }while((x[i] != 0 || x[i+1] != 0) && i < k-2);

    return x[i] == 0 && x[i+1] == 0;
}

int main()
{
    cout << "Въведете стойност на n от 2 до "
         << MAX_SIZE << " : ";
    int n;
    cin >> n;

    cout << "Въведете елементите на матрицата A: \n";
    int a[MAX_SIZE][MAX_SIZE]; 
    ReadMatrix(n, a);

    cout << "Матрица A:\n"; 
    WriteMatrix(n, a);

    for(int i = 0; i < n; i++)
    {
        if(Zero(n, a[i])) 
            cout << i << endl;
    }
    return 0;
}
