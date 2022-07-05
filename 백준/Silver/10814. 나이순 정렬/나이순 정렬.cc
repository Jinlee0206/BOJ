#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Data
{
	int age;
	string name;

	Data(int a, string b)
	{
		age = a;
		name = b;
	}
};

bool cmp(const Data& a, const Data& b)
{
	return a.age < b.age;
}

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
		vec.push_back(Data(a, s));
	}

	stable_sort(vec.begin(), vec.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		cout << vec[i].age << " " << vec[i].name << "\n";
	}

	return 0;
}