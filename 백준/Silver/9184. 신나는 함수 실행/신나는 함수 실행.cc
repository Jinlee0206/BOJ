#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[51][51][51];

int w(int x, int y, int z)
{
	if (x <= 0 || y <= 0 || z <= 0) return 1;
	else if (x > 20 || y > 20 || z > 20) return w(20,20,20);
	else if (x < y && y < z)
	{
		if (dp[x][y][z] != 0) return dp[x][y][z];
		return dp[x][y][z] = w(x, y, z - 1) + w(x, y - 1, z - 1) - w(x, y - 1, z);
	}
	else
	{
		if (dp[x][y][z] != 0) return dp[x][y][z];
		return dp[x][y][z] = w(x - 1, y, z) + w(x - 1, y - 1, z) + w(x - 1, y, z - 1) - w(x - 1, y - 1, z - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		int a, b, c;
		cin >> a >> b >> c;

		if (a == -1 && b == -1 && c == -1) break;

		int res = w(a, b, c);

		cout << "w(" << a << ", " << b << ", " << c << ") = " << res << "\n";
		

	}


	return 0;
}