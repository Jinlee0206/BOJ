#include <iostream>

using namespace std;

int main()
{
	int N, sum = 0;

	cin >> N;

	char input;

	for (int i = 0; i < N; i++)
	{
		cin >> input;
		
		/*
			char c = '1';
			int n = c - '0'; // n = 1, '0' 은 숫자 48 
		*/

		sum += input - '0';
	}

	cout << sum << "\n";

	return 0;
}