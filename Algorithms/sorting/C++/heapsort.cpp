
#include <iostream>

using namespace std;

// To heapify a subtree rooted with node i which is
// an index in array.Where n is the size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;


    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;


    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        //  heapify the sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i=n-1; i>=0; i--)
    {

        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
}

/*  function to print array  */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver program
int main()
{  int n;
cout<<"enter size of array"<<endl;
cin>>n;
    int * arr= NULL;
  arr= new int [n];
cout<<"enter array"<<endl;
  for (int i=0;i<n;i++)
  {
      cin>>arr[i];
  }

    heapSort(arr, n);

    cout << "Sorted array is "<<endl;
    printArray(arr, n);
}
