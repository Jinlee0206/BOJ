#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    bool isPlus = true;
    
    for(int i = 0; i<s.size(); i++)
    {
        if (s[i] == '-') 
        {
            isPlus = false;
            continue;
        }
        else if(s[i] == '+')
        {
            isPlus = true;
            continue;
        }
        
        answer += (int)(s[i] - '0');
        answer *= 10;
    }
    answer /= 10;
    
    if(!isPlus) answer *= -1;
    
    return answer;
}