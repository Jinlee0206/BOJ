#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k, sy, sx, ey, ex;

const int dy[4] = { -1, 0, 1, 0 };
const int dx[4] = { 0, -1, 0 ,1 };

int visited[10][10];
char m_map[10][10];

int DFS(int y, int x)
{
	// 기저 사례 (탈출 조건) 6개짜리 길이 가짓수 ++
	if (y == ey && x == ex)
	{
		if (k == visited[y][x]) return 1;
		else return 0;
	}

	int res = 0;
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx] || m_map[ny][nx] == 'T') continue;
		// 최단 거리 찾기
		visited[ny][nx] = visited[y][x] + 1;
		
		// 가짓수 총합 더하기
		res += DFS(ny, nx);

		// visited 초기화
		visited[ny][nx] = 0;
	}
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> r >> c >> k;

	string str;
	for (int i = 0; i < r; i++)
	{
		cin >> str;
		for (int j = 0; j < c; j++)
		{
			m_map[i][j] = str[j];
		}
	}

	sy = r - 1, sx = 0;
	ey = 0, ex = c - 1;

	visited[sy][sx] = 1;
	cout << DFS(sy, sx) << "\n";

	return 0;
}