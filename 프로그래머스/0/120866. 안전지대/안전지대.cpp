#include <bits/stdc++.h>

using namespace std;

const int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int a[104][104];

int solution(vector<vector<int>> board) {
    int answer = 0;
    
    int n = board.size();
    for(int i = 0; i< board.size(); i++)
    {
        for(int j= 0; j<board[i].size(); j++)
        {
            if(board[i][j] == 1){
                a[i][j] = 1;
                int y = i;
                int x = j;
                for(int k = 0; k < 8; k++)
                {
                    int ny = y + dy[k];
                    int nx = x + dx[k];
                    if(ny < 0 || nx < 0 || ny >= n || nx >= n|| a[ny][nx] == 1) continue;
                    a[ny][nx] = 1;
                }
            }
        }
    }
    
    for(int i = 0; i< n; i++)
    {
        for(int j= 0; j< n; j++)
        {
            if(a[i][j] == 0) answer++;
        }
    }
    
    return answer;
}