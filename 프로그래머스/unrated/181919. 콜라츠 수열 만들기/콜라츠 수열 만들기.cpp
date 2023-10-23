#include <bits/stdc++.h>

using namespace std;

vector<int> answer;

void go(int n)
{
    answer.push_back(n);
    if(n == 1) return;
    
    if(n % 2 == 0)
    {
        n /= 2;
        go(n);
    }
    else
    {
        n = 3 * n + 1;
        go(n);
    }
}

vector<int> solution(int n) {
    go(n);
    return answer;
}