#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i = 0; i<arr1.size(); i++)
    {
        arr1[i] |= arr2[i];
        
        string s = "";
        for(int idx = 0; idx < n ; idx++)
        {
            if(arr1[i] & (1 << idx)) s += '#';
            else s += ' ';
        }
        reverse(s.begin(), s.end());
        answer.push_back(s);
    }
    
    return answer;
}