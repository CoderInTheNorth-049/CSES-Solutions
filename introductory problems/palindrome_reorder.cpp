#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<int> mp(26);
    for (int i = 0; i < s.size(); i++)
    {
        mp[s[i] - 'A'] += 1;
    }
    string ans = "";
    int ct = 0;
    char single = '@';

    for (int it = 0; it < 26; it++)
    {
        if (mp[it] & 1)
        {
            single = it + 'A';
            ct += 1;
        }
    }
    if (ct > 1)
    {
        cout << "NO SOLUTION\n";
    }
    else
    {
        for (int it = 0; it < 26; it += 1)
        {
            for (int i = 0; i < mp[it] / 2; i++)
            {
                ans += (it + 'A');
            }
        }

        string str = ans;
        if (single != '@')
        {
            ans += single;
        }
        reverse(str.begin(), str.end());
        ans += str;
        cout << ans << endl;
    }
}

int32_t main()
{
    solve();
    return 0;
}