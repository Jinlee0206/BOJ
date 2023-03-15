#include <bits/stdc++.h>

using namespace std;

int isPalindrome(string s, int left, int right)
{
    while(left >= 0 && right < s.size())
    {
        if(s[left] != s[right]) break;
        left--;
        right++;
    }
    return right - left - 1;
}

int solution(string s)
{
    int answer = 0;
    for(int i = 0; i<s.size(); i++)
    {
        int odd = isPalindrome(s, i, i);
        int even = isPalindrome(s, i-1, i);
        answer = max(answer, (odd > even) ? odd : even);
    }
    return answer;
}