#include <bits/stdc++.h>

using namespace std;

vector<string> solution(vector<string> str_list) {
    vector<string> answer;
    
    int lPos = find(str_list.begin(), str_list.end(), "l") - str_list.begin();
    int rPos = find(str_list.begin(), str_list.end(), "r") - str_list.begin();
    
    if(lPos < rPos)
    {
        for(int i = 0; i < lPos; i++)
        {
            answer.push_back(str_list[i]);
        }
    }
    else
    {
        for(int i = rPos + 1; i < str_list.size(); i++) 
            answer.push_back(str_list[i]);
    }
    return answer;
}