#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned int A[10001];
unsigned int k, n;

// 매개변수 결정 알고리즘
// 답이 되는지 안 되는지 확인
unsigned Count(unsigned int size)
{
	unsigned int cnt = 0;

	for (int i = 1; i <= k; i++)
	{
		cnt += A[i] / size;
	}

	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> k >> n;

	unsigned int lt = 1, rt = 0, mid, res = 0, maxi = 0;

	for (int i = 1; i <= k; i++)
	{
		cin >> A[i];
		maxi= max(maxi, A[i]);
	}

	rt = maxi;

	// 이분검색 (Binary Search)
	while (lt <= rt)
	{
		mid = (lt + rt) / 2;

		if (Count(mid) >= n)
		{
			res = max(res,mid);
			lt = mid + 1;
		}
		else rt = mid - 1;
	}
	
	cout << res << "\n";

	return 0;
}