#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> pn;
bool ch[4000001];

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

	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	makePN(n);
	
	//for (int i = 0; i < pn.size(); i++)
	//{
	//	cout << pn[i] << ' ';
	//}

	int p1, p2, sum = 0, cnt = 0;
	p1 = p2 = 0;

	while (1)
	{
		if (sum >= n) sum -= pn[p1++];
		else if (p2 == pn.size()) break;
		else sum += pn[p2++];

		if (sum == n) cnt++;
	}

	cout << cnt << '\n';

	return 0;
}