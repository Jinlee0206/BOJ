using System;
using System.Collections.Generic;
using System.Linq;

public class Solution {
    public int solution(int[] queue1, int[] queue2) {
        int Temp = 0;
        long TotalVal = 0;
        long HalfVal = 0;
        int count = 0;
        int PossibleCheck = 0;
        long Q1Sum =0;
        long Q2Sum =0;
        Queue<int> Q1 = new Queue<int>();
        Queue<int> Q2 = new Queue<int>();
        for(int i =0; i < queue1.Length; ++i) // 각 배열을 큐에 저장
        {
            Q1.Enqueue(queue1[i]);
            Q2.Enqueue(queue2[i]);
        }
        Q1Sum=Qsum(queue1);
        Q2Sum=Qsum(queue2);
        TotalVal = Q1Sum + Q2Sum;
        if (TotalVal % 2 == 1) //첫번째 예외처리 두 큐의 합이 홀수일때 <- 두 큐의 길이가 1일때 값이 같지않은경우 또한 제외
            return -1;
        HalfVal = TotalVal / 2;
        PossibleCheck = queue1.Length*4;
        while (count < PossibleCheck)
        {
                if (Q1Sum < HalfVal)
                {
                    if (Q2.Count == 1) return -1;
                    TossQue(Q2, Q1,ref Q2Sum,ref Q1Sum);
                    ++count;
                }
                else if (Q2Sum < HalfVal)
                {
                    if (Q1.Count == 1) return -1;
                    TossQue(Q1, Q2, ref Q1Sum, ref Q2Sum);
                    ++count;
                }
                         if (Q1Sum == HalfVal)
                {
                    return count;
                }
        }
        return -1;
    }
    static void TossQue(Queue<int> Q1 , Queue<int> Q2 , ref long Q1Sum, ref long Q2Sum) // 1번큐에서 빼서 2번큐에 넣기
    {
            int Temp = 0;
            Temp = Q1.Dequeue();
            Q1Sum -= Temp;
            Q2Sum += Temp;
            Q2.Enqueue(Temp);
            return;
    }
    static long Qsum(int[] que)
    {
        long tmp = 0;
        for (int i = 0; i < que.Length; i++)
        {
            tmp += que[i];
        }
        return tmp;
    }
}