#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, M, sum = 0, min = 2147000000, cnt = 0, nCnt = 0;
	cin >> N >> M;

	for (int i = N; i <= M; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			if (i % j == 0)
			{
				cnt++;
			}
		}

		if (cnt == 2)
		{
			nCnt++;
			sum += i;
			
			if (nCnt == 1) min = i;
			
		}
		cnt = 0;

	}

	if (sum != 0) cout << sum << "\n" << min; 
	else cout << "-1";

	return 0;
}
