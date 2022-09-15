#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int alphabet[26];

int main()
{
	string str;
	cin >> str;


	for (int i = 0; i < str.size(); i++)
	{
		int tmp = str[i] - 97;
		alphabet[tmp]++;
	}

	for (auto i : alphabet) cout << i << " ";

	return 0;
}