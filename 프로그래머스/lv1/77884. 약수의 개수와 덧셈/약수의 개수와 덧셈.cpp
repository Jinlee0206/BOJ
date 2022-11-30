#include <string>
#include <vector>

using namespace std;

bool isTrue(int a)
{
    int x = 1;
    int ori = a;
    
    while(a--)
    {
        if(a != 0 && ori % a == 0) x++;
    }
    
    if(x % 2 == 0) return true;
    else return false;
}

int solution(int left, int right) {
    int answer = 0;
    
    for(int i = left; i<=right; i++)
    {
        if(isTrue(i)) answer += i;
        else answer -= i;
    }
    
    return answer;
}