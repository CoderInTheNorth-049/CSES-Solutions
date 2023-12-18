#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<long long> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    long long ans = 0;
    for (int i = 1; i < n; i++)
    {
        if (v[i] < v[i - 1])
        {
            ans += (v[i - 1] - v[i]);
            v[i] = v[i - 1];
        }
    }
    cout << ans << endl;
}

int32_t main()
{
    solve();
    return 0;
}