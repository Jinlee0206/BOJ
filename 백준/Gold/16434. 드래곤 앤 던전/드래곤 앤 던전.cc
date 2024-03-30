// BOJ - 16434 : 드래곤 앤 던전
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e18;
ll n, h_atk, t, a, h, res = INF, l =1, r = 1e18, mid;

struct A
{
    int t; int a; int h;
} arr[123466];

bool check(ll mid)
{
    ll mxHp = mid;
    ll init_atk = h_atk;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].t == 2)
        {
            mid = min(mxHp, mid + arr[i].h); // 포션 먹었을 때 최대 체력보다 높으면 최대치로 설정
            init_atk += arr[i].a;
        }
        else
        {
            ll cnt = arr[i].h / init_atk + (arr[i].h % init_atk ? 1 : 0);
            mid -= (cnt - 1) * arr[i].a; // (몬스터의 공격횟수) = (플레이어의 공격횟수 - 1)
        }
        if (mid <= 0) return false; // 용사의 죽음
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> h_atk;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].t >> arr[i].a >> arr[i].h;
    }
    
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            res = mid;
        }
        else l = mid + 1;
    }
    cout << res << '\n';

    return 0;
}
