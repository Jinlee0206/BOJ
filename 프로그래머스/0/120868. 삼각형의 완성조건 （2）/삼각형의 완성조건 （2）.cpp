#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> sides) {
    int answer = 0;
    sort(sides.begin(), sides.end());
    answer += sides[0];
    answer += sides[0] - 1;
    return answer;
}