#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k, a[105], visited[105], cnt;
const int INF = 2147000000;
vector<int> v;

// Optimal Algorithm
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++)	cin >> a[i];

	for (int i = 0; i < k; i++)
	{
		// 해당 제품이 멀티탭에 없는 경우
		if (!visited[a[i]])
		{
			// 멀티탭이 꽉찬 경우
			if (v.size() == n)
			{
				int last_idx = 0, pos = 0;

				// 멀티탭을 점검
				for (int _a : v)
				{
					int here_pick = INF;
					
					// 멀티탭의 _a 제품이 나중에 사용되는 지 확인
					for (int j = i + 1; j < k; j++)
					{
						// 나중에 또 사용되는 제품이라면 j번째에 사용되는 것을 체크
						if (_a == a[j])
						{
							here_pick = j;
							break;
						}
					}

					// last_idx를 가장 늦게 사용 되는 제품으로 갱신
					if (last_idx < here_pick)
					{
						last_idx = here_pick;
						pos = _a;
					}
				}

				visited[pos] = 0;
				cnt++;
				v.erase(find(v.begin(), v.end(), pos));
			}

			// 멀티탭에 제품 꽂기
			v.push_back(a[i]);
			visited[a[i]] = 1;
		}
	}

	cout << cnt << '\n';

	return 0;
}