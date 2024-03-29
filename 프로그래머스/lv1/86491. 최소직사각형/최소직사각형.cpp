#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int maxW = -2147000000, maxH = -2147000000;
    
    for(int i = 0; i< sizes.size(); i++)
    {
        int tmp = 0;
        if(sizes[i][0] < sizes[i][1])
        {
            tmp = sizes[i][0];
            sizes[i][0] = sizes[i][1];
            sizes[i][1] = tmp;
        }
        
        maxW = max(maxW, sizes[i][0]);
        maxH = max(maxH, sizes[i][1]);
    }
    
    answer = maxW * maxH;
    
    return answer;
}