#include<iostream>
#include<algorithm>
using namespace std;
void twoWaySort(int arr[], int n)
{
	// Make all odd numbers negative 
	for (int i = 0; i < n; i++)
		if (arr[i] & 1) // Check for odd 
			arr[i] *= -1;

	// Sort all numbers 
	sort(arr, arr + n);

	// Retaining original array 
	for (int i = 0; i < n; i++)
		if (arr[i] & 1)
			arr[i] *= -1;
	/*int arr[] = { 1, 3, 2, 7, 5, 4 }; 
    int n = sizeof(arr) / sizeof(int); 
    twoWaySort(arr, n); 
    for (int i = 0; i < n; i++) 
        cout << arr[i] << " "; 
    return 0; */
}
float BigSmall(float* arr,int size) {
	for (int i = 0; i < size; i++){
		if (arr[0]<arr[i]){
			arr[0] = arr[i];
		}
	}
	return arr[0];
}
double Sum_index(double* arr,int size_arr)
{
	double sum = 0;
	for (int i = 0; i < size_arr; i++){
		if (i%2==0){
			sum += arr[i];
		}
	}
	return sum;
}
void average_digit_rounded_down(int number) {
	double average = 0;
	int count = 0, digit = 0, sum = 0;
	do{
		digit = number % 10;
		sum += digit;
		count++;
		number /= 10;
	} while (number>0);
	average = sum / count;
	if (number == 0) {	cout << '0';}
	average = average - 0.5;
	cout << (int)average;
}
int even_sum_index(int* arr, int arr_size)
{
	int sum = 0;
	for (int i = 0; i < arr_size; i++){
		if ( (arr[i]%2) ==0 ){
			sum += arr[i];
		}
	}
	return sum;
}
void sec_hour(unsigned int number) {
	if (number > 8600) { cout << "Enter a possitive correct number!" << endl; system("Pause"); exit(1); }
	int hour = 0,minute=0,hour_count=0,minute_count=0, minute_minus_second=0;
	do{
		minute = number - 1;
		number = number - 1;
		minute_minus_second++;

		if (minute_minus_second == 60){
			minute_count++;
			minute_minus_second = 0;
		}if (minute_count==60){
			hour_count++;
			minute_count = 0;
		}
	} while (number>0);
	cout << hour_count << ":" << minute_count << endl;
}
int main()
{
	/*double arr1[] = { -1.5 };
	double arr2[] = { -1.3,2.1 };
	double arr3[] = { -1.0, 53.4, 45.5, 55.4, 123.4};

	cout << Sum_index(arr1, 1) << endl;
	cout << Sum_index(arr2, 2) << endl;
	cout << Sum_index(arr3, 5) << endl;*/
	/*chetvurta(4);
	cout << endl;
	chetvurta(54);
	cout << endl;
	chetvurta(13234);*/
	
	//vtora(4500);
	cout << endl;
	//vtora(8500);

	return 0;
}