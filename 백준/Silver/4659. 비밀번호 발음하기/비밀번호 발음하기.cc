#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isVowel(int idx)
{
	return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		string str;
		cin >> str;

		if (str == "end") break;

		bool flag = false, is_include_v = false;
		int constant = 0, vowel= 0, prev = -1;

		for (int i = 0; i < str.size(); i++)
		{
			int idx = str[i];
			if (isVowel(idx))
			{
				vowel++;
				constant = 0;
				is_include_v = true;
			}
			else
			{
				constant++;
				vowel = 0;
			}

			if (vowel == 3 || constant == 3) flag = 1;

			if (i >= 1 && (prev == idx) && (idx != 'e' && idx != 'o')) flag = 1;

			prev = idx;
		}

		if (!is_include_v) flag = 1;

		if (flag) cout << "<" << str << "> is not acceptable.\n";
		else cout << "<" << str << "> is acceptable.\n";
	}
	
	return 0;
}