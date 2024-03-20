#include <bits/stdc++.h>

using namespace std;

const int INF = 2147000000;
int m_min = INF;
int solution(vector<int> array, int n) {
    int answer = 0;
    int idx;
    sort(array.begin(), array.end());
    for(int i = 0; i< array.size(); i++)
    {
        if(m_min > abs(array[i] - n))
        {
            m_min = abs(array[i] - n);
            idx = i;
        }
    }
    answer = array[idx];
    
    return answer;
}