// DFS를 활용한 Composite Component

#include <bits/stdc++.h>
using namespace std;

const int dy[] = { -1, 0, 1, 0 };
const int dx[] = { 0, 1, 0, -1 };

int T, n, m, k, x, y;
int a[54][54], visited[54][54];

void go(int y, int x)
{
    visited[y][x] = 1; // 시작지점 방문처리 미리 (돌다리를 두들겨보기)

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= m || !a[ny][nx]) continue;
        if (visited[ny][nx]) continue;
        go(ny, nx);
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--)
    {
        fill(&a[0][0], &a[0][0] + 54 * 54, 0); // 한 테스트 케이스 끝나고 a 배열, visited 배열 초기화 해야함
        fill(&visited[0][0], &visited[0][0] + 54 * 54, 0); // 이차원 배열 초기화 fill 함수 사용법 암기

        int res = 0;
        cin >> m >> n >> k;

        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;
            a[y][x] = 1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 1 && !visited[i][j])
                {
                    go(i, j);
                    res++;
                }
            }
        }

        cout << res << '\n';
    }
    
    return 0;
}