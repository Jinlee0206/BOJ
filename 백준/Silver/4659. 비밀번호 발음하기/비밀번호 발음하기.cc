#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (true)
	{
		string str;
		cin >> str;

		if (str == "end") return 0;

		vector<int> vec;
		bool isAcceptable = true; // 비밀번호 가능 여부 체크
		bool exist = false; // 모음 존재
		int vowel = 0, constants = 0; // 자음, 모음 수 체크

		for (int i = 0; i < str.size(); i++)
		{
			// 모음 체크
			if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
			{
				exist = true;
				vowel++;
				constants = 0;
			}
			else
			{
				constants++;
				vowel = 0;
			}

			// 3개 이상 연속 체크
			if (constants == 3 || vowel == 3)
			{
				isAcceptable = false;
				break;
			}

			// 같은 글자 연속 여부 확인
			// 범위 지정 이후 index i와 i+1 이용해서 검사
			if (i < str.size() - 1)
			{
				if (str[i] == 'e' && str[i + 1] == 'e' || str[i] == 'o' && str[i + 1] == 'o') continue;
				else if (str[i] == str[i + 1])
				{
					isAcceptable = false;
					break;
				}
			}
	
		}

		if (exist && isAcceptable) cout << "<" << str << "> is acceptable." << "\n";
		else cout << "<" << str << "> is not acceptable." << "\n";

	}

	return 0;
}