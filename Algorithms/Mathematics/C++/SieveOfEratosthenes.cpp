/*Sieve of Eratosthenes is a simple, ancient algorithm for finding all prime numbers up to any given limit.
It does so by iteratively marking as composite (i.e., not prime) the multiples of each prime, starting with the first prime number, 2.*/
#include<bits/stdc++.h>
#define ar_size 100000
using namespace std;

bool prime[ar_size];

void sieve(){
   int i,j;
   memset(prime,true,ar_size);
   prime[0]=prime[1]=false;

   for(i=2;i*i<=ar_size;i++)
   {
       if(prime[i]==true)
       {
           for(j=i*i;j<=ar_size;j=j+i)
           {
               prime[j]=false;
           }
       }
   }
}

int main()
{
    int num;
    sieve();
        do
    {
        cout<<"Enter a number to check its primality(-1 to Exit): ";
        cin>>num;
      if(num!=-1)
      {
        if(num == 0 || num == 1)
            cout<<"Number is neither prime nor composite!"<<endl;
        else if(prime[num]==true)
            cout<<"Number is prime! "<<endl;
        else
            cout<<"Number is composite! "<<endl;
      }

    }while(num!=-1);
}
