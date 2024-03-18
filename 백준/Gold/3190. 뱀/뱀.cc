// BOJ-3190 : 뱀
#include <bits/stdc++.h>
using namespace std;

const int dy[] = { 0, 1, 0 ,-1 };
const int dx[] = { 1, 0, -1 ,0 };

int n, k, l, x, idx, a[104][104], visited[104][104], dir = 0, res;
char C;
vector<pair<int, int>> v;
deque<pair<int, int>> dq;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		int r, c;
		cin >> r >> c;
		a[--r][--c] = 1;
	}

	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> C;
		if (C == 'D') v.push_back({ x, 1 });
		else v.push_back({ x, 3 });
	}

	dq.push_back({ 0,0 });
	while (dq.size())
	{
		res++;
		pair<int,int> tmp = dq.front();
		int ny = tmp.first + dy[dir];
		int nx = tmp.second + dx[dir];

		// 보드판 끝에 가거나 자기 자신의 몸에 부딪힘
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) break;

		// 사과를 안먹었으면 길이 일정
		// deque의 back 부분 방문처리 해제
		if (!a[ny][nx])
		{
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		}
		else a[ny][nx] = 0;

		// 방문할 곳 방문 처리
		visited[ny][nx] = 1;
		dq.push_front({ ny,nx });

		// 방향전환할 시간 도달
		if (res == v[idx].first)
		{
			dir = (dir + v[idx].second) % 4; // 방향 만들기 모듈러 연산
			idx++;
		}
	}

	cout << res << '\n';
	
	return 0;
}