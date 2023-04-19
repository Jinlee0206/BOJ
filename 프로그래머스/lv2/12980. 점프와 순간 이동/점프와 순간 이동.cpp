#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    
    while(n > 0)
    {
        bool i = (n % 2 != 0) == true ? true : false;
        if(i)
        {
            n -= 1;
            answer++;
        }
        else
        {
            n /= 2;
        }
    }
    
    return answer;
}