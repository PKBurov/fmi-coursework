typedef double(*type)(double);

const int MAX = 100;

void Map(double X[], int k, type f)
{
    for(int i = 0; i < k; i++)
        X[i] = f(X[i]);
}


void Mapfg(double Y[][MAX], int k, type f, type g)
{
    for(int i = 0; i < k; i++)
    {
        if(i%2 == 0)
        {
            Map(Y[i], k, f);
        }
        else 
        {
            Map(Y[i], k, g);
        }
    }
}
