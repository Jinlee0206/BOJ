#include <iostream>
#include <string>

using namespace std;

int arr[26], cnt =0;

int main() 
{
	string str;
	cin >> str;

	int max = 0, maxIndex = 0;

	for (int i = 0; i < str.size(); i++)
	{
		if ((int)str[i] < 97) arr[(int)str[i] - 65]++;
		else arr[(int)str[i] - 97]++;
	}

	for (int i = 0; i < 26; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxIndex = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (max == arr[i]) cnt++;
	}

	if (cnt > 1)cout << "?";
	else cout << (char)(maxIndex + 65);

	return 0;
}