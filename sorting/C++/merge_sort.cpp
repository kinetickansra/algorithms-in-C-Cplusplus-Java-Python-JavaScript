#include<iostream>
#define MAX 100
using namespace std;

void merge(int arr1[],int arr2[],int arr3[],int n1,int n2);

int main()
{
	int arr1[MAX],arr2[MAX],arr3[MAX],n1,n2,i;
	
	cout<<"\n Enter the number of elements in array 1:";
	cin>>n1;
	
	cout<<"\n Enter the elements in sorted order :";
	for(i=0;i<n1;i++)
	cin>>arr1[i];

	cout<<"\n Enter the number of elements in array 2:";
	cin>>n2;
	
	cout<<"\n Enter the elements in sorted order :";
	for(i=0;i<n2;i++)
	cin>>arr2[i];
	
	merge(arr1,arr2,arr3,n1,n2);
	
	cout<<"\n The Merged list is :\n";
	for(i=0;i<n1+n2;i++)
	cout<<"\t"<<arr3[i];
	
}

void merge(int arr1[],int arr2[],int arr3[],int n1,int n2)
{
	int i=0,j=0,k=0;
	
	while( (i<n1) && (j<n2) )
	{
		if(arr1[i] < arr2[j])
			arr3[k++]=arr1[i++];
			
		else
			arr3[k++]=arr2[j++];	
	}
	
	while(i<n1) /* Put remaining elements of arr1 into arr3 */
		arr3[k++]=arr1[i++];
	
	while(j<n2) /* Put remaining elements of arr2 into arr3 */
		arr3[k++]=arr2[j++];
		
		
} /* End of merge */

