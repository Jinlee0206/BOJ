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
	getline(cin,str);

	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ') continue;
		if ((str[i] >= 65 && str[i] <= 77) || (str[i] >= 97 && str[i] <= 109)) str[i] += 13;
		else if ((str[i] > 77 && str[i] <= 90) || (str[i] > 109 && str[i] <= 122)) str[i] -= 13;
	}

	cout << str << "\n";

	return 0;
}