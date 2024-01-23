#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> date1, vector<int> date2) {
    int answer = 0;
    
    for(int i = 0; i< date1.size(); i++)
    {
        if(date2[i]-date1[i] > 0) {
            answer = 1;
            break;
        }
        else if(date2[i] - date1[i] < 0)
        {
            answer = 0;
            break;
        }
    }
    return answer;
}