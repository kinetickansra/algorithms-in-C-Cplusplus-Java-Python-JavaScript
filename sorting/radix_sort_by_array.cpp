#include <iostream>
 
using namespace std;

int getMax(int arr[], int n);
void countSort(int arr[], int n, int exp);
void radixsort(int arr[], int n);
void display(int arr[],int n);
int main()
{
	int n, i;

	cout<<"\n Enter the size of the list: ";
	cin>>n;
 
	int arr[n];
	

	for(i = 0; i < n; i++)
	{
		cout<<"Enter element "<<i+1<<": ";	
		cin>>arr[i];	
	}
 
	radixsort(arr, n);
	display(arr,n);	
 
}

int getMax(int arr[], int n) /*Get maximum value from array*/ 
{
	int max = arr[0];
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}
 
void countSort(int arr[], int n, int exp)
{ 
	int output[n], i, count[10] = {0}; /* Count[i] array will be counting the number of array values having that 'i' digit at their (exp)th place*/
 
	for (i = 0; i < n; i++) /* Count the number of times each digit occurred at (exp)th place in every input*/
		count[(arr[i] / exp) % 10]++;
 
	for (i = 0; i < 10; i++) /* Calculating their cumulative count */
		count[i] += count[i-1];
 
	for (i = n - 1; i >= 0; i--) /* Inserting values according to the digit '(arr[i] / exp) % 10' fetched into count[(arr[i] / exp) % 10]*/
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
 
	for (i = 0; i < n; i++) /* Assigning the result to the arr pointer of main()*/
		arr[i] = output[i];
}
 
void radixsort(int arr[], int n)
{
	int exp, m;
	m = getMax(arr, n);
 
	for (exp = 1; m/exp > 0; exp *= 10) /* Calling countSort() for digit at (exp)th place in every input */
		countSort(arr, n, exp);
}

void display(int arr[],int n)
{
	int i;
	cout<<"\n Your sorted list is:";
	for (i = 0; i < n; i++)
	cout<<"\n"<<i<<"->"<<arr[i];
}/*end of display*/
