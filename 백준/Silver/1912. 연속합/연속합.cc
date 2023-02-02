#include<bits/stdc++.h>

using namespace std;

const int INF = 2147000000;
int n, a, sum, m_max = -INF;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		sum += a;
		m_max = max(m_max, sum);

		if (sum < 0)
		{
			sum = 0;
			continue;
		}
	}

	cout << m_max;
	
	return 0;
}