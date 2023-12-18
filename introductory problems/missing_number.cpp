#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> v(n + 1, -1);
    int x;
    for (int i = 1; i < n; i++)
    {
        cin >> x;
        v[x] = 1;
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] == -1)
        {
            cout << i << endl;
            return;
        }
    }
}

int32_t main()
{
    solve();
    return 0;
}