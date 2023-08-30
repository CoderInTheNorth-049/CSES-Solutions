#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#define BUG
#ifdef BUG
#define bug(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}
#else
#define bug(...)
#endif

using ll=long long;
ll expo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
ll mminvprime(ll a, ll b) {return expo(a, b - 2, b);}
ll mod_add(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
ll mod_mul(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
ll mod_sub(ll a, ll b, ll m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
ll mod_div(ll a, ll b, ll m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}

int m1=1e9+7;
int m2=1e9+9;
int p=31;
vector<long long> p_pow1(1000007);
class solution
{

    long long substrhash(int l,int r,vector<long long> &hash)
    {
        if(l==0) return hash[r];
        
        ll val1=hash[r];
        ll val2=hash[l-1];
        return mod_mul(mod_sub(val1, val2, m1), mminvprime(p_pow1[l], m1), m1);
    }

    public:
    solution()
    {
        p_pow1[0]=1LL;
       
        for(int i=1;i<p_pow1.size();i++)
        {
            p_pow1[i]=(p_pow1[i-1]*p)%m1;
        }

    }

    void solve()
    {
       string s;cin>>s;
       vector<long long> hash1(s.size()),hash2(s.size());
       hash1[0]=(s[0]-'a');
       hash2[0]=(s[0]-'a');

        for(int i=1;i<s.size();i++)
        {
            hash1[i]=((s[i]-'a')*p_pow1[i])%m1;
            hash1[i] = (hash1[i] + (i > 0 ? hash1[i-1] : 0LL)) % m1;
        }
        for(int i=1;i<s.size();i++)
        {
            hash2[i]=((s[i]-'a')*p_pow1[i])%m2;   
            hash2[i] = (hash2[i] + (i > 0 ? hash2[i-1] : 0LL)) % m2;
        }
        vector<long long> ans;
        //bug(hash2[t.size()-1]);
        for(int i=0;i<s.size()-1;i++)
        {
            long long h1=substrhash(0,i,hash1);
            long long h2=substrhash(0,i,hash2);
            long long k1=substrhash(s.size()-1-i,s.size()-1,hash1);
            long long k2=substrhash(s.size()-1-i,s.size()-1,hash2);
            //bug(h);
           if(h1==k1) ans.push_back(i+1);
        }
        for(auto &it:ans) cout<<it<<" ";
        cout<<endl;
        
    }
};

int32_t main()
{

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    solution test;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    auto start = chrono::high_resolution_clock::now();
    long long t;
    t = 1;

    //cin >> t;

    cout << fixed << setprecision(9);
    // primes=siuu();
    while (t-- > 0)
    {
        test.solve();
    }
    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    time_taken *= 1e-9;

#ifndef WAQT
    bug(time_taken);
#endif

    return 0;
}