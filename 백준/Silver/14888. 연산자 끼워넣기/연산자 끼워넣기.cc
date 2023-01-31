#include<bits/stdc++.h>

using namespace std;

int n, a[14], oper[4], m_min = 2147000000, m_max= -2147000000;

void dfs(int res, int lv)
{
	if (lv == n)
	{
		m_max = max(m_max, res);
		m_min = min(m_min, res);
	}

	for (int i = 0; i < 4; i++)
	{
		if (oper[i] > 0)
		{
			oper[i]--;
			if (i == 0) dfs(res + a[lv], lv + 1);
			else if (i == 1) dfs(res - a[lv], lv + 1);
			else if (i == 2) dfs(res * a[lv], lv + 1);
			else dfs(res / a[lv], lv + 1);
			oper[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < 4; i++) cin >> oper[i];

	dfs(a[0], 1);

	cout << m_max << '\n' << m_min << '\n';

	
	return 0;
}