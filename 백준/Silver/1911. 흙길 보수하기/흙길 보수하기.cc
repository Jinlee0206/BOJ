#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, idx, b, res;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        // idx 가 각 웅덩이 끝지점보다 뒤에 있으면 다음 웅덩이로 넘어간다.
        if (v[i].second <= idx) continue;
        // idx가 웅덩이 시작점보다 왼쪽에 있을 때
        if (idx < v[i].first)
        {
            b = (v[i].second - v[i].first) / m
                + ((v[i].second - v[i].first) % m ? 1 : 0); // 나누어 떨어지면 0, 나머지 남으면 1
            idx = v[i].first + b * m;
        }
        // idx가 웅덩이 시작점보다 오른쪽에 있을 때
        else
        {
            b = (v[i].second - idx) / m + ((v[i].second - idx) % m ? 1 : 0);
            idx = idx + b * m;
        }
        res += b;
    }
    cout << res << '\n';
    return 0;
}