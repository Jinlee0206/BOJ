#include<bits/stdc++.h>

using namespace std;

int n, k, l, y, x, X, ans, idx, dir = 1;
char C;
int bd[104][104], visited[104][104];

vector<pair<int, int>> v;
deque<pair<int, int>> dq;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

// deque 활용 스네이크 게임 구현
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < k; i++)
	{
		cin >> y >> x;
		bd[--y][--x] = 1;
	}

	cin >> l;

	for (int i = 0; i < l; i++)
	{
		cin >> X >> C;
		if (C == 'D') v.push_back({ X, 1 });
		else v.push_back({ X, 3 });
	}

	dq.push_back({ 0,0 });
	while (dq.size())
	{
		ans++;
		tie(y, x) = dq.front();

		int ny = y + dy[dir];
		int nx = x + dx[dir];

		// 보드 판 끝에 가거나 자기 자신의 몸에 부딪힌다
		if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) break;

		// 해당 보드판에 사과가 없다
		if (!bd[ny][nx])
		{
			// 꼬리쪽 방문 풀어주기
			visited[dq.back().first][dq.back().second] = 0;
			dq.pop_back();
		} // 사과 먹은 곳 사과 제거
		else bd[ny][nx] = 0;

		// 방문할 곳 방문처리
		visited[ny][nx] = 1;
		dq.push_front({ ny,nx });	

		// 방향 전환할 시간 도달
		if (ans == v[idx].first)
		{
			// 방향 만들기 모듈러 연산 암기!
			dir = (dir + v[idx].second) % 4;
			idx++;
		}

	}

	cout << ans << '\n';

	return 0;
}