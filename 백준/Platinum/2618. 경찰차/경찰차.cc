// BOJ - 2618 : 경찰차
#include <bits/stdc++.h>
using namespace std;

int n, w, py[1004], px[1004], dp[1004][1004], y, x;

int d(int a, int b)
{
	return abs(py[a] - py[b]) + abs(px[a] - px[b]);
}

int getSum(int a, int b)
{
	if (a == w + 1 || b == w + 1) return 0; // 모든 사건 해결
	if (dp[a][b]) return dp[a][b];
	int next = max(a, b) + 1; // 다음 사건을 가리키는 변수
	return dp[a][b] = min(getSum(next, b) + d(a, next), getSum(a, next) + d(b, next)); // 경찰차 1과 2 둘 중 최단거리로 움직이는 경우의 수를 선택
}

// Trace
void solve()
{
	int a = 0, b = 1;
	for (int i = 2; i < w + 2; i++)
	{
		if (dp[i][b] + d(a, i) < dp[a][i] + d(b, i))
		{
			cout << "1\n";
			a = i;
		}
		else
		{
			cout << "2\n";
			b = i;
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> w;
	py[0] = 1, py[1] = n;
	px[0] = 1, px[1] = n;
	for (int i = 2; i < w + 2; i++)
	{
		cin >> y >> x;
		py[i] = y, px[i] = x;
	}
	cout << getSum(0, 1) << '\n';
	solve();

	return 0;
}