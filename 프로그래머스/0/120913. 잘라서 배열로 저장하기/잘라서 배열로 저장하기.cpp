#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_str, int n) {
    vector<string> answer;
    string tmp = "";
    for(int i = 0; i < my_str.size(); i += n)
    {
        tmp = my_str.substr(i, n);
        answer.push_back(tmp);
        tmp = "";
    }
    if(tmp != "") answer.push_back(tmp);
    return answer;
}