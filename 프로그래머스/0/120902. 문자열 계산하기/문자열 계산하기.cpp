#include <bits/stdc++.h>

using namespace std;

int solution(string my_string) {
    int answer = 0;
    
    string tmp = "";
    string str = "+";
    
    for(int i = 0; i< my_string.size(); i++)
    {
        if(isdigit(my_string[i])) tmp += my_string[i];
        
        else if(my_string[i] == '+')
        {
            int num = 0;
            num = stoi(tmp);
            if(str == "+") answer += num;
            else answer -= num;
            tmp = "";
            str = "+";
        }
        else if(my_string[i] == '-')
        {
            int num = 0;
            num = stoi(tmp);
            if(str == "+") answer += num;
            else answer -= num;
            tmp = "";
            str = "-";
        }
    }
    
    if(!tmp.empty())
    {
        if(str == "+") answer += stoi(tmp);
        else if(str == "-") answer -= stoi(tmp);
    }
    
    return answer;
}