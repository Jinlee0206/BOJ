#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	double n, s1, s2;

	// C++-Style 소수 6자리까지 고정
	cout << fixed;
	cout.precision(6);
	
	cin >> n;

	double pi = M_PI;

	s1 = pow(n, 2) * M_PI;
	s2 = n * n * 2;

	// C-Style 소수 6자리 고정
	//printf("%.6f\n", s1);
	//printf("%.6f\n", s2);

	cout << s1 << "\n";
	cout << s2 << "\n";

	return 0;
}