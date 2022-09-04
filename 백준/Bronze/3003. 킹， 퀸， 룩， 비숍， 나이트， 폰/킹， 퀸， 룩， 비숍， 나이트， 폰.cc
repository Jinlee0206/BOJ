#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> vec(6);

	vec[0] = 1;
	vec[1] = 1;
	vec[2] = 2;
	vec[3] = 2;
	vec[4] = 2;
	vec[5] = 8;

	for (int i = 0; i < 6; i++)
	{
		int a;
		cin >> a;

		vec[i] -= a;
		cout << vec[i] << " ";
	}

	return 0;
}