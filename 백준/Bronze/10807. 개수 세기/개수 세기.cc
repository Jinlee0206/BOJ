#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int n, a, v;
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a;
        mp[a]++;
    }

    cin >> v;

    cout << mp[v] << '\n';

    return 0;
}