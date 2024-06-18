#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> m_map;
vector<bool> ch;

void dfs(int node)
{
    for(int i = 0; i< m_map.size(); i++)
    {
        if(m_map[node][i] == 1 && !ch[i])
        {
            ch[i] = true;
            dfs(i);    
        }
    }
    return;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    
    m_map = computers;
    
    for(int i = 0; i< n; i++) ch.push_back(false);
    
    for(int i = 0; i< n; i++)
    {
        if(!ch[i])
        {
            dfs(i);
            answer++;
        }
    }
    
    return answer;
}