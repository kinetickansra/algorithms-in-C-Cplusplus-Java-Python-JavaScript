#include <stdio.h>
#include <math.h>
#include <string.h>

#define max(x,y) ((x) >= (y)) ? (x) : (y)

int intlen(int n){
    int count = 0;
    while(n != 0)
    {
        // n = n/10
        n /= 10;
        ++count;
    }
    return count;
}

int karatsuba(int x, int y){
	if (intlen(x)==1 || intlen(y)==1) {
		return x*y;
  }
	else{
		int n = max(intlen(x),intlen(y));
		int z = n / 2;
		int a = x / (int)pow(10,z);
		int b = x % (int)pow(10,z);
		int c = y / (int)pow(10,z);
		int d = y % (int)pow(10,z);
		int ac = karatsuba(a,c);
		int bd = karatsuba(b,d);
		int adbc = karatsuba(a+b,c+d) - ac - bd;
		return ac * pow(10,2*z) + (adbc * pow(10,z)) + bd;
}
}
int main(void) {
  printf("%d",karatsuba (923,1723));
  return 0;
}