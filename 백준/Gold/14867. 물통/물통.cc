// BOJ - 14867 : 물통
#include<bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int a, b, c, d;
map<pair<int,int>, int> mp;
queue<pair<int, int>> q;

void enqueue(int x, int y, int d)
{
    if (mp[{x, y}]) return;
    mp[{x, y}] = d + 1;
    q.push({ x,y });
}

int bfs(int x, int y)
{
    // x와 y는 a와 b에 각각 남아있는 물의 양

    mp[{x, y}] = 1; // visited[y][x] = 1 과 동일 (초기 방문처리)
    q.push({ x,y });
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        // 6가지 경우의 수 함수로 처리
        enqueue(a, y, mp[{x, y}]); // A 채우기
        enqueue(x, b, mp[{x, y}]); // B 채우기
        enqueue(0, y, mp[{x, y}]); // A 비우기
        enqueue(x, 0, mp[{x, y}]); // B 비우기
        enqueue(max(0, x + y - b), min(x + y, b), mp[{x, y}]); // A -> B
        enqueue(min(x + y, a), max(0, x + y - a), mp[{x, y}]); // B -> A
    }
    if (mp[{c, d}]) return mp[{c, d}] - 1;
    else return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> c >> d;

    cout << bfs(0, 0);

    return 0;
}