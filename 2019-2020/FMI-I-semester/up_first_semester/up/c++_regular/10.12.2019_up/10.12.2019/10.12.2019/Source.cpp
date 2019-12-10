#include<iostream>

using namespace std;

void bubbleSort(int arr[], int n);
void swapp(int *xp, int *yp);
void selectionSort(int arr[], int n);
int* createEF(int* arr, int* arr2, int* arr3,int n, int	m);
int main()
{
	int arr[] = {1,5,9};
	int arr2[] = {10,15,12};
	const int MAX = 6;
	int arr3[MAX];
	createEF(arr, arr2, arr3, 4, 5);
	for (int i = 0; i < MAX; i++){
		cout<<arr3[i];
	}

	return 0;
}
void swapp(int* xp, int* yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}
void bubbleSort(int arr[], int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)

		// Last i elements are already in place  
		for (j = 0; j < n - i - 1 ; j++)
			if (arr[j] > arr[j + 1])
				swapp(&arr[j], &arr[j + 1]);
	for (int i = 0; i < n; i++){
		cout << arr[i];
	}
}
void selectionSort(int arr[], int n) {

	int i = 0, j = 0, min_index = 0;
	for (int i = 0; i <= n-1; i++){
		min_index = i;
		for (int j = i+1; j < n; j++){
			if (arr[j]<arr[min_index]){
				min_index = j;
				swapp(&arr[min_index], &arr[i]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i];
	}	
}
int *createEF(int *arr, int *arr2, int *arr3, int n, int m) {
	
	int *ptr = &arr[0];
	int *ptr2 = &arr2[0];
	int size = n + m;
	for ( int i = 0 ; i <= size ;i++){
		if (*ptr > *ptr2) {
			arr3[i]= *ptr2;
			ptr2++;
		}else {
			arr3[i]=*ptr;
			ptr++;
		}
	}
	return arr3;
}

