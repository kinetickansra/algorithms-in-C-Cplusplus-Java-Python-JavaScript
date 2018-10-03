#include<iostream>
using namespace std;

/* A function to do counting sort of array according to
 the digit represented by exp.*/
int countSort(int arr[], int n, int exp)
{

    int output[n];
    int i, count[n] ;
    for (int i=0; i < n; i++)
       count[i] = 0;

    // Storing count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%n ]++;

    //  count[i] now contains actual position of this digit in output[]

    for (i = 1; i < n; i++)
        count[i] += count[i - 1];

    //  output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%n] - 1] = arr[i];
        count[(arr[i]/exp)%n]--;
    }


    for (i = 0; i < n; i++)
        arr[i] = output[i];
}


// The main function to that sorts arr[] of size n using Radix Sort
void sort(int arr[], int n)
{

    countSort(arr, n, 1);
    countSort(arr, n, n);
}

// Function to print an array
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

