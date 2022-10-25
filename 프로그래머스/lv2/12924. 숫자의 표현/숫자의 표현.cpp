#include <string>
#include <vector>

using namespace std;

int go(int n)
{
    int end = (n+1)/2;
    int res = 1, sum = 0, j = 1;
    
    if (n == 1) return 1;
    
    for(int i = 1; i<= end; i++)
    {
        sum += i;
        
        if(sum >= n)
        {
            while(sum > n) sum -= j++;
            
            if(sum == n) res++;
        }
    }
    
    return res;
}

int solution(int n) {
    int answer = 1;
    
    answer = go(n);
    
    return answer;
}