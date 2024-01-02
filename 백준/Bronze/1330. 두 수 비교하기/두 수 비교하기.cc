#include<bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;
	
	if (n > m) cout << ">" << '\n';
	else if (n == m) cout << "==" << '\n';
	else cout << "<" << '\n';

	return 0;
}