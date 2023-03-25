using namespace std;

long long solution(int price, int money, int count)
{
    long long answer;
    long long sum;
    
    sum = count * (count + 1) / 2;
    answer = sum  * price;
    
    if (answer >= money) answer -= money;
    else answer = 0;
    
    return answer;
}