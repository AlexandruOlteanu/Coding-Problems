/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1644/problem/D
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

vector<pii> v;
map<int, int> taken_line, taken_col;

int main()
{
    FastEverything
    HighPrecision

    int test = 1;
    cin >> test;
    for (int tt = 1; tt <= test; ++tt) {
        ll n, m, k, q;
        cin >> n >> m >> k >> q;
        v.clear();
        for (int i = 1; i <= q; ++i) {
            int x, y;
            cin >> x >> y;
            v.pb({x, y});
        }
        taken_line.clear();
        taken_col.clear();
        int sz = v.size() - 1;
        ll cnt = 1;
        ll c = 0, l = 0;
        for (int i = sz; i >= 0; --i) {
            bool ok = 1;
            auto u = v[i];
            if (taken_line[u.fi] && taken_col[u.se]) {
                ok = 0;
            }
            if (c == m) {
                ok = 0;
            }
            if (l == n) {
                ok = 0;
            }
            if (ok) {
                cnt *= k;
                cnt %= md;
            }
            if (!taken_line[u.fi]) {
                ++l;
            }
            if (!taken_col[u.se]) {
                ++c;
            }
            taken_line[u.fi] = 1;
            taken_col[u.se] = 1;
        }
        cout << cnt << '\n';

    }

    return 0;
}
