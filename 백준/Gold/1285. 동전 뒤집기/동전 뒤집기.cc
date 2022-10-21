#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <map>
#include <string>

using namespace std;

int const INF = 2147000000;
int n, a[44], res = INF;
string s;

// 비트마스킹
// 행을 뒤집으면서 비트마스킹을 활용해서 켜져있는 Bit 수를 세면서 각 행의 최소 값을 찾은 후
// 열은 뒤집는 것와 안뒤집는 것의 최솟값만 체크해서 min(cnt, n-cnt) 합을 구해줌
void go(int here)
{
	//cout << "here: " << here << "\n";

	if (here == n + 1)
	{
		int sum = 0;
		for (int i = 1; i < (1 << n); i *= 2)
		{
			int cnt = 0;
			for (int j = 1; j <= n; j++) if (a[j] & i) cnt++;
			sum += min(cnt, n - cnt);
			
		}
		res = min(sum, res);

		//for (int i = 1; i <= n; i++)
		//{
		//	cout << a[i] << " ";
		//}
		//cout << "\n";
		return;
	}

	//a[here] = ~a[here];
	go(here + 1);
	//cout << "a[here] : " << a[here] << "\n";
	a[here] = ~a[here];
	go(here + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		int value = 1;
		for (int j = 0; j < s.size(); j++)
		{
			if (s[j] == 'T') a[i] |= value;
			value *= 2;
		}
	}

	go(1);
	cout << res << '\n';

	return 0;
}