#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer;
    
    int r = board[0] / 2;
    int u = board[1] / 2;
    int a = 0, b = 0;
    
    for(int i = 0; i< keyinput.size(); i++)
    {
        char ch = keyinput[i][0];
        switch(ch)
        {
            case 'l':
                if(a > -r) a--;                   
                break;
            case 'r':
                if(a < r) a++;
                break;
            case 'u':
                if(b < u) b++;
                break;
            case 'd':
                if(b > -u) b--;
                break;
        }
    }
    answer.push_back(a);
    answer.push_back(b);
    return answer;
}