/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1642/problem/D
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
const ll maxn = 5e4 + 2;

int a[maxn];

set<int> s;
vector<int> v, v1;
vector<pii> sol;
vector<int> final_sol;

int main()
{
    FastEverything
    HighPrecision

    int test = 1;
    cin >> test;
    for (int tt = 1; tt <= test; ++tt) {
        int n;
        cin >> n;
        s.clear();
        v.clear();
        sol.clear();
        final_sol.clear();
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            if (s.count(a[i])) {
                s.erase(a[i]);
            }
            else {
                s.insert(a[i]);
            }
        }
        if (!s.empty()) {
            cout << "-1\n";
            continue;
        }
        v.clear();
        int pos = 0;
        for (int i = 1; i <= n; ++i) {
            v.pb(a[i]);
        }
        while (!v.empty()) {
            for (int i = 1; i < v.size(); ++i) {
                if (v[i] == v[0]) {
                    bool ok = 1;
                    if (i % 2 == 0) {
                        ok = 0;
                    }
                    else {
                        for (int j = 0; j <= i / 2 && ok; ++j) {
                            if (v[j] != v[j + i / 2 + 1]) {
                                ok = 0;
                            }
                        }
                    }
                    if (ok) {
                        pos += i + 1;
                        v1.clear();
                        for (int j = i + 1; j < v.size(); ++j) {
                            v1.pb(v[j]);
                        }
                        v = v1;
                        final_sol.pb(i + 1);
                    }
                    else {
                        pos += i + 1;
                        v1.clear();
                        for (int j = i - 1; j >= 1; --j) {
                            v1.pb(v[j]);
                        }
                        for (int j = i + 1; j <= 2 * i - 1; ++j) {
                            sol.pb({pos, v[j - i]});
                            ++pos;
                        }
                        final_sol.pb(2 * i);
                        for (int j = i + 1; j < v.size(); ++j) {
                            v1.pb(v[j]);
                        }
                        v = v1;
                    }
                    break;
                }
            }
        }
        int sz = sol.size();
        cout << sz << '\n';
        for (auto u : sol) {
            cout << u.fi << " " << u.se << '\n';
        }
        sz = final_sol.size();
        cout << sz << '\n';
        for (auto u : final_sol) {
            cout << u << " ";
        }
        cout << '\n';
    }

    return 0;
}
