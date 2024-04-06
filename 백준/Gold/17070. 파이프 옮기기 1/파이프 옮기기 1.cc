// BOJ - 17070 : 파이프 옮기기 1
#include<bits/stdc++.h>
using namespace std;
const int INF = 214700000;

int n, a[24][24], dp[24][24][3];

// 파이프를 놓을 수 있는지 없는지 판단하는 불리언 함수
bool check(int y, int x, int dir)
{
    if (dir == 0 || dir == 2) // 가로 or 세로
    {
        if (!a[y][x]) return true;
    }
    else if (dir == 1) // 대각선
    {
        if (a[y][x] == 0 && a[y - 1][x] == 0 && a[y][x - 1] == 0) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    dp[1][2][0] = 1; // 초기 가로 (1,2) 지점에 두번째 파이프 놓임
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // 가로 방향 이동
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][0];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][0];

            // 세로 방향 이동
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][2];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][2];

            // 대각선 방향 이동
            if (check(i, j + 1, 0)) dp[i][j + 1][0] += dp[i][j][1];
            if (check(i + 1, j, 2)) dp[i + 1][j][2] += dp[i][j][1];
            if (check(i + 1, j + 1, 1)) dp[i + 1][j + 1][1] += dp[i][j][1];
        }
    }

    int res = dp[n][n][0];
    res += dp[n][n][1];
    res += dp[n][n][2];

    cout << res << '\n';

    return 0;
}
