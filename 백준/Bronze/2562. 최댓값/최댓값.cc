#include <iostream>

using namespace std;

int main() 
{
	int idx = 0, max =0;

	int arr[9];

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
			idx = i;
		}
		
	}

	cout << max << endl;
	cout << idx + 1 << endl;

	return 0;
}