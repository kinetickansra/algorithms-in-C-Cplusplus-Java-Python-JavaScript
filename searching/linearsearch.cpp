#include<iostream>
#include<conio.h>

using namespace std;
int linearsearch(int num[],int n,int item);
int main()
{
int i,n,num[50],index,item;

cout<<"\n Enter the number of elements of the list:";
cin>>n;
cout<<"\n Enter the elements:";
for(i=0;i<n;i++)
cin>>num[i];
cout<<"\n Enter the item to be searched:";
cin>>item;
index=linearsearch(num,n,item);
if(index==-1)
cout<<"\n %d is not found in list"<<item;
else
cout<<item<<" found at position "<<(index+1);

}
int linearsearch(int num[],int n,int item)
{
int i=0;
while(i<n && item!=num[i])
i++;
if(i<n)
return i;
else
return -1;
}
