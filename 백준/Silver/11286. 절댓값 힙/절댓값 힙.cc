#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(int a, int b)
	{
		if (abs(a) == abs(b))
		{
			if (a > b) return a > b;
			else return b < a;
		}
		return abs(a) > abs(b);
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, cmp> pq;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		
		if (a == 0)
		{
			if (!pq.empty())
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << "0" << "\n";
		}
		else pq.push(a);
	}

	return 0;
}