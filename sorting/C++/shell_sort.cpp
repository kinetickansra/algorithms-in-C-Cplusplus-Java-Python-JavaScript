#include<iostream>
#define MAX 100

using namespace std;

int main()
{
	int arr[MAX],i,n,j,k,incr;
	
	cout<<"\n Enter the number of elements :";
	cin>>n;
	
	cout<<"\n Enter the elements :";
	for(i=0;i<n;i++)
		cin>>arr[i];
		
	cout<<"\n ***************** Shell Sort ******************";
	cout<<"\n Enter maximum increment (odd value) :";
	cin>>incr;
	
	/* shell sort */
	
	while(incr>=1)
	{
		for(i=incr;i<n;i++)
		{
			k=arr[i];
			
			for(j=i-incr;j>=0 && k<arr[j];j=j-incr)
			    arr[j+incr]=arr[j];
			    
			arr[j+incr]=k;
		}
		incr=incr-2;  /* Decrease the increment */
	} /* End of while */
	cout<<"\n sorted list by using shell sort is";
	
	for(i=0;i<n;i++)
	   cout<<"\t"<<arr[i];		
}
	
