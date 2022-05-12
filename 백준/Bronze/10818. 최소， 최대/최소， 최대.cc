#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	int min = -1000000, max = 1000000;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr+N);

	cout << arr[0] << " " << arr[N - 1] << "\n";

	return 0;
}