#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	int cnt = N;

	int arr[101];
	bool flag = true;
	

	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
		if (arr[i] == 1) cnt--;
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 2; j * j <= arr[i]; j++)
		{
			if (arr[i] % j == 0)
			{
				cnt--;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
