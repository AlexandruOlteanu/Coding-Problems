/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1418/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt")
#pragma GCC target("abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
// Useful
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define FastEverything  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define HighPrecision cout<<fixed<<setprecision(17);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll const mod=1000000007LL;
ll const mod2 = 100000000LL;
ll const md=998244353LL;
ll mypowr(ll a,ll b) {ll res=1;if(b<0)b=0;a%=mod; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
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
const ll maxn = 2e5 + 2;

int dp[maxn][2];
int a[maxn];

int main()
{
    FastEverything
    HighPrecision
    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        dp[1][0] = a[1];
        dp[2][0] = a[1] + a[2];
        dp[1][1] = inf;
        for(int i = 2; i <= n; ++i){
            dp[i][0] = dp[i - 2][1] + a[i] + a[i - 1];
            dp[i][0] = min(dp[i][0], dp[i - 1][1] + a[i]);
            dp[i][1] = inf;
            if(i >= 3){
                dp[i][1] = dp[i - 2][0];
            }
            dp[i][1] = min(dp[i][1], dp[i - 1][0]);
        } 
        int cnt = min(dp[n][1], dp[n][0]);
        cout<<cnt<<'\n';

    }   
    return 0;
}
