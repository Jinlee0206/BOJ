#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Euclidean algorithm
int GCD(int a, int b)
{
	int c = a % b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

int LCM (int a, int b)
{
	return (a*b) / GCD(a,b);
}

int main()
{
	int n, m;
	cin >> n >> m;

	cout << GCD(n, m) << "\n" << LCM(n,m) <<"\n";

	return 0;
}