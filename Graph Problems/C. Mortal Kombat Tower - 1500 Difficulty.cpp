/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1366/problem/C
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
const ll maxn = 1e3 + 2;

int a[35][35];
bool was[maxn];
vector<int> v[maxn];
ll white = 0, black = 0;
int n, m;

void dfs(int x){
    if(was[x])return;
    was[x] = 1;
    int x1 = 0, y1 = 0;
    y1 = x % m;
    if(y1 == 0)y1 = m;
    x1 = x / m + (x % m != 0); 
    if(a[x1][y1] == 0)++white;
    else ++black;
    for(auto u:v[x]){
        dfs(u);
    }
}


int main()
{
    FastEverything
    HighPrecision
    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        cin>>n>>m;
        int pos = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin>>a[i][j];
            }
        }
        int total_dist = n - 1 + m - 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                int dist = i - 1 + j - 1;
                dist = total_dist - dist;
                for(int t = 1; t <= n; ++t){
                    for(int t1 = 1; t1 <= m; ++t1){
                        if(t < i && t1 > j)continue;
                        if(t > i && t1 < j)continue;
                        int dist2 = t - 1 + t1 - 1;
                        if(dist2 != dist)continue;
                        int here1 = 0, here2 = 0;
                        here1 = (i - 1) * m + j;
                        here2 = (t - 1) * m + t1;
                        v[here1].pb(here2);
                    }
                }
            }
        }
        int cnt = 0;
        for(int i = 1; i <= n * m; ++i){
            if(was[i])continue;
            white = black = 0;
            dfs(i);
            cnt += min(white, black);
        }
        cout<<cnt<<'\n';
        for(int i = 1; i <= n * m; ++i){
            v[i].clear();
            was[i] = 0;
        }

    }   
    return 0;
}
