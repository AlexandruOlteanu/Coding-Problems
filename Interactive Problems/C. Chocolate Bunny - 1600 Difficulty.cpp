/*
    Programmer : Alexandru Olteanu
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

int perm[maxn];
unordered_set<int> s;

int main()
{
    FastEverything
    HighPrecision

    int test = 1;
    // cin >> test;
    for (int tt = 1; tt <= test; ++tt) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << "! 1";
            cout << endl;
            return 0;
        }
        int i = 1, j = 2;
        int have = n - 1;
        while (have) {
            cout << "? " << i << " " << j << endl;
            int x, y;
            cin >> x;
            cout << "? " << j << " " << i << endl;
            cin >> y;
            if (x > y) {
                perm[i] = x;
                s.insert(x);
            }
            else {
                perm[j] = y;
                s.insert(y);
            }
            --have;
            while(perm[i] != 0) {
                ++i;
            }
            j = max(j, i + 1);
            while(perm[j] != 0) {
                ++j;
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; ++i) {
            if (perm[i] == 0) {
                for (int j = 1; j <= n; ++j) {
                    if (!s.count(j)) {
                        perm[i] = j;
                        j = n + 1;
                    }
                }
            }
            cout << perm[i] << " ";
        }
        cout << endl;



    }

    return 0;
}
