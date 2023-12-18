#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    long long curr = 5, ans = 0;
    while (curr <= n)
    {
        ans += n / curr;
        curr *= 5;
    }
    cout << ans << endl;
}

int32_t main()
{
    solve();
    return 0;
}