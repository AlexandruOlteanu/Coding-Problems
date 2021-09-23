/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1446/problem/B
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
// #pragma GCC optimize("Ofast")
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
typedef pair<ll,ll> pll;
ll const mod=1000000007LL;
ll const mod2 = 100000000LL;
ll const md=998244353LL;
ll mypowr(ll a,ll b, ll mod1) {ll res=1;if(b<0)b=0;a%=mod1; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod1;a=a*a%mod1;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ifstream in("input.txt");
ofstream out("output.txt");
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()

//#define cin in
//#define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 5e3 + 2;

ll dp[maxn][maxn];
unordered_map<char, int> last;

int main()
{
    FastEverything
    HighPrecision
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n, m;
        cin>>n>>m;
        string a, b;
        cin>>a>>b;
        a = "#" + a;
        b = "#" + b;
        ll cnt = -infll;
        for(int i = 1; i <= n; ++i){
            last[a[i]] = i;
            for(int j = 1; j <= m; ++j){
                if(j  > 1){
                    dp[i][j] = max(dp[i][j], dp[i][j - 1] - 1);
                }
                if(last[b[j]] > 0){
                    dp[i][j] = max(dp[i][j], dp[last[b[j]] - 1][j - 1] + 2 - (i - last[b[j]]));
                }
                cnt = max(cnt, dp[i][j]);   
            }
        }
        cout<<cnt<<'\n';
    }    
   
    return 0;
} 
