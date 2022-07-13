#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<pair<int, int> > vec;
	vector<int> vec2;

	for (int i = 1; i <= n; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back({a, b});
		vec2.push_back(0);
	}
	
	for(int i = 0; i<n; i++)
	{
		int res = 1;
		for(int j= 0; j < n; j++)
		{
			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second) res++;	  	
		}
		vec2[i] = res;
	}
	
	for(int i = 0; i<n; i++)
	{
		cout << vec2[i] << " ";
	}

	return 0;
}