#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int n, m;
vector<int> vec;
vector<int> res;
int ch[8] = { false };
set<vector<int>> s;

void EliminateRedundancy()
{
	s.insert(res);

	return;
}

//void Print()
//{
//	for (int i = 0; i < m; i++)
//	{
//		cout << res[i] << " ";
//	}
//	cout << "\n";
//	return;
//}

void DFS(int lv)
{
	if (lv == m)
	{
		EliminateRedundancy();
		//Print();
		return;
	}
	else
	{
		for (int i = 0; i < vec.size(); i++)
		{
			if (ch[i]) continue;
			ch[i] = true;
			res.push_back(vec[i]);
			DFS(lv + 1);
			ch[i] = false;
			res.pop_back();
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
		int a;
		cin >> a;
		vec.push_back(a);
	}

	// 입력 vector 컨테이너 중복 방지는 이 경우 해당되지 않음
	/*sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());*/

	DFS(0);

	for (auto vector : s) {
		for (auto temp : vector)
		{
			cout << temp << " ";
		}
		cout << "\n";
	}

	return 0;
}