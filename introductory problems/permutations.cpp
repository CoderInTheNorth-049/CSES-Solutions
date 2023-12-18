#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
        cout << 1 << endl;
    else if (n == 2 || n == 3)
        cout << "NO SOLUTION\n";
    else
    {
        int it1 = 1, it2 = 2;
        while (it2 <= n)
        {
            cout << it2 << " ";
            it2 += 2;
        }
        while (it1 <= n)
        {
            cout << it1 << " ";
            it1 += 2;
        }
    }
}

int32_t main()
{
    solve();
    return 0;
}