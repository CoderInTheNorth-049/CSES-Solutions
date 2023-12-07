#include <bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;

int f(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            result = (1ll * result * a) % mod;
        }
        a = (1ll * a * a) % mod;
        b >>= 1;
    }
    return result;
}
int main()
{

    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        cout << f(a, b) << endl;
    }
}