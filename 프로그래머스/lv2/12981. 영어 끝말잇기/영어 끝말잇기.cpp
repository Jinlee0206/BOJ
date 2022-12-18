#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

map<string, int> m;

vector<int> solution(int n, vector<string> words) {
    int now = 1;
    
    m[words[0]] = 1;
    char prev = words[0].back();
    
    for(int i = 1; i < words.size(); i++)
    {
        if(prev != words[i].front()) return {now + 1, i/n + 1};
        if(m.count(words[i]) == 0) m[words[i]] = 1;
        else
        {
            return {now + 1, i/n + 1};
        }
        now = (now + 1) % n;
        prev = words[i].back();
    }        
    
    return {0, 0};
    
}