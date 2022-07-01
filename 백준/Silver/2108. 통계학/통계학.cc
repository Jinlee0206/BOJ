#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double getAverage(vector<int> &vec, int size)
{
	int sum = 0;
	int avg = 0;
	for (int i = 0; i < size; i++)
	{
		sum += vec[i];
	}
	avg = round(sum / (double)size);

	return avg;
}

int median(vector<int> &vec) {
	return vec[vec.size() / 2];
}

int mode(vector<int>& vec2, int max, int min, bool isSecond)
{
	int most = -2147000000, most_val;

	for (int i = 0; i < 8001; i++)
	{
		if(vec2[i] == 0)
			continue;
		if (vec2[i] == most)
		{
			if (isSecond)
			{
				most_val = i - 4000;
				isSecond = false;
			}
		}
		if (vec2[i] > most)
		{
			most = vec2[i];
			most_val = i - 4000;
			isSecond = true;
		}
	}
	return most_val;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, min = 2147000000, max = -2147000000;
	cin >> n;

	vector<int> vec;
	vector<int> number(8001,0);

	bool isSecond = false;

	for (int i = 0; i < n; i++)
	{
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
		number[tmp+4000]++;
	}

	sort(vec.begin(), vec.end());

	cout << getAverage(vec, n) << "\n";
	cout << median(vec) << "\n";
	cout << mode(number, max, min, isSecond) << "\n";
	min = vec[0];
	max = vec[vec.size() - 1];
	cout << max - min << "\n";

	return 0;
}
