#include <bits/stdc++.h>

using namespace std;

// 투포인터 알고리즘
int solution(vector<int> elements) {
    int answer = 0;
    int length = elements.size();
    
    set<int> s; // 중복을 허용하지 않는 균형 이진트리로 구성된 연관 컨테이너
    vector<int> v(elements); // 복사할 벡터 하나 생성
    copy(v.begin(), v.end(), back_inserter(elements));  // copy : 소스 벡터에서 대상 벡터로 요소를 복사
                                                        // 반복자 어댑터(iterator_adaptor) [back_inserter] : vector의 사이즈를 여유롭게 할당한 후 resize() 하는 과정을 줄여줌,, push_back과 같음
    
    for(int start = 0; start < length; start++)
    {
        int sum = elements[start];
        s.insert(sum);
        int cnt = 1;
        int end = start;
        while(cnt < length)
        {
            cnt++;
            end++;
            sum += elements[end];
            s.insert(sum);
        }
    }
    
    answer = s.size();
    return answer;
}