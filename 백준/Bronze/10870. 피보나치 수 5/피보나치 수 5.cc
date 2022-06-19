#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int fibonacci(int a)
{
	if (a == 0) return 0;
	if (a == 1) return 1;
	
	else return fibonacci(a - 2) + fibonacci(a - 1);
}

int main()
{
	int N;
	cin >> N;

	cout << fibonacci(N) << "\n";

	return 0;
}