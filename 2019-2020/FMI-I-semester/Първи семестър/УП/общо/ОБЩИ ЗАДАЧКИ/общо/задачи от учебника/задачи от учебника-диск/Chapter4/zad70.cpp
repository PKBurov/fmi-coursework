const int MAX = 100;

void MapfgColumns(double Y[][MAX], int k, double (*f)(double), double (*g)(double))
{
    for(int j = 0; j < k; j++)
    {
	    for(int i = 0; i < k; i++)
     {
        	if(j%2 == 0) 
                Y[i][j] = f(Y[i][j]);
		       else 
                Y[i][j] = g(Y[i][j]);
						}
    }
}
