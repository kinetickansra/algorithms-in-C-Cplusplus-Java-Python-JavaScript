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

	static void bubblesort(std::vector<int> &arr);
};


Scanner *Main::scn = new Scanner(System::in);

void Main::main(std::vector<std::wstring> &args)
{
	std::vector<int> arr = takeInput();

	bubblesort(arr);
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

void Main::bubblesort(std::vector<int> &arr)
{
	for (int i = 0;i < arr.size() - 1;i++)
	{
		for (int j = 0;j < arr.size() - 1 - i;j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
