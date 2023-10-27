#include <bits/stdc++.h>
using namespace std;

const int INF = 2147000000;
int answer = -INF;

int solution(vector<int> numbers) {
    for(int i = 0; i< numbers.size(); i++)
    {
        for(int j = i+1; j < numbers.size(); j++)
        {
            answer = max(answer, numbers[i] * numbers[j]);
        }
    }
    
    return answer;
}