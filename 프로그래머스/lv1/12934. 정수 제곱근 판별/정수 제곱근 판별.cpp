#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    
    long long a = sqrt(n);
    
    // n의 제곱근이 자연수가 아닌 경우에는 n/sqrt(n) = n 값이 자연수로 다시 저장되지 않는다
    if(a*a == n)
    {
        answer = pow(a+1, 2);
    }
    
    return answer;
}