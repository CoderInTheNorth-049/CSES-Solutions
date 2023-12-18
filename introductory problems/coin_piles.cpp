#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long x, y;
    cin >> x >> y;
    long long mx = max(x, y);
    long long mn = min(x, y);
    if ((2 * mx - mn) % 3 == 0 && mx <= 2 * mn)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main()
{
    long long t;
    t = 1;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}