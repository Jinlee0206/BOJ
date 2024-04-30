#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr, vector<vector<int>> queries) {
    vector<int> answer;
    for(int i = 0; i< queries.size(); i++)
    {
        int s = queries[i][0];
        int e = queries[i][1];
        int k = queries[i][2];
        vector<int> v;
        for(int j = s; j <= e; j++)
        {
            v.push_back(arr[j]);
        }
        sort(v.begin(), v.end());
        int pos = upper_bound(v.begin(), v.end(), k) - v.begin();
        if(pos != v.size())
        {
            answer.push_back(v[pos]);
        } else answer.push_back(-1);
    }
    return answer;
}