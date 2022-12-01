#include <string>
#include <vector>
#include <stack>

using namespace std;

stack<int> stk;

int solve(int res)
{
    int idx = 1;
    
    while(stk.size())
    {
        int a = stk.top();
        stk.pop();
        res += a * idx;
        idx *= 3;
    }
    return res;
}

void go (int a)
{
    while(a)
    {
        stk.push(a%3);
        a /= 3;
    }
}

int solution(int n) {
    int answer = 0;
    
    go(n);
    
    answer = solve(answer);
    
    return answer;
}