#include <bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n & 1)
        {
            n = n * 3 + 1;
        }
        else
            n /= 2;
        cout << n << " ";
    }
    cout << endl;
}

int32_t main()
{
    solve();
    return 0;
}