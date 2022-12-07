#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;
    
    while(1)
    {
        if(n == 0) break;
        
        if(n % 2 == 1) ans++;
        n /= 2;
    }
    
    return ans;
}