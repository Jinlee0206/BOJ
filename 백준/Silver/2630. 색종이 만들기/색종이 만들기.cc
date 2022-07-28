#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int map[129][129];
int w_cnt= 0, b_cnt = 0;

void div_conq(int x, int y, int n)
{
	int tmp_cnt = 0;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (map[i][j]) tmp_cnt++;
		}
	}

	if (!tmp_cnt) w_cnt++;
	else if (tmp_cnt == n * n) b_cnt++;
	else {
		div_conq(x, y, n / 2);
		div_conq(x, y + n / 2, n / 2);
		div_conq(x + n / 2, y, n / 2);
		div_conq(x + n / 2, y + n / 2, n / 2);
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	div_conq(0, 0, n);
 
	cout << w_cnt << "\n" << b_cnt << "\n";

	return 0;
}