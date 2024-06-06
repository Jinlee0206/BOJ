#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    int cmp2 = common[2] - common[1];
    int cmp1 = common[1] - common[0];
    
    if(cmp1 != cmp2)
    {
        int tmp = cmp2 / cmp1;
        answer = common[common.size() - 1] * tmp;
    }
    else
    {
        answer = common[common.size() - 1] + cmp2;
    }
    
    return answer;
}