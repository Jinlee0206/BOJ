#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int factorial(int a)
{
	if (a == 0) return 1;
	if (a <= 1) return 1;
	else return a * factorial(a - 1);
}

int main()
{
	int N, val;
	cin >> N;

	cout << factorial(N) << "\n";

	return 0;
}