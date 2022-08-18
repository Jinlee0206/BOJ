#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int k;
	cin >> k;

	vector<pair<int,int>> vec(6);

	for (int i = 0; i < 6; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}

	int area = -1;
	int ans = -1;

	// 6각형이 연속으로 생성이 된다는 것을 이용해서 for문을 돌림.
	for (int i = 0; i < 6; i++)
	{
		int artmp = vec[i].second * vec[(i+1) % 6].second;
		if (area == -1 || artmp > area)
		{
			area = artmp;
			ans = area - vec[(i + 3) % 6].second * vec[(i + 4) % 6].second;
		}
	}

	cout << k * ans << "\n";

	return 0;
}