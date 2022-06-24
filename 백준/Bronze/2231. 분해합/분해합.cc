#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fx(int x)
{
	int k, sum;
	bool flag = false;
	for (int i = 1; i < x; i++)
	{
		k = i, sum = i;

		while (k != 0)
		{
			sum += k % 10;
			k /= 10;
		}

		if (sum == x) {
			cout << i << endl;
			flag = true;
			break;
		}
	}
	if (flag == false) cout << "0" << endl;
}

int main()
{
	int N;

	cin >> N;

	fx(N);

	return 0;
}
