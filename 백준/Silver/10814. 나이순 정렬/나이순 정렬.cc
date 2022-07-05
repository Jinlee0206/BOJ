#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int age;
	string name;
	int order;

	Data(int a, string b, int idx)
	{
		age = a;
		name = b;
		order = idx;
	}

	bool operator<(const Data& b) const
	{
		if (age == b.age) return order < b.order;
		else if (age != b.age) return age < b.age;
	}

};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<Data> vec;

	for (int i = 0; i < n; i++)
	{
		int a;
		string s;
		cin >> a >> s;
		vec.push_back(Data(a, s, i));
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++)
	{
		cout << vec[i].age << " " << vec[i].name << "\n";
	}

	return 0;
}