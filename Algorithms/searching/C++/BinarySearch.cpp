#include <string>
#include <vector>
#include <iostream>

class BinarySearch
{

	static void main(std::vector<std::wstring> &args);

};


void BinarySearch::main(std::vector<std::wstring> &args)
{
 Scanner *scn = new Scanner(System::in);
 int N = scn->nextInt();
 std::vector<int> a(N);
 bool flag = false;
 for (int i = 0;i < N;i++)
 {
	 a[i] = scn->nextInt();
 }
 int low = 0, high = static_cast<a::length*>(-1);
 int mid;

 int n = scn->nextInt();
 while (high >= low)
 {
	 mid = (high + low) / 2;
	 if (a[mid] > n)
	 {
		high = mid - 1;
	 }
	 else if (a[mid] < n)
	 {
		 low = mid + 1;
	 }
	 else if (a[mid] == n)
	 {
			 std::wcout << mid << std::endl;
		 flag = true;
		 break;
	 }

 }
 if (flag == false)
 {
	 std::wcout << -1 << std::endl;
 }

}
