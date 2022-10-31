#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;

    int cntp = 0, cnty = 0;
    
    for(int i = 0; i< s.size(); i++)
    {
        if(s[i] == 'p' || s[i] == 'P') cntp++;
        if(s[i] == 'y' || s[i] == 'Y') cnty++;
    }
    
    if(cntp == cnty) answer = true;
    else answer = false;
    
    return answer;
}