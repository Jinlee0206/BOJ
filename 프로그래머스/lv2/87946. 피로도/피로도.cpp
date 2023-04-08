#include <bits/stdc++.h>

using namespace std;

int answer = 0;
int visited[10];

void dfs(int stamina, int level, vector<vector<int>> dungeons)
{
    answer = max(answer, level);
    
    for(int i = 0; i< dungeons.size(); i++)
    {
        if(visited[i] == 0 && stamina >= dungeons[i][0])
        {
            visited[i] = 1;
            dfs(stamina - dungeons[i][1], level + 1, dungeons);
            visited[i] = 0;
        }
    }
    return;
}

int solution(int k, vector<vector<int>> dungeons) {
    
    dfs(k, 0, dungeons);
    
    return answer;
}