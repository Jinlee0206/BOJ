#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	time_t timer = time(nullptr);
	struct tm* t = localtime(&timer);

	printf("%d-%02d-%02d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	return 0;
}