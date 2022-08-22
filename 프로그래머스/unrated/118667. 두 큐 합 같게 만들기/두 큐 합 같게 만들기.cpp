#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int length = queue1.size();
    long mid = 0;

    queue<long> q1;
    queue<long> q2;

    int cnt = 0;
    long sum1 = 0, sum2 = 0;

    for (int i = 0; i < length; i++)
    {
        mid += queue1[i] + queue2[i];
        sum1 += queue1[i];
        sum2 += queue2[i];
        q1.push(queue1[i]);
        q2.push(queue2[i]);
    }

    mid /= 2;

    if ((sum1 + sum2) % 2 != 0) return -1;

    while (true)
    {
        if (cnt >= length * 3) break;

        if (sum1 > sum2)
        {
            int tmp = q1.front();
            q2.push(tmp);
            sum1 -= tmp;
            sum2 += tmp;
            q1.pop();
        }

        else if (sum2 > sum1)
        {
            int tmp = q2.front();
            q1.push(tmp);
            sum2 -= tmp;
            sum1 += tmp;
            q2.pop();
        }
        else
        {
            if (sum1 == mid) return cnt;
            break;
        }

        cnt++;
    }

    return -1;
}