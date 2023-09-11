#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    answer = count(array.begin(), array.end(), n);
    return answer;
}