#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, cnt = 0, p1 = 0, p2 = 0;
	cin >> n;
	p2 = n-1;
	
	vector<int> vec;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}

	cin >> m;


	// 이중 for문 
	// 시간복잡도 O(n^2)
	/*for (int i = 0; i < n ; i++)
	{
		for (int j = n - 1; j > i; j--)
		{
			if (vec[i] + vec[j] == m) cnt++;
		}
	}*/

	// 투포인터 알고리즘
	// 시간 복잡도 O(n)
	// 오름차순 정렬 후 포인터 두개를 이동시켜가며 두 수의 합(타겟 값)을 찾는다
	sort(vec.begin(), vec.end());
	
	while (p1 < p2)
	{
		if (vec[p1] + vec[p2] == m)
		{
			cnt++;
			p2--;
		}
		else if (vec[p1] + vec[p2] > m)
		{
			p2--;
		}
		else
		{
			p1++;
		}
	}

	cout << cnt << "\n";

	return 0;
}