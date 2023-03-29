#include<bits/stdc++.h>
using namespace std;

double solution(vector<int> arr) {   
    double sum = 0;
    
    //for(int i = 0; i<arr.size(); i++)
    //{
    //    sum += arr[i];
    //}
    
    sum = accumulate(arr.begin(), arr.end(), 0);
    sum /= arr.size();
    
    return sum;
}