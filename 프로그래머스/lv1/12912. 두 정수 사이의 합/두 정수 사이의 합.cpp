#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    
    if(a == b) return a;
    else if (a < b)
    {
        int tmp;
        tmp = a;
        a = b;
        b = tmp;
    }
    
    while(a>=b)
    {
        answer += b++;
    }
    
    return answer;
}