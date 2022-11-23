#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[10][10], mx = -2147000000, y, x;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            cin >> a[i][j];
            if (mx < a[i][j])
            {
                mx = a[i][j];
                y = i;
                x = j;
            }
        }
    }

    cout << mx << '\n' << y << " " << x;

    return 0;
}