#include <iostream.h>
const int MAX_N = 100;

int n;
int board[MAX_N][MAX_N];

void printBoard()
{ 
    cout << endl;
    for(int i = 0; i < n; i++)
    { 
        for(int j = 0; j < n; j++)
        {
            cout << (board[i][j] ? "*" : "0");
        }
        cout << endl;
    }
}

bool isFree(int i, int j)
{ 
    for(int k = 0; k < n; k++)
    {
        if(board[i][k] || board[k][j])
        {
            return false;
        }
    }
    return true;
}

void generate(int i)
{ 
    if(i > n)
        return;  

    if(i == n)
    {
        printBoard(); 
        return;
    }

    for(int j = 0; j < n; j++)
    { 
        if(isFree(i, j))
        {
            board[i][j] = 1;
            generate(i+1);
            board[i][j] = 0;
        }
    }
}

int main()
{
    n = 5;
    generate(0);
    return 0;
}
