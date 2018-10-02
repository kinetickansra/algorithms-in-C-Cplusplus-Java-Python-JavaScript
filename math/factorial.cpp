//program to find factorial of a given no. using recursive function.

#include <iostream.h>
using namespace std;
int fac(int n){
if
{ 
  n<=1 return 1;
} 
else
{ 
  return n*fac(n-1);
}
}

int main(){
int i,n;
cout<<"enter the no. for finding the factorial";
cin>>n;
i=fac(n);
cout<<"the factorial of the given no. is "<<i;
}
