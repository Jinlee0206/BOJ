#define _CRT_NO_SECURE_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int n;
string str;
char a[100][100];

string quad(int y, int x, int size)
{
	//cout << y << " : " << x << " : " << size << "\n";

	// 기저 사례
	if (size == 1) return string(1, a[y][x]); // 배열의 첫번째 요소 string 값 반환

	// 메인 로직
	char b = a[y][x];
	string res = "";

	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (b != a[i][j])
			{
				res += '(';
				res += quad(y, x, size / 2);
				res += quad(y, x + size / 2, size / 2);
				res += quad(y + size / 2, x, size / 2);
				res += quad(y + size / 2, x + size / 2, size / 2);
				res += ')';
				return res;
			}
		}
	}
	return string(1, a[y][x]);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			a[i][j] = str[j];
		}
	}

	/*
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	*/

	cout << quad(0, 0, n) << "\n";

	return 0;
}