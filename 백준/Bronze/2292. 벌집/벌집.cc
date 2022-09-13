#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	int end_of_hex = 1, result = 1, cnt = 6;

	while (true)
	{
		if (end_of_hex >= n) break;
		end_of_hex += cnt;
		cnt += 6;
		result++;
	}

	cout << result << "\n";

	return 0;
}