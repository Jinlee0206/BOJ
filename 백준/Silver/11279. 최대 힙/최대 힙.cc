#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int> pq;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		
		if (a != 0)
		{
			pq.push(a);
		}
		else
		{
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << "0" << "\n";
		}
	}

	return 0;
}