#include <bits/stdc++.h>

using namespace std;
vector<int> answer;
    
void makeNumber(int n)
{
    int a = 1;
    while(n >= a)
    {
        if(n % a == 0)
        {
            answer.push_back(a);
        }
        a++;
    }
}

vector<int> solution(int n) {
    makeNumber(n);
    return answer;
}