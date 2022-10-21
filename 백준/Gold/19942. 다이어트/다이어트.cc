#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

int n, mp, mf, ms, mv;
map<int, vector<vector<int>>> res_v;
int p, f, s, v, sum, res = 2147000000;

struct component {
	int p;
	int f;
	int s;
	int v;
	int cost;

	component(int a, int b, int c, int d, int e)
	{
		p = a;
		f = b;
		s = c;
		v = d;
		cost = e;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> mp >> mf >> ms >> mv;

	vector<component> vec;
	for (int i = 0; i < n; i++)
	{
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		vec.push_back({ a,b,c,d,e });
	}

	for (int i = 0; i < (1 << n); i++)
	{
		vector<int> idx;
		p = f = s = v = sum = 0;

		for (int j = 0; j < n; j++)
		{
			if (i & (1 << j))
			{
				idx.push_back(j + 1);
				p += vec[j].p;
				f += vec[j].f;
				s += vec[j].s;
				v += vec[j].v;
				sum += vec[j].cost;
			}
		}

		if (p >= mp && f >= mf && s >= ms && v >= mv)
		{
			if (res >= sum)
			{
				res = sum;
				res_v[res].push_back(idx);
			}
		}
	}

	if (res == 2147000000) cout << -1 << "\n";
	else
	{
		sort(res_v[res].begin(), res_v[res].end());
		cout << res << "\n";
		for (int a : res_v[res][0])
		{
			cout << a << " ";
		}
	}

	return 0;
}