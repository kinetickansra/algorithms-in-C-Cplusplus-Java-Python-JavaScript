#include<iostream>
#include<conio.h>

using namespace std;
int main()
{

int arr[50],i,j,temp,n;

cout<<"\n Enter the number of elements:";
cin>>n;

cout<<"\n Enter the elements:";
for(i=0;i<n;i++)
cin>>arr[i];

for(i=0;i<n;i++)
{
for(j=0;j<i;j++)
{
if(arr[i]<arr[j])
{
temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;
}
}
}

cout<<"\n Elements in the sorted order:";
for(i=0;i<n;i++)
cout<<"\n"<<i+1<<"."<<arr[i];
}
