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

	queue<int> q;

	for (int i = 0; i < n; i++)
	{
		q.push(i+1);
	}

	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front() << "\n";

	return 0;
}