#include<iostream>
using namespace std;

int exchange_sort(int arr[],int n);
void display(int arr[],int n);

int main()
{
	int arr[100];		
	int i,n;		
	
	cout<<"\n Enter the size of the list:";
	cin>>n;

    cout << "\n Enter the numbers: ";

	for (i = 0; i < n; i++)
		cin >> arr[i];
		
	exchange_sort(arr,n);
	
	display(arr,n);	
	

}/*end of main*/

int exchange_sort(int arr[],int n)
{
	int i, j;
	int tmp;

	for(i=0;i<n-1;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (arr[i]>arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			
			return arr[i];
		}/*end of inner j for loop*/
	}/*end of outer i for loop*/
}/*end of exchange sort*/

void display(int arr[],int n)
{
	int i;
	
	cout<<"\n Your sorted list is:";
	for (i=0;i<n; i++)
		cout <<"\n" <<arr[i];
	
}/*end of display*/
