// BOJ-12100 : 2048 (easy)
#include <bits/stdc++.h>
using namespace std;

int n, res;

struct Board {
	int a[24][24];

	// 1. 배열이 90도 회전하는 로직
	void Rotate90()
	{
		int tmp[24][24];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) {
				tmp[i][j] = a[n - j - 1][i];
			}
		}
		memcpy(a, tmp, sizeof(a));
	}

	// 2. 메인로직
	
	/// <summary>
	/// [2][0][2][0] => [4][0][0][0]
	/// </summary>
	void MoveLogic()
	{
		int tmp[24][24];
		for (int i = 0; i < n; i++)
		{
			int c = -1, d = 0;
			for (int j = 0; j < n; j++)
			{
				if (a[i][j] == 0) continue; // 0이면 넘어가고
				if (d && a[i][j] == tmp[i][c]) tmp[i][c] *= 2, d = 0;
				else {
					tmp[i][++c] = a[i][j];
					d = 1;
				}
			}
			for (c++; c < n; c++) tmp[i][c] = 0;
		}
		memcpy(a, tmp, sizeof(a));
	}

	void GetMax()
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				res = max(res, a[i][j]);
			}
		}
	}
};

// 완전탐색
void go(Board b, int here)
{
	// 기저사례
	if (here == 5)
	{
		b.GetMax();
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		Board d = b;
		d.MoveLogic();
		go(d, here + 1);
		b.Rotate90(); // 네방향 탐색 구현
	}
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	Board bd;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			cin >> bd.a[i][j];
		}
	}

	go(bd, 0);
	cout << res << '\n';

	return 0;
}