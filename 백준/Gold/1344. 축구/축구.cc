// BOJ - 1344 : 축구
#include <bits/stdc++.h>
using namespace std;
const int INF = 2147000000;
const int n = 18;
double a, b, dp[20][20][20];
bool isP[20];


double go(int idx, int x, int y)
{
	// 기저사례
	if (idx == n) return isP[x] || isP[y] ? 1.0 : 0.0;
	
	// 메모이제이션
	double& res = dp[idx][x][y];
	if (res > -0.5) return res;
	res = 0.0;

	// 로직
	// 경우의 수는 모두 더하기
	// 확률은 (경우의수 * 확률)을 모두 더하기
	res += go(idx + 1, x + 1, y) * a * (1 - b);   // x만 넣을 확률
	res += go(idx + 1, x, y + 1) * (1 - a) * b;   // y만 넣을 확률
	res += go(idx + 1, x + 1, y + 1) * a * b;	  // x, y 둘다 넣을 확률
	res += go(idx + 1, x, y) * (1 - a) * (1 - b); // x, y 둘다 못 넣을 확률
	return res;
}

void era()
{
	fill(isP, isP + 20, 1);
	isP[0] = 0; isP[1] = 0;
	for (int i = 2; i <= 20; i++)
	{
		for (int j = i + i; j <= 20; j += i)
		{
			isP[j] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	scanf("%lf %lf", &a, &b);
	a /= 100; b /= 100;
	era();
	memset(dp, -1, sizeof(dp)); // 초기화
	printf("%.6lf", go(0, 0, 0));
	return 0;
}