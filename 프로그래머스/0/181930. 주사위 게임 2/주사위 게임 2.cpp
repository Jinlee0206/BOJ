#include <bits/stdc++.h>

using namespace std;

int solution(int a, int b, int c) {
    int answer = 0;
    if(a == b && b == c && c == a)
    {
        answer = (a + b + c) * (pow(a,2) + pow(b,2) + pow(c,2)) * (pow(a,3) + pow(b,3) + pow(c,3)); 
    }
    else if((a == b && a != c) || (b == c && b != a) || (c == a && c != b))
    {
        answer = (a + b + c) * (pow(a,2) + pow(b,2) + pow(c,2));
    }
    else
    {
        answer = a + b + c;
    }
    return answer;
}