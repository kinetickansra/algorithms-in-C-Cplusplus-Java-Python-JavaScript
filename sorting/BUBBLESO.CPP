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
for(j=0;j<n-i-1;j++)
{
if(arr[j]>arr[j+1])
{
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}

cout<<"\n Elements in the sorted order:";
for(i=0;i<n;i++)
cout<<"\n"<<i+1<<"."<<arr[i];

}
