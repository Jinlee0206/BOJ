#include <bits/stdc++.h>

using namespace std;

int solution(int i, int j, int k) {
    int answer = 0;
    
    for(int l = i; l <= j; l++)
    {
        int tmp = l;
        while(tmp > 0)
        {
            if(tmp % 10 == k) answer++;
            tmp /= 10;
        }
    }
    return answer;
}