using namespace std;

long long solution(int price, int money, int count)
{
    long long answer = 0;
    
    long long hap;
    
    hap = (count * (count + 1)) / 2;
    
    hap *= price;
    
    answer = hap - money;
    
    if(answer <= 0) answer = 0;

    return answer;
}