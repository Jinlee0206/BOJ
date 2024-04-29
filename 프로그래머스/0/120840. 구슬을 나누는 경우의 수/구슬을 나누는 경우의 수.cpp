#include <bits/stdc++.h>

using namespace std;


int solution(int balls, int share) {
    unsigned long long answer = 1;
    for(int i = 0; i< share; i++)
    {
        answer = answer * (balls - i) / (i + 1);
    }
    
    // 5C3 = 5 4 (3 2 1) / (3 2 1) * (2 1)
    // i = 1 : 1 * 5 / 1
    // i = 2 : 5 * 4 / 2
    // i = 3 : (5 * 4 / 2) * 3 / 3
    return answer;
}