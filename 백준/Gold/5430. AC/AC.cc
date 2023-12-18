// BOJ-5430 : AC
#include<bits/stdc++.h>
using namespace std;

int t;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> t;

	while (t--)
	{
		string p, s;
		int n, tmp = 0;

		cin >> p >> n >> s;

		deque<int> dq;

		for (int i = 1; i < s.size() - 1; i++)
		{
			if (s[i] != ',')
			{
				tmp = tmp * 10 + (s[i] - '0');
			}
			else
			{
				dq.push_back(tmp);
				tmp = 0;
			}
		}
		if(tmp != 0) dq.push_back(tmp);

		bool isRev = false, isError = false;


		for (int i = 0; i < p.size(); i++)
		{
			if (p[i] == 'R')
			{
				if (isRev) isRev = false;
				else isRev = true;
			}
			else if (p[i] == 'D')
			{
				if (dq.empty())
				{
					isError = true;
					break;
				}

				if (isRev == true) dq.pop_back();
				else if (isRev == false) dq.pop_front();
			}
		}

		if (!isError)
		{
			cout << "[";
			if (!isRev)
			{
				for (int i = 0; i < dq.size(); i++)
				{
					if (i == (dq.size() - 1)) cout << dq[i];
					else cout << dq[i] << ",";
				}
			}
			else
			{
				for (int i = dq.size() - 1; i >= 0; i--)
				{
					if (i == 0) cout << dq[i];
					else cout << dq[i] << ",";
				}
			}
			cout << "]\n";
		}
		else cout << "error" << '\n';
	}

	return 0;
}