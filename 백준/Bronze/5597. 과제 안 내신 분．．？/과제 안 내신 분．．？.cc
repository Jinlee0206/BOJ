#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool> vec(31);
int n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 0; i < 28; i++)
    {
        cin >> n;
        vec[n] = true;
    }

    for (int i = 1; i <= 30; i++)
    {
        if (!vec[i]) cout << i << '\n';
    }

    return 0;
}