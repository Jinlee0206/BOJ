#include <iostream>

using namespace std;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int T;

	cin >> T;

	for (int i = 1; i <= T; i++)
	{
		for (int j=1; j<=i; j++)
			cout << "*";

		cout << "\n";
	}

	return 0;
}
