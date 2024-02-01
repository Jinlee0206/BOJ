#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer = arr;
    
    for(int i= 0; i< queries.size(); i++)
    {
        swap(answer[queries[i][0]], answer[queries[i][1]]);
    }
    return answer;
}