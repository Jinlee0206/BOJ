// BOJ - 14391: 종이 조각

#include<bits/stdc++.h>
using namespace std;

int n, m, res;
int a[4][4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			a[i][j] = str[j] - '0';
		}
	}

	for (int s = 0; s < (1 << (n * m)); s++) // 맵을 0과 1로 나누는 모든 경우의 수 탐색
	{
		// 전체 합 초기화
		int sum = 0;
		// 세로 기준, 가로 방향 탐색
		for (int i = 0; i < n; i++)
		{
			int cur = 0;
			for (int j = 0; j < m; j++)
			{
				int k = i * m + j; // 실제 탐색 순서
				if ((s & (1 << k)) == 0) // 0 : 가로 합
				{
					cur = cur * 10 + a[i][j];
				}
				else
				{
					sum += cur;
					cur = 0;
				}
			}
			sum += cur; // 남은 cur 값 sum에 더하기
		}
		// 가로 기준, 세로 방향 탐색
		for (int j = 0; j < m; j++)
		{
			int cur = 0;
			for (int i = 0; i < n; i++)
			{
				int k = i * m + j;
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
		res = max(res, sum); // 완탐 후 최대치 구하기
	}
	
	cout << res << '\n';

	return 0;
}