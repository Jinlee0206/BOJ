#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long sum = 0;

    for (int i = 0; i < 3; i++)
    {
        long long a;
        cin >> a;
        sum += a;
    }

    cout << sum << '\n';

    return 0;
}