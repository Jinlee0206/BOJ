#include <bits/stdc++.h>

using namespace std;

int solution(string my_string, string is_suffix) {
    reverse(my_string.begin(), my_string.end());
    reverse(is_suffix.begin(), is_suffix.end());
    return my_string.find(is_suffix) == 0;
}