#include <bits/stdc++.h>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 1;
    
    int idx = section[0];
    
    for(int i = 1; i < section.size(); i++)
    {
        if(section[i] - idx > (m-1))
        {
            answer++;
            idx = section[i];
        }
    }
    
    return answer;
}