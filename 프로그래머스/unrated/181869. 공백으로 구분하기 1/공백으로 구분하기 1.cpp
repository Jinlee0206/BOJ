#include <bits/stdc++.h>

using namespace std;

vector<string> solution(string my_string) {
    vector<string> answer;
    char d = ' ';
    string str = "";
    for(int i = 0; i< my_string.size(); i++)
    {
        if(my_string[i] == d)
        {
            answer.push_back(str);
            str = "";
            continue;
        }
        str += my_string[i];
    }
    answer.push_back(str);
    return answer;
}