#include <iostream>
#include <string>

using namespace std;

int main()
{
	char input;

	cin >> input;

	// 아스키 코드로의 형 변환
	int ans = (int)input;

	cout << ans << "\n";

	return 0;
}