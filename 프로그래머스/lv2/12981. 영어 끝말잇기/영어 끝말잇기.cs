using System;
using System.Collections.Generic;

class Solution
{
    public int[] solution(int n, string[] words)
    {
        int[] answer = new int[2] {0,0};
        
        Dictionary<string, int> m = new Dictionary<string, int>();
        m.Add(words[0], 1);

        int now = 1;
        char prev = words[0][words[0].Length -1];
        
        for(int i = 1; i < words.Length; i++)
        {
            if(prev != words[i][0]) 
            {
                answer[0] = now+1; 
                answer[1] = i/n + 1;
                return answer; 
            }
            if(!m.ContainsKey(words[i])) m.Add(words[i], 1);
            else
            {
                answer[0] = now + 1;
                answer[1] = i/n + 1;
                return answer;
            }
            now = (now + 1) % n;
            prev = words[i][words[i].Length - 1];
        }
        
        return answer;
    }
}