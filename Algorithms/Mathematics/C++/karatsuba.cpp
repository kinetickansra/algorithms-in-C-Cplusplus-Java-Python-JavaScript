#include <iostream>
#include<string>
#include <algorithm> 
#include <cmath>
using namespace std;

int karatsuba(int x, int y){
	if ((to_string(x).length()==1) || (to_string(y).length()==1)) {
		return x*y;
  }
	else{
		int n = max(to_string(x).length(),to_string(y).length());
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

int main() {
  cout << karatsuba (923,1723);
}