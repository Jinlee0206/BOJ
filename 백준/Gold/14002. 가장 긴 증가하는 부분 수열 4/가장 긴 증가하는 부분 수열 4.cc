// BOJ - 14002 : 가장 긴 증가하는 부분 수열 4
#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int n, a[1004], cnt[1004], res = 1, idx;
int prev_list[1004];
vector<int> v;

void go(int idx)
{
	if (idx == -1) return;
	v.push_back(a[idx]);
	go(prev_list[idx]);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++) cin >> a[i];
	fill(prev_list, prev_list + 1004, -1);
	fill(cnt, cnt + 1004, 1);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[j] < a[i] && cnt[i] < cnt[j] + 1)
			{
				cnt[i] = cnt[j] + 1;
				prev_list[i] = j;
				if (res < cnt[i])
				{
					res = cnt[i];
					idx = i;
				}
			}
		}
	}

	cout << res << '\n';
	go(idx);
	for (int i = v.size() - 1; i >= 0; i--) cout << v[i] << " ";

	return 0;
}