// BOJ - 17143 : 낚시왕
#include <bits/stdc++.h>
#define max_n 104
using namespace std;

const int INF = 2147000000;
const int dy[] = { -1, 1,0,0 };
const int dx[] = { 0, 0, 1,-1 };

int R, C, M, shark[max_n][max_n], tmp[max_n][max_n], res;

struct Shark {
	int y, x, s, dir, z, death;
}a[max_n*max_n];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> M;

	for (int i = 1; i <= M; i++)
	{
		cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;
		a[i].y--; a[i].x--; a[i].dir--;
		
		// 모듈러 연산을 통해 이동 후 결과 위치 바로 계산
		if (a[i].dir <= 1) a[i].s %= (2 * (R - 1));
		else a[i].s %= (2 * (C - 1));

		// 상어 위치 인덱스 저장
		shark[a[i].y][a[i].x] = i;
	}

	// 사람 Move
	for (int t = 0; t < C; t++)
	{
		for (int y = 0; y < R; y++)
		{
			if (shark[y][t])
			{
				a[shark[y][t]].death = 1;
				res += a[shark[y][t]].z;
				shark[y][t] = 0;
				break;
			}
		}
		memset(tmp, 0, sizeof(tmp));
		for (int i = 1; i <= M; i++)
		{
			if (a[i].death) continue; // 죽은상어 이동 제외

			// 중간변수
			int y = a[i].y;
			int x = a[i].x;
			int s = a[i].s;
			int d = a[i].dir;
			int ny, nx;

			while (1)
			{
				ny = y + s * dy[d];
				nx = x + s * dx[d];
				if (ny >= 0 && nx >= 0 && ny < R && nx < C) break;

				// 왼쪽 벽 오른쪽 벽에 부딪혔을 때, 방향전환하면서 남은 거리 s만큼 더 진행하게 끔 하는 로직
				if (d <= 1)
				{
					if (ny < 0)
					{
						s -= y;
						y = 0;
					}
					else
					{
						s -= R - 1 - y;
						y = R - 1;
					}
				}
				else
				{
					if (nx < 0)
					{
						s -= x;
						x = 0;
					}
					else
					{
						s -= C - 1 - x;
						x = C - 1;
					}
				}
				d ^= 1;
			}

			// 상어끼리 죽이는 경우
			if (tmp[ny][nx])
			{
				if (a[tmp[ny][nx]].z < a[i].z)
				{
					a[tmp[ny][nx]].death = 1;
					tmp[ny][nx] = i;
				}
				else {
					a[i].death = 1;
				}
			}
			else
			{
				tmp[ny][nx] = i;
			}

			a[i].y = ny;
			a[i].x = nx;
			a[i].dir = d;
		}
		memcpy(shark, tmp, sizeof(tmp));
	}
	cout << res << '\n';

	return 0;
}