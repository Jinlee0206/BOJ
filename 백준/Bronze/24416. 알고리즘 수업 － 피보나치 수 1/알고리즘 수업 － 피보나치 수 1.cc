#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DPS(int n)
{
	if (n == 1 || n == 2) return 1;
	else return DPS(n - 1) + DPS(n - 2);
}


int a[50];

int DP(int n)
{
	a[1] = 1;
	a[2] = 1;

	for (int i = 3; i <= n; i++)
	{
		a[i] = a[i - 1] + a[i - 2];
	}

	return a[n];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	if (n >= 3) {
		cout << DPS(n) << " " << n - 2 << "\n";
	}
	else cout << DPS(n) << " " << 0 << "\n";

	return 0;
}