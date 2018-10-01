#include<iostream>
#define MAX 100

using namespace std;

void quick(int arr[],int low,int up);
int partition(int arr[],int low,int up);

int main()
{
	int arr[MAX],i,n,j,k,incr;
	
	cout<<"\n Enter the number of elements :";
	cin>>n;
	
	cout<<"\n Enter the elements :";
	for(i=0;i<n;i++)
		cin>>arr[i];
		
	quick(arr,0,n-1);	
	cout<<"\n ***************** Quick Sort ******************";
	
	cout<<"\n sorted list by using quick sort is";
		
	for(i=0;i<n;i++)
	   cout<<"\t"<<arr[i];		
}
	
void quick(int arr[],int low,int up)
{
	int pivloc;
	
	if(low>=up)
	    return;
	    
	pivloc=partition(arr,low,up);
	quick(arr,low,pivloc-1); /*process left sublist */
	quick(arr,pivloc+1,up); /* process right sublist */
	    
} /* End of quick() */

int partition(int arr[],int low,int up)
{
	int temp,i,j,pivot;
	i=low+1;
	j=up;
	pivot=arr[low];
	
	while(i<=j)
	{
		while((arr[i] < pivot) && (i<up) )
			i++;
		
		while(arr[j] > pivot)
			j--;
		
		if(i<j)
		{
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			i++;
			j--;
			
		}
		
		else
			i++;	
						
	}
	
	arr[low]=arr[j];
	arr[j]=pivot;
	return j;
} 
/* End of partition */

