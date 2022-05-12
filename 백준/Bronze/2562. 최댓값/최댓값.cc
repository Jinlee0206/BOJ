#include <iostream>

using namespace std;



int main() {
	//ios_base::sync_with_stdio(0);

	int max =0 , maxIndex =0;
	int arr[9];

	for (int i = 0; i < 9; i++)
	{
		cin >> arr[i];
	}

	for (int i = 0; i < 9; i++)
	{
		if (max < arr[i]) {
			max = arr[i];
			maxIndex = i;
		}
	}

	cout << max << endl;
	cout << maxIndex + 1 << endl;

	return 0;
}