#include<stdio.h>
#include<conio.h>
int binarysearch(int num[],int n,int item);
//int linearsearch(int num[],int n,int item);
int main()
{
int i,n,num[50],index,item;
//clrscr();
printf("\n Enter the number of elements:");
scanf(" %d",&n);
printf("\n Enter the elements in sorted order:");
for(i=0;i<n;i++)
scanf(" %d",&num[i]);
printf("\n Enter the item to be searched:");
scanf("%d",&item);
index=binarysearch(num,n,item);
if(index==1)
printf("\n %d is not found in array",item);
else
printf("\n %d found at position %d",item,(index+1));
//getch();
}
/*int linearsearch(int num[],int n,int item)
{
int i=0;
while(i<n && item!=num[i])
i++;
if(i<n)
return i;
else
return 1;
}*/
int binarysearch(int num[],int n,int item)
{
int low=0,up=n-1,mid;
while(low<=up)
{
mid=(low+up)/2;
if(item>num[mid])
low=mid+1;
else if(item<num[mid])
up=mid-1;
else
return mid;
}
return 1;
}
