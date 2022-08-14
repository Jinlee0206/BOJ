#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];

void DFS(int cnt, int idx)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; i++)
		{
			cout << arr[i] << " ";
		}
		cout << "\n";
		return;
	}
	else
	{	
		for (int i = idx; i <= n; i++)
		{
			arr[cnt] = i;
			DFS(cnt + 1, i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	DFS(0, 1);

	return 0;
}