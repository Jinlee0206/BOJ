#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> numbers, int k) {
    // k * 2 공을 받는 사람 위치
    // (k-1) * 2 공을 던지는 사람 위치
    // numbers.size() 만큼 나머지 연산
    return numbers[((k-1) * 2) % numbers.size()];
}