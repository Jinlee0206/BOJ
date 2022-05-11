#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str;
	cin >> str;

	// alphabet_idx : 알파벳 개수 만큼 선언
	int alphabet_idx[26];

	// 배열 -1로 초기화
	for (int i = 0; i < 26; i++)
	{
		alphabet_idx[i] = -1;
	}

	for (int i = 0; i < str.size(); i++)
	{
		// 처음 등장 하는 위치만 alphabet_idx 배열에 카운팅 
		if (alphabet_idx[str[i] - 97] != -1)
			continue; // continue문 아래에 있는 실행문을 실행하지 않고 다음 반복문을 진행하라
		else 
			alphabet_idx[str[i] - 97] = i;
	}

	// alphabet_idx 출력
	for (int i = 0; i < 26; i++)
		cout << alphabet_idx[i] << " ";

	return 0;
}