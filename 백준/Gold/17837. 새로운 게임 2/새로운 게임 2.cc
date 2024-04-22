// BOJ - 17837 : 새로운 게임 2
#include<bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

const int dy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, -1, 0 ,0 };

int n, k, a[15][15];
struct Point {
    int y, x, dir;
};
vector<int> v[15][15];
vector<Point> status;

void move(int y, int x, int dir, int i)
{
    int ny = y + dy[dir];
    int nx = x + dx[dir];

    // 파란색 or 체스판을 벗어나는 경우
    if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 2)
    {
        status[i].dir ^= 1; // 방향 전환
        ny = y + dy[status[i].dir];
        nx = x + dx[status[i].dir];
        if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx] == 2) return;
    }
    // 한칸 이동 로직
    vector<int>& here_v = v[y][x];   // 현 위치
    vector<int>& next_v = v[ny][nx]; // 다음 위치
    auto pos = find(here_v.begin(), here_v.end(), i);
    // 뒤집어서 보내기
    if (a[ny][nx] == 1) reverse(pos, here_v.end());
    for (auto it = pos; it != here_v.end(); it++)
    {
        next_v.push_back(*it);
        status[*it].y = ny;
        status[*it].x = nx;
    }
    here_v.erase(pos, here_v.end());
    return;
}

bool isOver()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i][j].size() >= 4)
            {
                return 1;
            }
        }
    }
    return 0;
}

bool simul()
{
    for (int i = 0; i < status.size(); i++)
    {
        int y = status[i].y;
        int x = status[i].x;
        int dir = status[i].dir;
        move(y, x, dir, i);
        if (isOver()) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        int y, x, dir;
        cin >> y >> x >> dir;
        y--; x--; dir--;
        v[y][x].push_back(i);
        status.push_back({ y,x,dir }); // 말의 상태값을 저장
    }

    int cnt = 0;
    bool flag = 0;
    while (cnt <= 1000)
    {
        cnt++;
        if (simul())
        {
            flag = 1;
            break;
        }
    }

    if (flag) cout << cnt << '\n';
    else cout << -1 << '\n';

    return 0;
}