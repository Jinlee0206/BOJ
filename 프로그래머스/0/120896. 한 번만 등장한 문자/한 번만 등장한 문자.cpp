#include <bits/stdc++.h>

using namespace std;

int a[26];

string solution(string s) {
    string answer = "";
    for(int i = 0; i<s.size(); i++)
    {
        a[s[i]-'a']++;
    }
    
    for(int i = 0; i< 26; i++)
    {
        if(a[i] == 1) answer += i + 'a';
    }
    return answer;
}