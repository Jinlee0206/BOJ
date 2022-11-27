#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    
    int a = 0;
    
    while(n--)
    {
        a++;
        if(a % 2 == 1) answer += "수";
        else answer += "박";
    }
    
    return answer;
}