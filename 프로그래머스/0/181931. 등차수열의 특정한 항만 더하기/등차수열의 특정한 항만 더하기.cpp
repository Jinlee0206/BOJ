#include <bits/stdc++.h>

using namespace std;

int solution(int a, int d, vector<bool> included) {
    int answer = 0;
    
    for(int i = 0; i<included.size(); i++)
    {
        answer += (a + (d * i)) * included[i];
    }
    return answer;
}