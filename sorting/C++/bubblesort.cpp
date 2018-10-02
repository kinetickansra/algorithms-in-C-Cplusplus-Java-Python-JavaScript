#include <iostream>
#include <vector>
using namespace std;

int main()
{
	cout << "Please enter any amount of numbers in whatever order. Seperate them by space: ";
	vector<double> list;						// list contain user inputs
	while (1)									// loop until '\n' is detected
	{
		double inputNumber;
		cin >> inputNumber;
		if (cin.get() == '\n')
			break;
		list.push_back(inputNumber);
	}

	for (int i(0); i < list.size(); ++i)		// bubble sort
		for (int j(i); j < list.size(); ++j)
		{
			if (list[i] > list[j])
			{
				double temp = list[i];			// temporary double to store number for swapping
				list[i] = list[j];
				list[j] = temp;
			}
		}

	for (auto each : list)
		cout << each << " ";					// print sorted list

	return 0;
}