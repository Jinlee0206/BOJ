#include <string>
#include <vector>

using namespace std;

int fibo[100001];

int fibonazzi(int n)
{
    if (fibo[n]) return fibo[n];
    if (n == 0 || n == 1) return n;
    else return fibo[n] = (fibonazzi(n-1) + fibonazzi(n-2)) % 1234567;  
}

int solution(int n) {
    int answer = 0;
    
    answer = fibonazzi(n);
    
    return answer;
}