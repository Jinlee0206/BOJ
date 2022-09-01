#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, c;

// 매개변수 결정 알고리즘
// 답이 되는지 안 되는지 확인
int CalDistance(int length, vector<int> &vec)
{
	int cnt = 1, pos = vec[1];

	for (int i = 2; i <= n; i++)
	{
		if (vec[i] - pos >= length)
		{
			cnt++;
			pos = vec[i];
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;

	vector<int> A(n + 1);

	int lt = 1, rt = 0, mid, res = 0;

	for (int i = 1; i <= n; i++)
	{
		cin >> A[i];
	}

	sort(A.begin()+1, A.end());

	rt = A.back();

	while (lt <= rt)
	{
		mid = (lt + rt) / 2;

		if (CalDistance(mid, A) >= c)
		{
			res = max(res,mid);
			lt = mid + 1;
		}
		else rt = mid - 1;
	}

	cout << res << "\n";

	return 0;
}