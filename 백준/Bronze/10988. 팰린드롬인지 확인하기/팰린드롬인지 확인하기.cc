#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	bool palindrome = true;
	cin >> str;

	for (int i = 0; i < str.size() / 2; i++)
	{
		if (str[i] != str[str.size() - 1 - i])
		{
			palindrome = false;
			break;
		}
	}

	cout << palindrome << "\n";

	return 0;
}