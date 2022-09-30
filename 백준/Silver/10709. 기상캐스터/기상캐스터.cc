#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int> > res(n+1, vector<int> (m+1));
	vector<vector<char> > vec(n+1, vector<char> (m+1));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin >> ch;
			vec[i][j] = ch;
			if (ch == 'c') res[i][j] = 0;
			else res[i][j] = -1;
		}
	}

	// DP?
	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (res[i][j] == 0) continue;
			else if (res[i][j - 1] >= 0)
			{
				res[i][j] = res[i][j - 1] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
	

	return 0;

}