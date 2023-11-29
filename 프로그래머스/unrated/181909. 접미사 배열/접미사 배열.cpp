#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    
    for(int i = 0; i< my_string.size(); i++)
    {
        string tmp = my_string.substr(i);
        answer.push_back(tmp);
    }
    sort(answer.begin(), answer.end());
    return answer;
}