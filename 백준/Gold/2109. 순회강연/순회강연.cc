// BOJ-2109 : 순회강연
#include<bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int n, p, d, mx = -INF, res;

struct Data {
	int money;
	int when;

	Data(int a, int b)
	{
		money = a;
		when = b;
	}

	bool operator< (const Data& b) const {
		return when > b.when;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<Data> v;
	priority_queue<int> pq;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		v.push_back(Data(p,d));

		mx = max(mx, d);
	}

	sort(v.begin(), v.end());

	int j = 0;
	for (int i = mx; i >= 1; i--)
	{
		for (; j < n; j++)
		{
			if (v[j].when < i) break;
			pq.push(v[j].money);
		}

		if (pq.size())
		{
			res += pq.top();
			pq.pop();
		}
	}

	cout << res << '\n';
	return 0;
}
