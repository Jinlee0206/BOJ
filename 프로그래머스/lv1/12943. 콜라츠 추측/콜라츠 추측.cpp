#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    
    long long renum = num;
    
    while(1)
    {
        if(renum == 1) break;
        
        if(renum % 2 == 0)
        {
            renum /= 2;
            answer++;
        }
        else 
        {
            renum = (renum *3) + 1;
            answer++;
        }
        
        if(answer >= 500)
        {
            answer = -1;
            break;
        }
    }
    
    return answer;
}