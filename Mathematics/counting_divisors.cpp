#include <bits/stdc++.h>
using namespace std;

int f(int n)
{
    int ans = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans += 1;
            if (n / i != i)
                ans += 1;
        }
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << f(n) << endl;
    }
}