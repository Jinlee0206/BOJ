
#include <bits/stdc++.h>

using namespace std;

int solution(int storey) {
    int answer = 0;

    while (storey)
    {
        int remain = storey % 10;

        if (remain > 5){
            answer += (10 - remain);
            storey += 10;
        }
        else if (remain < 5)
        {
            answer += remain;
        }
        else
        {
            if((storey/10) % 10 > 4)
            {
               storey += 10;
            }
            answer += remain;
        }
        storey /= 10;
    }
    return answer;
}
