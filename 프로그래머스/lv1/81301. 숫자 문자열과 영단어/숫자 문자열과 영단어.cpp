#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 0;
    string res = "";
    
    while(s.size())
    {
        if((int)s[0] >= '0' && (int)s[0] <= '9')
        {
            res += s[0];
            s.erase(0, 1);
        }
        else
        {
            if(s[0] == 'z')
            {
                res += '0';
                s.erase(0,4);
            }
            else if(s[0] == 'o')
            {
                res += '1';
                s.erase(0,3);
            }
            else if(s[0] == 't')
            {
                if(s[1] == 'w')
                {
                    res += '2';
                    s.erase(0,3);
                }
                else
                {
                    res += '3';
                    s.erase(0,5);
                }
            }
            else if(s[0] == 'f')
            {
                if(s[1] == 'o')
                {
                    res += '4';
                    s.erase(0,4);
                }
                else
                {
                    res += '5';
                    s.erase(0,4);
                }
            }
            else if(s[0] == 's')
            {
                if(s[1] == 'i')
                {
                    res += '6';
                    s.erase(0,3);
                }
                else 
                {
                    res += '7';
                    s.erase(0,5);
                }
            }
            else if(s[0] == 'e')
            {
                res+='8';
                s.erase(0,5);
            }
            else
            {
                res += '9';
                s.erase(0,4);
            }
        }
    }
    
    answer = stoi(res);
    
    return answer;
}