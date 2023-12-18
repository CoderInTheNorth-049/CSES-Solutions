#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        cout << max(0LL, (i * i * (i * i - 1)) / 2 - (i - 1) * (i - 2) * 4) << endl;
    }
}

int32_t main()
{
    solve();
    return 0;
}