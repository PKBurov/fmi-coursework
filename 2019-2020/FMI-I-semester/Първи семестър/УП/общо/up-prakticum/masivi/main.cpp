#include <iostream>

using namespace std;

int main() {

	int n, q,br, a, b;
	cin >> n;
	int array[100];
	int min;


	for (int i = 0; i < n; i++)
		cin >> array[i];	//vuvejdane na chisla v masiva


    cin>>q;

    while(q!=0)
    {
        cin >> a >> b;
        min = array[a];
        for (int j = a+1; j <= b ; j++)
        {
            if (array[j] < min)
			min = array[j];
        }

        cout << min<<endl;
        q--;
    }



	return 0;
}
