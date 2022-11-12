#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string str1, str2, res;

string go(string a, string b)
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
		res += (sum % 10) + '0';
		sum /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> str1 >> str2;

	cout << go(str1, str2) << "\n";

	return 0;
}