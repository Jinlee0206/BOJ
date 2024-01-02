#include<bits/stdc++.h>
using namespace std;

int n;
string str;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		if (n > 100) break;
		getline(cin, str);
		cout << str << "\n";
		n++;
	}
	
	return 0;
}