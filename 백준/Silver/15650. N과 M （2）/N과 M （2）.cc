#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
bool visited[8] = { false };
int arr[8];

void Print()
{
	for (int i = 0; i < n; i++)
	{
		if (visited[i])
		{
			cout << arr[i] << " ";
		}
	}
	cout << "\n";
	return;
}

// 조합의 경우 중복되면 안되므로 시작점 (idx)가 필요하다
// 다음 cnt로 넘어갈 때 이전의 작은 숫자를 건드리지 않도록 하기 위해 idx 필요
void DFS(int cnt, int idx)
{
	if (cnt == m)
	{
		Print();
		return;
	}

	else
	{
		for (int i = idx; i < n; i++)
		{
			if (visited[i]) continue;

			visited[i] = true;
			DFS(cnt + 1, i + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		arr[i] = i+1;
		visited[i] = false;
	}

	DFS(0, 0);

	return 0;
}