#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = s.size();
    
    for(int i = 1; i<= s.size()/2; i++)
    {
        int cnt = 1;
        string tmp = "", cmp = "";
        cmp = s.substr(0,i);
        
        for(int j = i; j< s.size(); j+=i)
        {
            if (cmp == s.substr(j,i)) cnt++;
            else 
            {
                if(cnt > 1) tmp += to_string(cnt);
                tmp += cmp;
                cmp = s.substr(j,i);
                cnt = 1;
            }
        }
        
        if(cnt > 1) tmp += to_string(cnt);
        tmp += cmp;
        if(answer > tmp.size()) answer= tmp.size(); 
    }   
        
    return answer;
}