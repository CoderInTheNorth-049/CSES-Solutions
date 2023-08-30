#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
//--------------------------------------------------
#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
//------------------------------------------------------
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

// *(o_set.find_by_order(1)) -> 2nd smallest num
//  o_set.order_of_key(4) -> idx of 4 or no. of elements less than 4
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

using ll=long long;
#define ff first
#define ss second

struct HASH
{
    size_t operator()(const pair<ll,ll> &x)const{
        return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
    }
};

class solution
{
    public:
    solution()
    {
        
    }

    void solve()
    {
      int n;cin>>n;
      vector<ll> v(n);
      multiset<ll> st;
      for(int i=0;i<n;i++)
      {
        cin>>v[i];
        auto it=st.upper_bound(v[i]);
        
        if(it==st.end())
        {
            st.insert(v[i]);
        }
        else 
        {
            //bug(*it);
            st.erase(it);
            st.insert(v[i]);
        }
      }
      cout<<st.size()<<endl;
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