#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//--------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ll=long long;
#define ff first
#define ss second
//------------------------------------------------------
#define ordered_set tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define ordered_multiset tree<ll, null_type,less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update>

// *(o_set.find_by_order(1)) -> 2nd smallest num
//  o_set.order_of_key(4) -> idx of 4 or no. of elements less than 4
//  o_set.erase(o_set.find(2));
//  multi.erase(multi.upper_bound(val))
//======================================================================
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
//======================================================================




const int m1=1e9+7;
int p=31;
vector<ll> p_pow1;
vector<ll> modinv;
 
ll expo(ll a,ll b,ll mod)
{
    ll res=1;
    while(b>0)
    {
        if(b&1) res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1LL;
    }
    return res;
}
 
ll mminvprime(ll a,ll b)
{
    return expo(a,b-2,b);
}
 
ll mod_add(ll a,ll b, ll m)
{
    a=a%m;
    b=b%m;
    return ((a+b)%m +m)%m;
}
 
ll mod_mul(ll a,ll b, ll m)
{
    a=a%m;
    b=b%m;
    return ((a*b)%m +m)%m;
}
 
ll mod_sub(ll a,ll b, ll m)
{
    a=a%m;
    b=b%m;
    return ((a-b)%m +m)%m;
}
 
ll mod_div(ll a,ll b,ll m)
{
    a=a%m;
    b=b%m;
    return (mod_mul(a,mminvprime(b,m),m)+m)%m;
}
 

struct HASH
{
    size_t operator()(const pair<ll,ll> &x)const{
        return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
    }
};



class solution
{
    ll substrhash(int l,int r,vector<ll> &hash)
    {
        if(l==0) return hash[r];
        
        ll val1=hash[r];
        ll val2=hash[l-1];
        ll ans1=mod_mul(mod_sub(val1, val2, m1), modinv[l], m1);
 
        return ans1;
    }

    public:
    solution()
    {
        
    }

    void solve()
    {
      ll n,k;cin>>n>>k;
      vector<ll> v(n);
      vector<ll> ans(n-k+1);

      for(int i=0;i<n;i++) cin>>v[i];

      ordered_multiset mst;
      for(int i=0;i<k;i++)
      {
        mst.insert(v[i]);
      }
      for(int i=0;i<=n-k;i++)
      {
        ll idx=(k-1)/2;
        ll median=*mst.find_by_order(idx);
        ans[i]=median;
        if(i>n-k) break;
        mst.erase(mst.upper_bound(v[i]));
        mst.insert(v[i+k]);
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