#include <string>
#include <vector>
#include <iostream>

class Main
{
   public:
   static Scanner *scn;

	static void main(std::vector<std::wstring> &args);
	static std::vector<int> takeInput();

	static void display(std::vector<int> &arr);

	static void insertionsort(std::vector<int> &arr);

};


Scanner *Main::scn = new Scanner(System::in);

void Main::main(std::vector<std::wstring> &args)
{
	std::vector<int> arr = takeInput();

	insertionsort(arr);
	display(arr);
}

std::vector<int> Main::takeInput()
{
	int n = scn->nextInt();
	std::vector<int> arr(n);

	for (int i = 0; i < n; i++)
	{
		arr[i] = scn->nextInt();
	}
	return arr;
}

void Main::display(std::vector<int> &arr)

{

	for (auto val : arr)
	{
		std::wcout << val << std::endl;
	}
}

void Main::insertionsort(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > temp) // shifting
		{
			arr[j + 1] = arr[j];
			j--;
		}

		arr[j + 1] = temp;
	}
}
