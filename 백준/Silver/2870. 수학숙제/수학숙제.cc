#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> vec;

// 숫자 앞의 0을 제거 하는 Logic
void go(string& tmp)
{
	while (true)
	{
		if (tmp.size() && tmp.front() == '0') tmp.erase(tmp.begin());
		else break;
	}
	if (tmp.size() == 0) tmp = "0";
	vec.push_back(tmp);
	tmp = "";
}

// 문자열의 숫자 크기비교 커스텀 오퍼레이터
bool cmp(string a, string b)
{
	if (a.size() == b.size()) return a < b;
	return a.size() < b.size();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		string tmp = "";
		
		bool flag= false;

		for (int i = 0; i < str.size(); i++)
		{
			if (isdigit(str[i])) tmp += str[i];
			else if (tmp.size()) go(tmp);
		}
		// 숫자로 남고 끝났을 때 실행
		if (tmp.size()) go(tmp);
	}

	sort(vec.begin(), vec.end(), cmp);

	for (auto i : vec) cout << i << "\n";

	return 0;
}