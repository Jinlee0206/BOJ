#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int MAX = 200002;

int n, k;

int visited[MAX+4];
long long cnt[MAX+4];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	if (n == k)
	{
		puts("0"); puts("1");
		return 0;
	}

	queue<int> q;

	q.push(n);
	visited[n] = 1;
	cnt[n] = 1;

	while (q.size())
	{
		int tmp = q.front();
		q.pop();

		for (int next : {tmp - 1, tmp + 1, tmp * 2})
		{
			if (next < 0 || next > MAX) continue;

			if (!visited[next])
			{
				q.push(next);
				visited[next] = visited[tmp] + 1;
				cnt[next] += cnt[tmp];
			}
			else if (visited[next] == visited[tmp] + 1)
			{
				cnt[next] += cnt[tmp];
			}
		}
	}

	cout << visited[k] - 1 << "\n";
	cout << cnt[k] << "\n";

	return 0;
}