#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer = arr;
    int size = answer.size();
    
    if(size == 1) return answer;
    
    int x = 1;
    while(true)
    {
        if(size <= pow(2,x)) break;
        x++;
    }
    
    for(int i = 0; i< pow(2,x) - size; i++)
    {
        answer.push_back(0);
    }
    return answer;
}