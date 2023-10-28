// 13913 : 숨바꼭질 4
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n, k;
int visited[MAX + 4], pos[MAX+4];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;
    pos[n] = n;

    while (q.size())
    {
        int now = q.front();
        q.pop();

        for (int next : {now - 1, now + 1, now * 2})
        {
            if (next <0 || next > MAX) continue;
            if (visited[next]) continue;

            visited[next] = visited[now] + 1;
            pos[next] = now;
            q.push(next);
        }
    }

    cout << visited[k] - 1 << '\n';

    deque<int> dq = { k };
    while (dq.front() != n) dq.push_front(pos[dq.front()]);

    for (int i : dq) cout << i << ' ';

    return 0;
}