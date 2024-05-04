// BOJ - 3678 : 성냥개비
#include<bits/stdc++.h>
using namespace std;
const int INF = 2147000000;

int t, n;
int a[] = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
string dp[104], max_str = "111111111111111111111111111111111111111111111111119";

string get_min_str(string a, string b)
{
    if (a.size() == b.size()) return (a < b ? a : b); // 스트링의 비교는 선 사이즈 체크 필수
    if (a.size() < b.size()) return a;
    return b;
}

// 2. 탑다운 방식
string findMin(int here)
{
    if (here == 0) return "";
    string& res = dp[here];
    if (res != max_str) return res;
    for (int i = 0; i <= 9; i++)
    {
        if (here - a[i] < 0) continue;
        if (here == n && i == 0) continue; // 성냥개비 모두 썼을때, 첫번째 인덱스가 0인 경우 불가능
        res = get_min_str(res, to_string(i) + findMin(here - a[i]));
    }
    return res;
}

string findMax(int here)
{
    string res = "";
    if (here & 1) // here이 홀수인 경우 7 붙이기
    {
        res += '7';
        here -= 3;
    }
    while (here)
    {
        res += '1';
        here -= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> n;
    	fill(dp, dp + 104, max_str);
        cout << findMin(n) << " " << findMax(n) << '\n';
    }
    return 0;
}