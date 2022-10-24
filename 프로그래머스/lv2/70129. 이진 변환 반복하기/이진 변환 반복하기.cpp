#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    
    int cnt = 0;
    int sum = 0;
    
    while(s != "1")
    {
        int tmpCnt = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '1') tmpCnt++;
        }
        
        sum += s.length() - tmpCnt;
        
        s = "";
        
        while(tmpCnt > 0)
        {
            if(tmpCnt % 2 == 0) s += "0";
            else s += "1";
            tmpCnt /= 2;
        }
        
        cnt++;
    }
    
    answer.push_back(cnt);
    answer.push_back(sum);
    
    return answer;
}