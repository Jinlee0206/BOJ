#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
// 찾고자 하는 값 이상이 처음 나오는 위치
int lowerBound(vector<int> &vec, int target, int size)
{
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start)
	{
		mid = (start + end) / 2;
		if (vec[mid] >= target) end = mid;
		else start = mid + 1;
	}
	return end;
}

// 찾고자 하는 값보다 큰 값이 처음 나오는 위치
int upperBound(vector<int>& vec, int target, int size)
{
	int mid, start, end;
	start = 0, end = size - 1;

	while (end > start)
	{
		mid = (start + end) / 2;
		if (vec[mid] > target) end = mid;
		else start = mid + 1;
	}
}
*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n;

	vector<int> vec;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	sort(vec.begin(), vec.end());

	cin >> m;

	for (auto i = 0; i < m; i++)
	{
		int x;
		cin >> x;

		cout << upper_bound(vec.begin(), vec.end(), x) - lower_bound(vec.begin(), vec.end(), x) << " ";
	}

	return 0;
}