#include <bits/stdc++.h>

using namespace std;

int answer = 0, k;

void dfs(vector<int> &numbers, int here, int sum)
{
    if(here == numbers.size())
    {
        if(sum == k) answer++;
    }
    else
    {
        dfs(numbers, here+1, sum + numbers[here]);
        dfs(numbers, here+1, sum - numbers[here]);
    }
    return;
}

int solution(vector<int> numbers, int target) {
    int size = numbers.size();
    k = target;
    dfs(numbers, 0, 0);    
    
    return answer;
}