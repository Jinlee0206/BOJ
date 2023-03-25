using System;

class Solution
{
    public long solution(int price, int money, int count)
    {
        long answer = 0;
		for(int i = 0; i<count; i++)
		{
			answer += (i+1) * price;
		}
		if (answer >= money) answer -= money;
		else answer = 0;
		return answer;
    }
}