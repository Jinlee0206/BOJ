// BOJ-15353 : 큰 수 A+B (2)
#include<bits/stdc++.h>
using namespace std;

string sum(string a, string b)
{
	int sum = 0;
	string res;
	while (a.size() || b.size() || sum)
	{
		if (a.size())
		{
			sum += a.back() - '0';
			a.pop_back();
		}
		if (b.size())
		{
			sum += b.back() - '0';
			b.pop_back();
		}
		res += sum % 10 + '0';
		sum /= 10; // 올림
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	cin >> a >> b;
	cout << sum(a, b) << '\n';

	return 0;
}