#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int n, a[1030];
vector<int> res[14];

//vector<int> adj[1004];
//int visited[1004];

/*void postOrder(int here)
{
	if (visited[here] == 0)
	{
		if (adj[here].size() == 1) postOrder(adj[here][0]);
		if (adj[here].size() == 2)
		{
			postOrder(adj[here][0]);
			postOrder(adj[here][1]);
		}
		visited[here] = 1;
		cout << here << " ";
	}
}

void preOrder(int here)
{
	if (visited[here] == 0)
	{
		visited[here] = 1;
		cout << here << " ";

		if (adj[here].size() == 1) preOrder(adj[here][0]);
		if (adj[here].size() == 2)
		{
			preOrder(adj[here][0]);
			preOrder(adj[here][1]);
		}
	}
}

void inOrder(int here)
{
	if (visited[here] == 0)
	{
		if (adj[here].size() == 1)
		{
			inOrder(adj[here][0]);
			visited[here] = 1;
			cout << here << " ";
		}
		else if (adj[here].size() == 2)
		{
			inOrder(adj[here][0]);
			visited[here] = 1;
			cout << here << " ";
			inOrder(adj[here][1]);
		}
		else
		{
			visited[here] = 1;
			cout << here << " ";
		}
	}
}*/

void go(int start, int end, int level)
{
	if (start > end) return;
	if (start == end)
	{
		res[level].push_back(a[start]);
		return;
	}
	int mid = (start + end) / 2;
	res[level].push_back(a[mid]);
	go(start, mid - 1, level + 1);
	go(mid + 1, end, level + 1);
	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	/*adj[3].push_back(6);
	adj[3].push_back(2);
	adj[6].push_back(1);
	adj[6].push_back(4);
	adj[2].push_back(5);
	adj[2].push_back(7);*/

	/*int root = 3;

	cout << "\n 트리순회 : postOrder \n";
	postOrder(root); memset(visited, 0, sizeof(visited));
	cout << "\n 트리순회 : preOrder \n";
	preOrder(root); memset(visited, 0, sizeof(visited));
	cout << "\n 트리순회 : inOrder \n";
	inOrder(root);*/

	cin >> n;
	int _end = (int)pow(2, n) - 1;

	for (int i = 0; i < _end; i++)
	{
		cin >> a[i];
	}

	go(0, _end, 1);

	for (int i = 1; i<= n; i++)
	{
		for (int j = 0; j < res[i].size(); j++)
		{
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}

	return 0;
}