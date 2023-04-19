#include <iostream>
using namespace std;

int solution(int n)
{
    int answer = 0;
    
    while(n > 0)
    {
        bool i = (n % 2 != 0) == true ? true : false;
        n = i ? n-1 : n/2;
        if(i) answer++;
    }
    
    return answer;
}