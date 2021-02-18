//program to find factorial of a given no. without using recursive function.

#include <iostream>
using namespace std;
int fac(int n){
 int m=1;
    for(int j=1; j<=n; j++)
    {
        m=m*j;
    }
    return m;
}

int main(){
int i,n;
cout<<"enter the no. for finding the factorial : \n";
cin>>n;
i=fac(n);
cout<<"the factorial of the given no. is "<<i;
}
