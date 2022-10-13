#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;

const int m_max = 500000;

int n, k, turn = 1;
int visited[2][m_max + 4];
bool ok = false;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	if (n == k) { cout << 0 << "\n"; return 0; }

	queue<int> q;
	q.push(n);
	visited[0][n] = 1;

	while (q.size())
	{
		k += turn;

		if (k > m_max) break;
		if (visited[turn % 2][k])
		{
			ok = true;
			break;
		}

		int qSize = q.size();
		for (int i = 0; i < qSize; i++)
		{
			int x = q.front();
			q.pop();

			for (int nx : {x - 1, x + 1, x * 2})
			{
				if (nx < 0 || nx > m_max || visited[turn % 2][nx]) continue;
				visited[turn % 2][nx] = visited[(turn + 1) % 2][x] + 1;
				if (nx == k)
				{
					ok = true;
					break;
				}
				q.push(nx);
			}
			if (ok) break;
		}
		if (ok)break;
		turn++;
	}

	if (ok)cout << turn << "\n";
	else cout << -1 << "\n";
	
	return 0;
}