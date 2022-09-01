#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long A[1000001];
long long n, m;

// 매개변수 결정 알고리즘
// 답이 되는지 안 되는지 확인
long long Count(long long size)
{
	long long cnt = 0;

	for (int i = 1; i <= n; i++)
	{
		if (A[i] - size <= 0) continue;

		cnt += A[i] - size;
	}

	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	long long lt = 1, rt = 0, mid, res = 0, maxi = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
		maxi= max(maxi, A[i]);
	}

	rt = maxi;

	// 이분검색 (Binary Search)
	while (lt <= rt)
	{
		mid = (lt + rt) / 2;

		if (Count(mid) >= m)
		{
			res = max(res,mid);
			lt = mid + 1;
		}
		else rt = mid - 1;
	}
	
	cout << res << "\n";

	return 0;
}