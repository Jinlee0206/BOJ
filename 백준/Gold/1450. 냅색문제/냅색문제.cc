#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

ll w[31], ans, n, c;
vector<ll> group1, group2;

void DFS(int start, int end, vector<ll>& vec, ll sum)
{
	if (start > end)
	{
		vec.push_back(sum);
		return;
	}
	else
	{
		DFS(start + 1, end, vec, sum); // start 번째의 물건을 선택하지 않는 경우
		DFS(start + 1, end, vec, sum + w[start]);  // start 번째의 물건을 선택하는 경우
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> c;

	for (int i = 0; i < n; i++)
	{
		cin >> w[i];
	}

	DFS(0, n / 2, group1, 0);
	DFS(n / 2 + 1, n - 1, group2, 0);

	sort(group2.begin(), group2.end());

	for (int i = 0; i < group1.size(); i++)
	{
		// upper_bound() : c - group[i] 값을 초과하는 숫자가 group2 배열의 몇 번째에서 처음 등장하는지 알 수 있음. iterator 반환
		// lower_bound() : c - group[i] 값과 같거나 큰 숫자가 group2 배열의 몇 번째에서 처음 등장하는지 알 수 있음. iterator 반환
		ll x = c - group1[i];
		ans += upper_bound(group2.begin(), group2.end(), x) - group2.begin();
	}

	cout << ans << "\n";

	return 0;
}