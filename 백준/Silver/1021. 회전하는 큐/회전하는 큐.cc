#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m, cnt = 0, idx = 0;
	cin >> n >> m;

	deque<int> deq;

	for (int i = 0; i < n; i++)
	{
		deq.push_back(i+1);
	}

	while (m--)
	{
		int num;
		cin >> num;

		for (int i = 0; i < deq.size(); i++)
		{
			if (deq[i] == num)
			{
				idx = i;
				break;
			}
		}

		if (idx < deq.size() - idx)
		{
			while (1)
			{
				if (deq.front() == num)
				{
					deq.pop_front();
					break;
				}
				++cnt;
				deq.push_back(deq.front());
				deq.pop_front();
			}
		}
		else
		{
			while (1)
			{
				if (deq.front() == num)
				{
					deq.pop_front();
					break;
				}
				++cnt;
				deq.push_front(deq.back());
				deq.pop_back();
			}
		}

	}

	cout << cnt << "\n";


	return 0;
}