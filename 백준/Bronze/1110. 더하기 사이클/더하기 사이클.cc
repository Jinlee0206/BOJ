#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cycle(int n)
{
	int length = 0;
	int original = n;

	while (1)
	{
		int first = n / 10;
		int second = n % 10;

		n = (second * 10) + ((first + second) % 10);
		length++;

		if (n == original)
			break;
	}

	return length;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	cout << cycle(n);

	

	return 0;
}