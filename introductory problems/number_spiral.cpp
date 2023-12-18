#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long c, r;
    cin >> r >> c;
    long long diag = max(c, r);
    diag = diag * diag - (diag - 1);
    if (r == c)
    {
    }
    else if (c > r)
    {
        if (c & 1)
        {
            diag += (c - r);
        }
        else
            diag -= (c - r);
    }
    else
    {
        if (r & 1)
        {
            diag -= (r - c);
        }
        else
            diag += (r - c);
    }
    cout << diag << endl;
}

int32_t main()
{
    long long t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
    return 0;
}