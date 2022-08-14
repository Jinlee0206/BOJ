#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];

void DFS(int cnt)
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
		for (int i = 1; i <= n; i++)
		{
			arr[cnt] = i;
			DFS(cnt+1);
		}
	}
}

int main()
{
	cin >> n >> m;

	DFS(0);

	return 0;
}