#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	vector<int> v;

	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;
		
		sum += a;

		v.push_back(a);
	}

	sort(v.begin(), v.end());
	sum /= 5;

	cout << sum << '\n' << v[2] << '\n';
	

	return 0;
}