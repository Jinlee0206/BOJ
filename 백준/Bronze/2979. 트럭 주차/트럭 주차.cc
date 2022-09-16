#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fare[101];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int a, b, c, res =0;
	cin >> a >> b >> c;

	for (int i = 0; i < 3; i++)
	{
		int start, end;
		cin >> start >> end;
		
		for (int j = start; j < end; j++) fare[j]++;
	}

	for (int i = 1; i < 100; i++)
	{
		if (fare[i] == 1) res += a;
		else if (fare[i] == 2) res += b * 2;
		else if (fare[i] == 3) res += c * 3;
	}

	cout << res << "\n";

	return 0;
}