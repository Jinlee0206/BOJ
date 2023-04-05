using System;
using System.Collections;
using System.Collections.Generic;

class Solution {
    int n = 0;
    int m = 0;
    int[] dy = {-1, 0, 1, 0};
    int[] dx = {0, -1, 0, 1};
    
    Queue<(int,int)> q = new Queue<(int,int)>();
    
    public void bfs(int i, int j, int[,] maps)
    {
        q.Enqueue((i, j));
        
        while(q.Count != 0)
        {
            (int y, int x) = q.Dequeue();
            for(int k = 0; k<4; k++)
            {
                int ny = y + dy[k];
                int nx = x + dx[k];
                
                if(ny <0 || nx < 0 || ny >= n || nx >= m) continue;
                if(maps[ny,nx] == 0) continue;
                if(maps[ny,nx] == 1)
                {
                    maps[ny,nx] = maps[y,x] + 1;
                    q.Enqueue((ny,nx));
                }
            }
        }
    }
    
    
    public int solution(int[,] maps) {
        n = maps.GetLength(0);
        m = maps.GetLength(1);
        
        bfs(0,0,maps);
        
        if(maps[n-1,m-1] == 1) return -1;
        else return maps[n-1,m-1];
    }
}