#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

void hanoi(int n, int start, int via, int dest)
{
	if (n == 1) cout << start << " " << dest << "\n";
	else
	{
		hanoi(n - 1, start, dest, via);
		cout << start << " " << dest << "\n";
		hanoi(n - 1, via, start, dest);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cout << (int)pow(2, n) - 1 << endl;
	hanoi(n, 1, 2, 3);

	return 0;
}