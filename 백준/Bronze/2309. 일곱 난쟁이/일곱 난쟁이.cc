#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 조합
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	vector<int> vec;

	for (int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;
		vec.push_back(n);
		sum += n;
	}

	sort(vec.begin(), vec.end());
	sum -= 100;
	
	int first, second;
	for (int i = 0; i < 9; i++)
	{
		for (int j = i + 1; j < 9; j++)
		{
			int tmp = vec[i] + vec[j];
			if (tmp == sum)
			{
				first = i;
				second = j;
			}
		}
	}

	for (auto res : vec)
	{
		if (res == vec[first] || res == vec[second]) continue;
		cout << res << "\n";
	}

	return 0;
}

// 순열
/*
int main() {
	vector<int> vec(9);

	for (int i = 0; i < 9; i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	do {
		int sum = 0;
		for (int i = 0; i < 7; i++) {
			sum += vec[i];
		}

		if (sum == 100) break;
	} while (next_permutation(vec.begin(), vec.end()));

	for (int i = 0; i < 7; i++) {
		cout << vec[i] << "\n";
	}

	return 0;
}*/