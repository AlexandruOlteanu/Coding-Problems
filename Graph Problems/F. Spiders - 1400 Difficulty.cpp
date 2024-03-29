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

ifstream in("input.txt");
ofstream out("output.txt");
#define cin in
#define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e5 + 5;

int a[maxn];

vector<int> v[105];

int dist[105];
vector<bool> visited(105);

void dfs(int x) {
    for (auto u : v[x]) {
        if (visited[u]) {
            continue;
        }
        visited[u] = true;
        dist[u] = dist[x] + 1;
        dfs(u);
    }
}


int main(int argc, char **args) {

    FastEverything
    HighPrecision
    int number_of_tests = 1;
    // cin >> number_of_tests;
    for (int test = 1; test <= number_of_tests; ++test) {
        
       int n;
       cin >> n;
       int ans = 0;
       for (int i = 1; i <= n; ++i) {
         int k;
         cin >> k;
         for (int j = 1; j <= k; ++j) {
            v[j].clear();
            visited[j] = false;
         }
         for (int j = 1; j < k; ++j) {
            int x, y;
            cin >> x >> y;
            v[x].pb(y);
            v[y].pb(x);
         }

         for (int j = 1; j <= k; ++j) {
            dist[j] = inf;
         }
         dist[1] = 0;
         visited[1] = true;
         dfs(1);
         int maxi = dist[1];
         int nr = 0;
         for (int j = 1; j <= k; ++j) {
            if (dist[j] > maxi) {
                maxi = dist[j];
                nr = j;
            }
            dist[j] = inf;
            visited[j] = false;
         }
         dist[nr] = 0;
         visited[nr] = true;
         dfs(nr);
         maxi = dist[nr];
         for (int j = 1; j <= k; ++j) {
            if (dist[j] > maxi) {
                maxi = dist[j];
            }
            dist[j] = inf;
         }
         ans += maxi;
       }

       cout << ans << '\n';
        
    }   


    return 0;
} 
