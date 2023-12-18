// BOJ-5430 : AC
#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--)
	{
		string p, s;
		int n, tmp = 0;

		cin >> p >> n >> s;

		deque<int> dq; // 덱을 활용하여 R 함수 처리

		for (int i = 1; i < s.size() - 1; i++)
		{
			if (s[i] != ',')
			{
				tmp = tmp * 10 + (s[i] - '0');
			}
			else
			{
				dq.push_back(tmp);
				tmp = 0;
			}
		}
		if(tmp != 0) dq.push_back(tmp); //빈 배열이 주어질 때 반례 체크

		bool isRev = false; // 실제 배열을 뒤집는 것이 아니라 bool 값과 deque를 활용하여 앞 또는 뒤의 원소 제거
		bool isError = false; // 에러 발생을 체크하는 boolean 변수

		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R') isRev = !isRev;
			else if (p[i] == 'D')
			{
				if (dq.empty())
				{
					isError = true; // 빈 배열에 D 함수 사용 시 에러
					break;
				}

				if (isRev == true) dq.pop_back();
				else if (isRev == false) dq.pop_front();
			}
		}

		if (!isError) // 에러 발생 하지 않았을 때 정답 출력
		{
			cout << "[";
			if (isRev) reverse(dq.begin(), dq.end());
			for (int i = 0; i < dq.size(); i++)
			{
				cout << dq[i];
				if (i < (dq.size() - 1)) cout << ",";
			}
			
			cout << "]\n";
		}
		else cout << "error" << '\n'; // 에러 발생시
	}

	return 0;
}