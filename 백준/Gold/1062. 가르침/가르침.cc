#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, words[51];
string str;

int count(int mask) {
	int cnt = 0;
	for (int word : words)
	{
		if (word && (word & mask) == word) cnt++;
	}
	return cnt;
}

int go(int idx, int k, int mask)
{
	if (k < 0) return 0;
	if (idx == 26) return count(mask);
	int res = go(idx + 1, k - 1, mask | (1 << idx));
	if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' && idx != 'i' - 'a' && idx != 'c' - 'a')
	{
		res = max(res, go(idx + 1, k, mask));
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		for (char c : str)
		{	
			words[i] |= (1 << (c - 'a'));
		}
	}

	cout << go(0, m, 0) << "\n";

	return 0;
}