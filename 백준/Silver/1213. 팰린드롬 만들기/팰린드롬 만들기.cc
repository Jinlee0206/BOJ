#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int alphabet[200];
int flag = 0;
char mid;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string str, res;
	cin >> str;


	for (char a : str) alphabet[a]++;

	for (int i = 'Z'; i >= 'A'; i--)
	{
		if (alphabet[i])
		{
			if (alphabet[i] & 1)
			{
				mid = char(i);
				flag++;
				alphabet[i]--;
			}

			if (flag == 2) break;
			for (int j = 0; j < alphabet[i]; j += 2)
			{
				res = char(i) + res;
				res += char(i);
			}
		}
	}

	if (mid)res.insert(res.begin() + res.size() / 2, mid);
	if (flag == 2) cout << "I'm Sorry Hansoo" << "\n";
	else cout << res << "\n";

	return 0;
}