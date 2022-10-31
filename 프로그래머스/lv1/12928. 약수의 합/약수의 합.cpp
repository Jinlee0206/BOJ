#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    int tmp = n;
    
    while(1)
    {
        if(n==0) break;
        
        if(tmp % n == 0) answer += n;
        
        n--;
    }
    
    return answer;
}