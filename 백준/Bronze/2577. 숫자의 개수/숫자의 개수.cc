#include <iostream>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	int arr_idx[10] = { 0, };

	int mul = 0;
	mul = A * B * C;

	while (mul != 0)
	{
		arr_idx[mul % 10]++;
		mul /= 10;
	}

	for (int i = 0; i < 10; i++)
	{
		cout << arr_idx[i] << "\n";
	}

	return 0;
}