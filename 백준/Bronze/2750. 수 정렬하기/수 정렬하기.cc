#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> vec(n);

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec[i] = a;
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		cout << vec[i] << endl;
	}

	return 0;

}
