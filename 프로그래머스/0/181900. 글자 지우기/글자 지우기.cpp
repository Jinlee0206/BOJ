#include <bits/stdc++.h>

using namespace std;

string solution(string my_string, vector<int> indices) {
    string answer = "";
    
    sort(indices.begin(), indices.end());
    for(int i = 0; i<indices.size(); i++)
    {
        my_string.erase(indices[i] - i, 1);
    }
    answer = my_string;
    return answer;
}