#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, m, a[5][5], res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			a[i][j] = (int)(str[j]- '0');
		}
	}

	for (int s = 0; s < (1 << (n * m)); s++)
	{
		// 전체 합 초기화
		int sum = 0;

		// 세로 기준, 가로 방향 탐색 
		for (int i = 0; i < n; i++)
		{
			// 줄마다 cur 변수 초기화 
			int cur = 0;
			for (int j = 0; j < m; j++)
			{
				int k = i * m + j;
				// 0 : 가로 합
				if ((s & (1 << k)) == 0) {
					cur = cur * 10 + a[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			// 남은 cur 값 sum에 더하기
			sum += cur;
		}

		// 가로 기준, 세로 방향 탐색
		for (int j = 0; j < m; j++)
		{
			int cur = 0;
			for (int i = 0; i < n; i++)
			{
				int k = i * m + j;
				// 1 : 세로 합
				if ((s & (1 << k)) != 0)
				{
					cur = cur * 10 + a[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur;
		}

		// 완탐 후 최대치 구하기
		res = max(res, sum);
	}
	
	cout << res << "\n";

	return 0;
}