#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int first;
	int second;

	Data(int x, int y)
	{
		first = x;
		second = y;
	}

	bool operator<(const Data &b) const
	{
		if(first != b.first) return first < b.first;
		if(second != b.second) return second < b.second;
	}
};


int main()
{
	int N;
	cin >> N;

	vector<Data> a;

	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		a.push_back(Data(x, y));
	}

	sort(a.begin(), a.end());

	for (int i = 0; i < N; i++)
	{
		cout << a[i].first << " " << a[i].second << "\n";
	}

	return 0;
}