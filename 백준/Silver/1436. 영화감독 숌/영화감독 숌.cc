#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	// 반복문 사용
	int ans = 665;
	int cnt = 0;

	
	while (cnt != n)
	{
		++ans;
		int tmp = ans;

		while (tmp != 0)
		{
			if (tmp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else tmp /= 10;
		}
	}

	cout << ans << "\n";

	// find() 함수 사용

	/*
	string s;

	while (++ans)
	{
		s = to_string(ans);

		if (s.find("666") != string::npos) ++cnt;
		if (cnt == n)
		{
			cout << ans << "\n";
			break;
		}
	}
	*/



	return 0;
}