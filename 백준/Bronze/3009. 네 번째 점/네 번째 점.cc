#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<pair<int, int>> vec(4);

	for (int i = 0; i < 3; i++)
	{
		int a, b;
		cin >> a >> b;
		vec[i] = make_pair(a,b);
	}


	if (vec[0].first == vec[1].first) vec[3].first = vec[2].first;
	else if (vec[1].first == vec[2].first) vec[3].first = vec[0].first;
	else vec[3].first = vec[1].first;

	if (vec[0].second == vec[1].second) vec[3].second = vec[2].second;
	else if (vec[1].second == vec[2].second) vec[3].second = vec[0].second;
	else vec[3].second = vec[1].second;

	cout << vec[3].first << " " << vec[3].second << "\n";

	return 0;
}