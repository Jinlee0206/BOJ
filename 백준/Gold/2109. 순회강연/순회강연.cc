#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

int n, d, p, max = -2147000000, res = 0;

// 1. day 내림차순 정렬 방법

/*
struct Data
{
	int money;
	int when;

	Data(int a, int b)
	{
		money = a;
		when = b;
	}

	bool operator<(const Data& b) const
	{
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

		if (d > max)
		{
			max = d;
		}
	}

	sort(v.begin(), v.end());

	int j = 0;
	for (int i = max; i >= 1; i--)
	{
		for (; j < n; j++)
		{
			//cout << "I_position : " << i << ' ';
			//cout << "J_position : " << j << '\n';
			
			// break 구문은 반복자를 ++시키지 않는다
			if (v[j].when < i) break;
			pq.push(v[j].money);
		}

		if (!pq.empty())
		{
			res += pq.top();
			pq.pop();
		}
	}

	cout << res << '\n';
		
	return 0;
}
*/

// 2. Day 오름차순 정렬
int main()
{
	priority_queue<int, vector<int>, greater<int>> pQ;
	vector<pair<int, int>> v;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p >> d;
		v.push_back({ d,p });
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < n; i++)
	{
		pQ.push(v[i].second);
		if (pQ.size() > v[i].first) pQ.pop();
	}

	while (pQ.size())
	{
		res += pQ.top();
		pQ.pop();
	}

	cout << res << '\n';

	return 0;
}