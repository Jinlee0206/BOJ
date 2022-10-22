#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;

string solution(string s) {
    string answer = "";
    
    string tmp = s;
    
    for(int i = 0; i< s.size(); i++)
    {
        if(s[i] == ' ')
        {
            vec.push_back(atoi(tmp.c_str()));
            tmp.clear();
        }else
        {
            tmp += s[i];
        }
    }
    
    vec.push_back(atoi(tmp.c_str()));
    sort(vec.begin(), vec.end());
    answer += to_string(vec.front()) + " " + to_string(vec.back());
    
    
    return answer;
}