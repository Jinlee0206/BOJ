#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, string overwrite_string, int s) {
    string answer = my_string;
    
    answer.replace(answer.begin() + s, answer.begin() + s + overwrite_string.length(), overwrite_string);
        
    return answer;
}