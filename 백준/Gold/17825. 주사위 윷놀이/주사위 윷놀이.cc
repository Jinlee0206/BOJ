// BOJ - 17825 : 주사위 윷놀이
#include <bits/stdc++.h>
using namespace std;

int n = 10, a[14], hor[4], v[104];

vector<int> adj[54];

void add(int here, int there)
{
	adj[here].push_back(there);
}

void setMap()
{
	for (int i = 0; i <= 19; i++) add(i, i + 1);
	add(5, 21); add(21, 22); add(22, 23); add(23, 24);
	add(10, 27); add(27, 28); add(28, 24);
	add(15, 29); add(29, 30); add(30, 31); add(31, 24);
	add(24, 25); add(25, 26); add(26, 20); add(20, 100);

	for (int i = 1; i <= 20; i++) v[i] = i * 2;
	v[21] = 13; v[22] = 16; v[23] = 19; v[24] = 25;
	v[25] = 30; v[26] = 35;
	v[27] = 22; v[28] = 24; v[29] = 28; v[30] = 27; v[31] = 26;
}

bool isHor(int hor_idx, int idx)
{
	if (hor_idx == 100) return false;
	for (int i = 0; i < 4; i++)
	{
		if (i == idx) continue;
		if (hor[i] == hor_idx) return true;
	}
	return false;
}

int move(int here, int cnt)
{
	if (here == 100) return 100;
	if (adj[here].size() >= 2)
	{
		here = adj[here][1];
		cnt--;
	}

	if (cnt)
	{
		queue<int> q;
		q.push(here);
		int there;

		while (q.size())
		{
			int x = q.front();
			q.pop();
			there = adj[x][0];
			q.push(there);
			if (there == 100) break;
			cnt--;
			if (cnt == 0) break;
		}
		return there;
	}
	else return here;

}

int go(int here)
{
	if (here == n) return 0;
	int res = 0;

	for (int i = 0; i < 4; i++)
	{
		int tmp_idx = hor[i]; // 각각의 말 임시 위치 저장
		int hor_idx = move(tmp_idx, a[here]);
		if (isHor(hor_idx, i)) continue; // 움직일 위치에 말있는지
		hor[i] = hor_idx;
		res = max(res, go(here + 1) + v[hor_idx]);
		hor[i] = tmp_idx;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	setMap();

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	cout << go(0) << '\n';

	return 0;
}