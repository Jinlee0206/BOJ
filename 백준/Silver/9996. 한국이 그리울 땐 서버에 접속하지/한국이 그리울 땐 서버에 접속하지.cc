#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

string str, prefix, suffix;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	cin >> str;

	int pos = str.find('*');

	prefix = str.substr(0, pos);
	// substr() 하나의 문자만 넣으면 문자열 끝까지 추출한다
	suffix = str.substr(pos + 1);
	
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		// 앞 또는 뒤 하나만 입력하여서 DA가 되는 경우 방지
		if (prefix.size() + suffix.size() > s.size())
		{
			cout << "NE" << "\n";
		}
		else
		{
			if (prefix == s.substr(0, prefix.size()) && suffix == s.substr(s.size() - suffix.size())) cout << "DA" << "\n";
			else cout << "NE" << "\n";
		}
	}

	return 0;
}