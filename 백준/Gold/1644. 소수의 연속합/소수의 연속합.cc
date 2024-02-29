// BOJ-1644 : 소수의 연속합
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> pn;
bool ch[4000001];

// 에라스토테네스의 체
void makePN(int a)
{
	for (int i = 2; i * i <= a; i++)
	{
		if (ch[i]) continue;
		for (int j = 2 * i; j <= a; j += i)
		{
			ch[j] = true;
		}
	}
	for (int i = 2; i <= a; i++) if (!ch[i]) pn.push_back(i);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	makePN(n);

	// 투포인터 알고리즘
	int p1, p2, sum = 0, cnt= 0;
	p1 = p2 = 0;
	while (true)
	{
		if (sum >= n) sum -= pn[p1++];
		else if (p2 == pn.size()) break;
		else sum += pn[p2++];

		if (n == sum) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}
