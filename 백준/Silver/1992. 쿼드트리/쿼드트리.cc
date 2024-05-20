// BOJ - 1992 : 쿼드트리
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n;
char a[65][65];

string go(int y, int x, int size)
{	
	if (size == 1) return string(1, a[y][x]); // char 형을 string으로 만드는 함수 string(size, char);
	char b = a[y][x];
	string res = "";
	for (int i = y; i < y + size; i++)
	{
		for (int j = x; j < x + size; j++)
		{
			if (b != a[i][j])
			{
				res += '(';
				res += go(y, x, size / 2);
				res += go(y, x + size / 2, size / 2);
				res += go(y + size / 2, x, size / 2);
				res += go(y + size / 2, x + size / 2, size / 2);
				res += ')';
				return res; // 압축이 안되는 경우
			}
		}
	}
	return string(1, a[y][x]); // 압축이 되는 경우
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.size(); j++)
		{
			a[i][j] = str[j];
		}
	}

	cout << go(0, 0, n) << '\n';

	return 0;
}