#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<int> arr) {
    for(int i = 0; i< arr.size(); i++)
    {
        if(arr[i] >= 50 && ((arr[i] & 1) == 0)) arr[i] /= 2;
        else if(arr[i] < 50 && ((arr[i] & 1) == 1)) arr[i] *= 2;
    }
    return arr;
}