#include <string>
#include <vector>
#include <iostream>
#include <cmath>

class Main
{
  static void main(std::vector<std::wstring> &args);
  private:
  static int karatsuba(int x, int y);
};


void Main::main(std::vector<std::wstring> &args)
{
  std::wcout << karatsuba(923,1723);
}

int Main::karatsuba(int x, int y)
{
  if (std::to_wstring(x)->length() == 1 || (std::to_wstring(y)->length() == 1))
  {
	  return x*y;
  }
	else
	{
	  int n = std::max(std::to_wstring(x)->length(),std::to_wstring(y)->length());
	  int z = n / 2;
	  int a = x / static_cast<int>(std::pow(10, z));
	  int b = x % static_cast<int>(std::pow(10, z));
	  int c = y / static_cast<int>(std::pow(10, z));
	  int d = y % static_cast<int>(std::pow(10, z));
	  int ac = karatsuba(a,c);
	  int bd = karatsuba(b,d);
	  int adbc = karatsuba(a + b,c + d) - ac - bd;
	  return ac * static_cast<int>(std::pow(10, (2*z))) + (adbc * static_cast<int>(std::pow(10, z))) + bd;
	}
}
