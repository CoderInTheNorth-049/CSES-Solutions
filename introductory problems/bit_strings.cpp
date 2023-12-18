#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long M = 1e9 + 7;

    long long ans = 1;
    long long x = 2;
    while (n > 0)
    {
        if (n & 1)
        {
            ans = (ans * x) % M;
        }
        n >>= 1;
        x = (x * x) % M;
    }
    cout << ans << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}