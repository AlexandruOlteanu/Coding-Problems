/*
    Programmer : Alexandru Olteanu
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

// #define cin in
// #define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e5 + 2;

int a[maxn];
vector<int> v[maxn];

struct tree{
    int even, odd;
    tree(){
        even = inf, odd = inf;
    }
}ready[maxn];

int q[maxn], top = 1;

void build(int x){
    if(a[x] % 2 == 0)ready[x].even = 0;
    else ready[x].odd = 0;
    q[1] = x;
    top = 1;
    for(int i = 1; i <= top; ++i){
        for(auto u:v[q[i]]){
            if(a[u] % 2 != a[x] % 2){
                if(a[x] % 2 == 1 && ready[u].odd > ready[q[i]].odd + 1){
                    q[++top] = u;
                    ready[u].odd = ready[q[i]].odd + 1;
                }
                if(a[x] % 2 == 0 && ready[u].even > ready[q[i]].even + 1){
                    q[++top] = u;
                    ready[u].even = ready[q[i]].even + 1;
                }
            }
        }
    }
    return;
}


int main()
{
    FastEverything
    HighPrecision
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;
        cin>>n;
        for(int i  = 1; i <= n; ++i){
            cin>>a[i];
            if(i + a[i] <= n)v[i + a[i]].pb(i);
            if(i - a[i] >= 1)v[i - a[i]].pb(i);
        }
        for(int i = 1; i <= n; ++i){
            build(i);
        }
        for(int i = 1; i <= n; ++i){
            int cnt = 0;
            if(a[i] % 2){
                cnt = ready[i].even;
            }
            else{
                cnt = ready[i].odd;
            }
            if(cnt == inf)cnt = -1;
            cout<<cnt<<" ";
        }
    }   
    return 0;
}

