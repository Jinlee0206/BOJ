#include <iostream>
#include <vector>
#include <algorithm>

typedef long long ll;
using namespace std;

ll a, b, c;

ll func(ll x, ll y)
{
	//cout << x << " : " << y << "\n";

	// 어떤 수의 0 제곱은 1
	if (y == 0) return 1;
	if (y == 1) return x % c;

	ll res = func(x, y/2);
	res = (res * res) % c;
	
	// 모듈러 연산 곱셈
	// ((a % c) * (a % c)) % c = (a * a) % c

	//cout << "res : " << res << "\n";

	// 승수가 홀수일 때와 짝수일 때
	if (y % 2) res = (res * x) % c;
	return res;


}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> a >> b >> c;

	cout << func(a, b) << "\n";

	return 0;
}