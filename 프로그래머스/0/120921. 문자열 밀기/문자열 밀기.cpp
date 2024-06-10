#include <bits/stdc++.h>

using namespace std;

int solution(string A, string B) {
    int answer = -1;
    
    int cnt = A.size() - 1;
    if(A == B) {
        answer = 0;
        return answer;
    }
    while(cnt--)
    {
        rotate(A.rbegin(), A.rbegin() + 1 ,A.rend());
        if(A == B) {
            answer = A.size() - 1 - cnt;
            break;
        }
    }
    return answer;
}