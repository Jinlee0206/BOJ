#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, sum = 0, res = 0, min=0;

	cin >> N >> M;

	vector<int> a(N);

	for (int i = 0; i < N; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < N-2; i++)
	{
		for (int j = i+1; j < N-1; j++)
		{
			for (int k = j+1; k < N; k++)
			{
				sum = a[i] + a[j] + a[k];
				if (M-sum >=0 && sum > min) min = sum;
			}
		}
	}

	cout << min << endl;


	return 0;
}
