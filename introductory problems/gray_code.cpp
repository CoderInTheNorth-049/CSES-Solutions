#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    int sz = 1 << n;
    vector<string> code;
    code.push_back("0");
    code.push_back("1");
    for (int i = 2; i <= n; i++)
    {
        vector<string> temp = code;
        reverse(temp.begin(), temp.end());
        for (int i = 0; i < code.size(); i++)
            code[i] = "0" + code[i];
        for (int i = 0; i < temp.size(); i++)
        {
            temp[i] = "1" + temp[i];
            code.push_back(temp[i]);
        }
    }
    for (auto &it : code)
        cout << it << endl;
}

int32_t main()
{
    solve();
    return 0;
}