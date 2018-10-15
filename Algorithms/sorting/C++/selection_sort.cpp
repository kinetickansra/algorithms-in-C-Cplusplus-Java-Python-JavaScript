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
	static void selectionsort(std::vector<int> &arr);
};


Scanner *Main::scn = new Scanner(System::in);

void Main::main(std::vector<std::wstring> &args)
{
	std::vector<int> arr = takeInput();

	selectionsort(arr);
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

void Main::selectionsort(std::vector<int> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}

		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
	}
}
