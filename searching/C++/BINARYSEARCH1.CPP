/*author: rishav krishna(https://github.com/rishu22)*/
#include<stdio.h>
#include<conio.h>
int main()
{
	int arr[10],i,search,lb=0,ub,mid,n,p=0;

	printf("enter size of array");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter elements");
		scanf("%d",&arr[i]);
	}
	printf("enter element to be search");
	scanf("%d",&search);
	ub=n;
	mid=(lb+ub)/2;
	while(ub>=lb)
	{
		if(arr[mid]==search)
		{
			p=1;
			break;
		}
		if(search<arr[mid])
		{
			ub=mid-1;
			mid=(lb+ub)/2;
		}
		else
		{
			lb=mid+1;
			mid=(lb+ub)/2;
		}
	}
	if(p==1)
	printf("found");
	else
	printf("not found");
	getch();
}
