#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, res = -2147000000;

vector<char> oper_str;
vector<int> num;

int oper(char a, int b, int c)
{
	if (a == '+') return b + c;
	if (a == '-') return b - c;
	if (a == '*') return b * c;
}

// 재귀와 누적합
void go(int here, int _num)
{
	if (here == num.size() - 1)
	{
		res = max(res, _num);
		return;
	}

	go(here + 1, oper(oper_str[here], _num, num[here + 1]));
	if (here + 2 <= num.size() - 1)
	{
		int tmp = oper(oper_str[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, oper(oper_str[here], _num, tmp));
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	string str;
	cin >> str;

	for (int i = 0; i < n; i++)
	{
		if (i % 2 == 0)  num.push_back(str[i] - '0'); 
		else oper_str.push_back(str[i]);
	}

	go(0, num[0]);
	cout << res << "\n";

	return 0;
}