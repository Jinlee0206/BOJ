#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k, sum = 0, m_max;
	cin >> n >> k;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		cin >> vec[i];
	}

	for (int i = 0; i < k; i++)
	{
		sum += vec[i];
	}

	m_max = sum;

	for (int i = k; i < n; i++)
	{
		sum += vec[i] - vec[i - k];
		m_max = max(sum, m_max);
	}

	cout << m_max << "\n";

	return 0;
}