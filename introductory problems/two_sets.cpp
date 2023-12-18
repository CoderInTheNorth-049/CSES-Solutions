#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    if (((n & 1) && ((n + 1) / 2) % 2 == 1) || (!(n & 1) && (n / 2) % 2 == 1))
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        long long sum = (n * (n + 1)) / 2;
        sum /= 2;
        set<long long> s1, s2;
        for (long long i = 1; i <= n; i++)
            s1.insert(i);
        for (long long i = n; i >= 1; i--)
        {
            if (sum - i >= 0)
            {
                s2.insert(i);
                s1.erase(i);
                sum -= i;
            }
        }
        cout << s1.size() << endl;
        for (auto &it : s1)
            cout << it << " ";
        cout << endl;
        cout << s2.size() << endl;
        for (auto &it : s2)
            cout << it << " ";
        cout << endl;
    }
}

int32_t main()
{
    solve();
    return 0;
}