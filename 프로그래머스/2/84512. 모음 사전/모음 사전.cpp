// 백트래킹, DFS
#include <bits/stdc++.h>

using namespace std;

int cnt = 0, answer = 0;
string aeiou = "AEIOU";

void dfs(string word, string str)
{
    // 기저 사례
    if(str == word) // 단어를 찾으면 answer에 cnt 할당
    {
        answer = cnt;
        return;
    }
    
    for(int i = 0; i< 5; i++)
    {
        if(str.size() < 5)
        {
            cnt++; // 알파벳을 하나 씩 붙이는 과정에서 cnt 증가
            dfs(word, str + aeiou[i]); // word의 길이는 1이상 5이하
        }
    }
}

int solution(string word) {
    dfs(word, "");
    return answer;
}