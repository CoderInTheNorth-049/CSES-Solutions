#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    int ans = 0, ct = 1;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == s[i - 1])
            ct += 1;
        else
        {
            ans = max(ans, ct);
            ct = 1;
        }
    }
    ans = max(ans, ct);
    cout << ans << endl;
}

int32_t main()
{
    solve();
    return 0;
}