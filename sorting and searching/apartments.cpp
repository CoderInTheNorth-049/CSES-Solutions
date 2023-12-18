#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int it1 = 0, it2 = 0;
    long long ans = 0;
    while (it1 < n && it2 < m)
    {
        if (abs(a[it1] - b[it2]) <= k)
        {
            it1 += 1;
            it2 += 1;
            ans += 1;
        }
        else if (a[it1] < b[it2])
        {
            it1 += 1;
        }
        else
            it2 += 1;
    }
    cout << ans << endl;
}

int32_t main()
{
    solve();
    return 0;
}