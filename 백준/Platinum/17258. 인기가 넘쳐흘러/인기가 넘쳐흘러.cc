// BOJ - 17258 : 인기가 넘쳐흘러
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, m, k, t, from, to, cnt[304], dp[304][304];
vector<pair<int, int>> v; // 파티 구간을 저장하기 위한 벡터 {시간, 현재인원}

int go(int here, int num, int prev)
{
	if (here == v.size()) return 0;
	if (dp[here][num]) return dp[here][num];

	int cost = max(0, t - v[here].second); // {2,0} 일때 cost는 2명 필요
	int real_cost = (prev >= cost) ? 0 : cost - prev; // 실제 코스트 {2,0} -> {2,1} 이전에 소모된 친구수를 빼야함

	int& res = dp[here][num];
	if (num - real_cost >= 0) // 친구 투입 가능
	{
		return res = max(go(here + 1, num - real_cost, cost) + v[here].first, go(here + 1, num, 0));
	}
	else return res = go(here + 1, num, 0);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> k >> t;
	for (int i = 0; i < m; i++)
	{
		cin >> from >> to;
		for (int j = from; j < to; j++)
		{
			cnt[j] = min(t, ++cnt[j]); // 최대 T값만큼만 취급
		}
	}
	int tmp = cnt[1];
	int _cnt = 1;
	for (int i = 2; i <= n; i++)
	{
		if (tmp != cnt[i]) // 파티 초대한 사람수 변동 생길 때
		{
			v.push_back({ _cnt, tmp });
			_cnt = 0; // 시간 0으로 초기화
			tmp = cnt[i];
		}
		_cnt++;
	}
	v.push_back({ _cnt, tmp }); // 마지막 구간
	cout << go(0, k, 0) << '\n';
	return 0;
}