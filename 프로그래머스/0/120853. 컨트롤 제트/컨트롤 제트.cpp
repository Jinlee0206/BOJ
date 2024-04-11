#include <bits/stdc++.h>

using namespace std;

int solution(string s) {
    int answer = 0;
    vector<string> s_list;
    stringstream ss(s);
    string tmp;
    
    while(ss >> tmp) s_list.push_back(tmp);
    for(int i = 0; i< s_list.size(); i++)
    {
        if(s_list[i] == "Z") answer -= stoi(s_list[i-1]);
        else answer += stoi(s_list[i]);
    }
    return answer;
}