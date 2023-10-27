#include <bits/stdc++.h>

using namespace std;

string solution(string my_string) {
    string answer = "";
    
    for(int i = 0; i< my_string.size(); i++)
    {
        if(my_string[i] >= 97 && my_string[i] <= 122) answer += toupper(my_string[i]);
        else if(my_string[i] >= 65 && my_string[i] <= 90) answer += tolower(my_string[i]);
    }
    
    return answer;
}