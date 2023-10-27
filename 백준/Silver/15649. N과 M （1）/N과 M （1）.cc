// BOJ-15649 : N과 M
#include<bits/stdc++.h>
using namespace std;

const int N = 8;
int n, m, a[N], visited[N];
vector<int> v;

void printV()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
	cout << '\n';
	return;
}

void go(int cnt)
{
	if (cnt == m)
	{
		printV();
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i]) continue;
		visited[i] = 1;
		v.push_back(a[i]);
		go(cnt + 1);
		visited[i] = 0;
		v.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++) a[i] = i + 1;

	go(0);
	
	return 0;
}