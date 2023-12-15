#include <bits/stdc++.h>
using namespace std;

int solution(string number) {
    int answer = 0;
    
    for(char ch : number)
    {
        answer += ch - '0';
    }
    
    answer %= 9;
    
    return answer;
}