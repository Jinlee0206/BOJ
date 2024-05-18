// BOJ - 1159 : 농구경기
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int n, alpha[26];
string ans = "";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		alpha[str[0] - 'a']++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] >= 5) ans += (char)(i + 'a');
	}
	if (ans == "") cout << "PREDAJA\n";
	else cout << ans << '\n';
	
	return 0;
}