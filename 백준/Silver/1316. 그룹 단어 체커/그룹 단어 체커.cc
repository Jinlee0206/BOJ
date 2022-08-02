#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	int cnt = n;

	vector<char> vec;


	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;

		bool alphabet[26] = { false };
		bool flag = true;

		for (int j = 0; j < str.length(); j++)
		{
			int idx = str[j] - 'a';

			if (!alphabet[idx]) alphabet[idx] = true;
			else if (alphabet[idx] && (str[j] != str[j - 1]))
			{
				cnt -= 1;
				break;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}