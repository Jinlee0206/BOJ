#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    queue<int> q;
    
    q.push(arr[0]);
    for(int i = 1; i<arr.size(); i++)
    {
        if(arr[i] == arr[i-1]) continue;
        q.push(arr[i]);
    }
    
    while(q.size())
    {
        int a;
        a = q.front();
        q.pop();
        
        answer.push_back(a);
    }
    
    return answer;
}