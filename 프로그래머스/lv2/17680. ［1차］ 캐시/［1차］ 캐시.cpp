#include <bits/stdc++.h>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    // 캐시 사이즈가 0인 경우 cache miss 만 cities의 size만큼 일어난다
    if(cacheSize == 0) return cities.size() * 5;
    
    vector<string> s;
    int answer = 0;
    
    for(int i = 0; i< cities.size(); i++)
        transform(cities[i].begin(), cities[i].end(), cities[i].begin(), ::tolower);
    
    for(int i = 0; i< cities.size(); i++)
    {
        // cache miss
        if(find(s.begin(), s.end(), cities[i]) == s.end())
        {
            // 캐시 용량 여유 있다
            if(s.size() < cacheSize)
            {
                s.push_back(cities[i]);
                answer += 5;
            }
            else if (s.size() == cacheSize)
            {
                // 맨 앞이 가장 오래된 참조
                if(!s.empty()) s.erase(s.begin());
                s.push_back(cities[i]);
                answer += 5;
            }
        }
        // cache hit
        else if(find(s.begin(), s.end(), cities[i]) != s.end())
        {
            // 찾은 거 삭제
            s.erase(find(s.begin(), s.end(), cities[i]));
            s.push_back(cities[i]);
            answer++;
        }
    }
    
    return answer;
}