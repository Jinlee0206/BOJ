#include <bits/stdc++.h>

using namespace std;

bool ch[1000001];

int prime(int n)
{
    int cnt = 0;
    for(int i = 2; i <= n;i++)
    {
        if(ch[i]) continue;
        for(int j= 2 * i ; j <= n; j += i)
        {
            ch[j] = true;
        }
    }
    for(int i = 2; i<=n; i++)
    {
        if(!ch[i]) cnt++;
    }
    return cnt;
}

int solution(int n) {
    int answer = 0;
    answer = prime(n);
    return answer;
}