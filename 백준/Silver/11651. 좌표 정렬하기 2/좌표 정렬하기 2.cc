#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data {
	int first;
	int second;

	Data(int a, int b)
	{
		first = a;
		second = b;
	}

	bool operator<(const Data& b) const {
		if (second != b.second) return second < b.second;
		if (first != b.first) return first < b.first;
	}
};

int main()
{
	int N;
	cin >> N;

	vector<Data> vec;

	for (int i = 0; i < N; i++)
	{
		int a, b;
		cin >> a >> b;
		vec.push_back(Data(a, b));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < N; i++)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}


	return 0;
}