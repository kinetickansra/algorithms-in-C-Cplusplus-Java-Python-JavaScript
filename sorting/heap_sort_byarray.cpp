#include <iostream>
using namespace std;

void Max_Heap(int arr[], int i, int n);
void Heap_Sort(int arr[], int n);
void Build_MaxHeap(int arr[], int n);
void display(int arr[],int n);
 
int main()
{
	int n, i;
	cout<<"\n Enter the size of the list: ";
	cin>>n;
	n++;
	int arr[n];
	
	cout<<"\n Enter the elements :";
	for(i = 1; i < n; i++)
		cin>>arr[i];
	
	Build_MaxHeap(arr, n-1);
	Heap_Sort(arr, n-1);
	display(arr,n);	
	
}/*END OF MAIN*/

void Max_Heap(int arr[], int i, int n)
{
	int j, temp;
	temp = arr[i];
	j = 2*i;
 
 	while (j <= n)
	{
		if (j < n && arr[j+1] > arr[j])
		j = j+1;
		
		if (temp > arr[j]) /* Break if parent value is already greater than child value*/
			break;
		
		else if (temp <= arr[j]) /* Switching value with the parent node if temp < a[j]*/
		{
			arr[j/2] = arr[j];
			j = 2*j;
		}
	}
	arr[j/2] = temp;

}/*END OF Max Heap*/

void Heap_Sort(int arr[], int n)
{
	int i, temp;
	for (i = n; i >= 2; i--) /* Storing maximum value at the end*/
	{
		temp = arr[i];
		arr[i] = arr[1];
		arr[1] = temp;
		Max_Heap(arr, 1, i - 1); /* Building max heap of remaining element*/
	}
}/*end of heap sort*/

void Build_MaxHeap(int arr[], int n)
{
	int i;
	for(i = n/2; i >= 1; i--)
		Max_Heap(arr, i, n);
}/*end of Build Max Heap*/

void display(int arr[],int n)
{
	int i;
	cout<<"\n Your sorted list is:";
	for (i = 1; i < n; i++)
	cout<<"\n"<<i<<"->"<<arr[i];
}/*end of display*/
