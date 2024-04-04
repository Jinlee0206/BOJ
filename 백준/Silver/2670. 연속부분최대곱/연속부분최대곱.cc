// BOJ - 2670 : 연속부분최대곱
#include <bits/stdc++.h>
using namespace std;

int n;
double a[10004], res;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	double b = a[0];
	res = b;

	for (int i = 1; i < n; i++)
	{
		if (a[i] > b * a[i]) b = a[i];
		else b *= a[i];
		res = max(b, res);
	}

	printf("%.3lf", res);

	return 0;
}