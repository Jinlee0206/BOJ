#include <bits/stdc++.h>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int idx = 0;
    int sum = 0;
    queue<int> q;
    
    while(1)
    {
        // 마지막 트럭일 때
        if(idx == truck_weights.size())
        {
            answer += bridge_length;
            break;
        }
        
        answer++; // 시간초 증가
        int tmp = truck_weights[idx];
        
        if(q.size() == bridge_length)
        {
            sum -= q.front();
            q.pop();
        }
        if(sum + tmp <= weight)
        {
            sum += tmp;
            q.push(tmp);
            idx++;
        }
        else
        {
            q.push(0);
        }
        
    }
    return answer;
}