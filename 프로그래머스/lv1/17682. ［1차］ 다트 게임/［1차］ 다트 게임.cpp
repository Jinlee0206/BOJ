#include <string>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int curScore =0;
    vector<int> v;
    int idx = 0;
    
    for(int i = 0; i< dartResult.size(); i++)
    {
        if(dartResult[i] -'0' >= 0 && dartResult[i] - '0' <= 9) 
            curScore = curScore * 10 + (dartResult[i] - '0');
        
        if(dartResult[i] == 'S') 
        {
            v.push_back(curScore);
            idx++;
            curScore = 0;
        }
        else if(dartResult[i] == 'D')
        {
            v.push_back(curScore * curScore);
            curScore = 0;
            idx++;
        }
        else if(dartResult[i] == 'T')
        {
            v.push_back(curScore * curScore * curScore);
            curScore = 0;
            idx++;
        }
        else if(dartResult[i] == '#')
        {
            v[idx-1] *= -1;
        }
        else if(dartResult[i] == '*')
        {
            if(v.size() == 1) v[idx-1] *= 2;
            else
            {
                v[idx-1] *= 2;
                v[idx-2] *= 2;
            }
        }
    }
    
    for(int i = 0; i< v.size(); i++) answer += v[i];
    
    return answer;
}