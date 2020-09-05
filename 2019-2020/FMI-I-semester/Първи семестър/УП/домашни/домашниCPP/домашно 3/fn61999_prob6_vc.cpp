/**
*
* Solution to homework task
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2016/2017
*
* @author Silvia Ivanova
* @idnumber 61999
* @task 6
* @compiler VC
*
*/

#include<iostream>  
using namespace std;


void selectionSort(double arrFN[], double arrTasks[], double arrPoints[], int n, bool isSortingByProblem)
{
	int minElement;

	for (int i = 0; i < n - 1; i++)
	{
		minElement = i;

		for (int j = i + 1; j < n; j++)
		{

			if (arrFN[j] < arrFN[minElement])
			{
				if (isSortingByProblem == false)
				{
					minElement = j;
				}

				if (isSortingByProblem == true && arrTasks[j] == arrTasks[minElement])
				{
					minElement = j;
				}
			}
		}

		if (minElement != i)
		{
			swap(arrFN[i], arrFN[minElement]);
			swap(arrTasks[i], arrTasks[minElement]);
			swap(arrPoints[i], arrPoints[minElement]);
		}
	}

}

int main()
{
	double Fnumbers[10000];
	double tasks[10000];
	double points[10000];

	unsigned int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> Fnumbers[i];
		cin >> tasks[i];
		cin >> points[i];

	}

	selectionSort(Fnumbers, tasks, points, n, false);
	selectionSort(tasks, Fnumbers, points, n, true);

	for (int t = 0; t < n; t++)
	{
		cout << Fnumbers[t] << " "
			<< tasks[t] << " "
			<< points[t] << '\n';

	}

	return 0;
}
