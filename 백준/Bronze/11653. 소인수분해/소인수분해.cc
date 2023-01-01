#include<bits/stdc++.h>

using namespace std;

int n;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	int idx = 2;
	while (n > 1)
	{
		if (n % idx == 0)
		{
			n /= idx;
			v.push_back(idx);
		}
		else idx++;
	}

	for (auto i : v) cout << i << '\n';

	return 0;
}