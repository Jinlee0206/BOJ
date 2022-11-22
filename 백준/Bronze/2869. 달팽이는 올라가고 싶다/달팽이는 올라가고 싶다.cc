#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int a, b, v, d = 1, dy;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> a >> b >> v;

    d += (v - a) / (a - b);

    if ((v - a) % (a - b) != 0)
    {
        d++;
    }

    if (a >= v)
    {
        cout << "1";
    }
    else cout << d << '\n';

    return 0;
}