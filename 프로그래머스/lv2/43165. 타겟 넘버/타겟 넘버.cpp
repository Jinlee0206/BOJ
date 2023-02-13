#include <bits/stdc++.h>

using namespace std;

int answer = 0;

void dfs(vector<int> &numbers, int start, int end, int val, int target)
{
    if(start == end)
    {
        if(val == target) answer++;
    }
    else
    {
        dfs(numbers, start+1, end, val + numbers[start], target);
        dfs(numbers, start+1, end, val - numbers[start], target);
    }
}

int solution(vector<int> numbers, int target) {
    int size = numbers.size();
    
    dfs(numbers, 0, size, 0, target);    
    
    return answer;
}