#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int a[101][101], n, y,x, answer = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> y >> x;

        for (int j = y; j < y + 10; j++)
        {
            for (int l = x; l < x + 10; l++)
            {
                if (a[j][l] == 1) continue;
                a[j][l] = 1;
                answer++;
            }
        }
    }
    
    cout << answer << '\n';

    return 0;
}