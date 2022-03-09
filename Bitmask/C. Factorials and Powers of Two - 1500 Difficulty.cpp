/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1646/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
// #pragma GCC optimize("Ofast");
// #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt")
// #pragma GCC target("abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize(3)
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// Useful
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define FastEverything  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define HighPrecision cout<<fixed<<setprecision(17);
typedef long long ll;
typedef pair<int,int> pii;
ll const mod=1000000007LL;
ll const mod2 = 100000000LL;
ll const md=998244353LL;
ll mypowr(ll a,ll b, ll mod1) {ll res=1;if(b<0)b=0;a%=mod1; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod1;a=a*a%mod1;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()

// ifstream in("input.txt");
// ofstream out("output.txt");
// #define cin in
// #define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e5 + 2;

ll fact[50];
map<long long, long long> m;

vector<pair<ll, int>> elements;
vector<ll> p;

int main()
{
    FastEverything
    HighPrecision

    fact[1] = 1;
    for (ll i = 2; i <= 20; ++i) {
        fact[i] = fact[i - 1] * i;
    }

    int u = (1 << 15);
    for (int i = 1; i < u; ++i) {
        int x = i;
        int sum = 1;
        long long nr = 0;
        ll s = 0;
        while (x) {
            if (x % 2) {
                s += fact[sum];
                ++nr;
            }
            x /= 2;
            ++sum;
        }
        if (m[s] == 0) {
            m[s] = nr;
        }
        m[s] = min(m[s], nr);
    }
    
    for (auto u : m) {
        elements.pb({u.fi, u.se});
    }

    int test = 1;
    cin >> test;
    for (int tt = 1; tt <= test; ++tt) {
        ll n;
        cin >> n;
        int cnt = inf;
        for (auto u : elements) {
            ll x = n;
            int sum = 0;
            x -= u.fi;
            if (x < 0)continue;
            sum += u.se;
            sum += __builtin_popcountll(x);
            cnt = min(cnt, sum);
        }
        cnt = min(cnt, __builtin_popcountll(n));
        cout << cnt << '\n';

    }


    return 0;
}
