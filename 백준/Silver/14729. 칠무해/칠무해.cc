#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n;
float f;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    priority_queue<float> pq;
    vector<float> v;

    for (int i = 0; i < n; i++)
    {
        cin >> f;
        if (pq.size() == 7)
        {
            pq.push(f); 
            pq.pop();
        }
        else pq.push(f);
    }
    
    while (pq.size())
    {
        v.push_back(pq.top());
        pq.pop();
    }

    reverse(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++)
    {
        cout << fixed;
        cout.precision(3);
        cout << v[i] << "\n";
    }
    
    return 0;
}