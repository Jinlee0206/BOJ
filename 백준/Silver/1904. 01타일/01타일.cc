#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[1000001];
int DFS(int n)
{
	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 2] + dp[i - 1]) % 15746;
	
	return dp[n];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cout << DFS(n)<< endl;


	return 0;
}