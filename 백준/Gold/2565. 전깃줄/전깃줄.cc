#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Line
{
	int left;
	int right;

	bool operator<(const Line& b) const
	{
		if (b.left != 0) return this->left < b.left;
	}
};

Line line[101];
int dp[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		cin >> line[i].left >> line[i].right;
	}

	int correct_line = 0;
	sort(line + 1, line + n + 1);

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (line[i].right > line[j].right) dp[i] = max(dp[i], dp[j] + 1);
		}
		correct_line = max(correct_line, dp[i]);

	}

	cout << n - correct_line << "\n";

	return 0;
}