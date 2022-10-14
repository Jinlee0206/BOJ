#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

const int max_n = 1505;
using namespace std;

int n, m;
char m_map[max_n][max_n];
bool visited[max_n][max_n], swan_visited[max_n][max_n];
bool _find;

queue<pair<int, int>> swan_q, swan_nq, water_q, water_nq;
pair<int, int> swan_pos;

const int dy[4] = { -1, 0 ,1 ,0 };
const int dx[4] = { 0, -1, 0, 1 };

void waterBfs()
{
	while (water_q.size())
	{
		int y = water_q.front().first;
		int x = water_q.front().second;
		water_q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) continue;

			if (m_map[ny][nx] == 'X')
			{
				visited[ny][nx] = true;
				m_map[ny][nx] = '.';
				water_nq.push({ ny,nx });
			}
		}
	}
	return;
}

void swanBfs()
{
	while (swan_q.size())
	{
		pair <int, int> tmp = swan_q.front();
		swan_q.pop();

		for (int i = 0; i < 4 ; i++)
		{
			int ny = tmp.first + dy[i];
			int nx = tmp.second + dx[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m || swan_visited[ny][nx]) continue;
			swan_visited[ny][nx] = true;

			if (m_map[ny][nx] == '.')
			{
				swan_q.push({ ny,nx });
			}
			else if (m_map[ny][nx] == 'X')
			{
				swan_nq.push({ ny,nx });
			}
			else if (m_map[ny][nx] == 'L')
			{
				_find = true;
				break;
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	_find = false;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> m_map[i][j];
			if (m_map[i][j] != 'X')
			{
				water_q.push({ i,j });
				visited[i][j] = true;
			}
			if (m_map[i][j] == 'L')
			{
				swan_pos.first = i;
				swan_pos.second = j;
			}
		}
	}

	//for (int i = 0; i < n; i++)
	//{
	//	for (int j = 0; j < m; j++)
	//	{
	//		cout << m_map[i][j] << " ";
	//	}
	//	cout << "\n";
	//}


	int day = 0;
	swan_q.push({ swan_pos.first, swan_pos.second });
	swan_visited[swan_pos.first][swan_pos.second] = true;
	
	while (_find == false)
	{
		swanBfs();

		if (_find == false)
		{
			waterBfs();
			water_q = water_nq;
			swan_q = swan_nq;

			while (!water_nq.empty()) water_nq.pop();
			while (!swan_nq.empty()) swan_nq.pop();
			day++;
		}
	}

	cout << day << "\n";
	
	return 0;
}