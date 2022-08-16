#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// erase()와 lower_bound()를 이용한 방법
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<long long> vec;
	vector<long long> erased_vec;

	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		vec.push_back(a);
		erased_vec.push_back(a);
	}

	sort(erased_vec.begin(), erased_vec.end());
	erased_vec.erase(unique(erased_vec.begin(), erased_vec.end()), erased_vec.end());

	for (int i = 0; i < n; i++)
	{
		cout << lower_bound(erased_vec.begin(), erased_vec.end(), vec[i]) - erased_vec.begin() << " ";
	}


	return 0;
}

// STL_map을 이용한 해시 테이블 방법
/*int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	long long tmp;
	vector<long long> vec;
	vector<long long> sorted_vec;
	map<long long, int> m_map;

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		vec.push_back(tmp);
		sorted_vec.push_back(tmp);
	}

	sort(sorted_vec.begin(), sorted_vec.end());

	tmp = sorted_vec[0];
	int cnt = 0;

	m_map.insert(make_pair(sorted_vec[0], cnt));

	for (int i = 0; i < n; i++)
	{
		if (tmp != sorted_vec[i])
		{
			cnt++;
			m_map.insert(make_pair(sorted_vec[i], cnt));
			tmp = sorted_vec[i];
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << m_map[vec[i]] << " ";
	}

	return 0;
}*/