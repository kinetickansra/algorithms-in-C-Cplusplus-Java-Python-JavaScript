#include<iostream.h>
#include<conio.h>

void main()
{
int   i,n,position;
float arr[50],new_arr[50];

clrscr();

cout<<"\n Enter the size of the array:";
cin>>n;

cout<<"\n Enter the elements of the array:";

for(i=0;i<n;i++)
cin>>arr[i];

cout<<"\n Enter the position of the element to be deleted:";
cin>>position;

for(i=0;i<position-1;i++)
new_arr[i]=arr[i];

for(i=position;i<n;i++)
new_arr[i-1]=arr[i];

cout<<"\n Your upraded array is:";

for(i=0;i<n-1;i++)
{
cout<<"\n"<<i+1<<". ";
cout<<new_arr[i];
}

getch();
}

