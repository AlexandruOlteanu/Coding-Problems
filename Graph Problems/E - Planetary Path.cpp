/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://www.codechef.com/CDMN21B/problems/PLNTPATH
*/
#include<bits/stdc++.h>
using namespace std;
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
const ll maxn = 2e4 + 2;

int a[maxn];
vector<pair<ll, int>> v[1002];
vector<ll> dist(1002, infll);
priority_queue<pll> q;

void build_dijkstra(int root){
    dist[root] = 0;
    q.push({0, root});
    while(!q.empty()){
        int u = q.top().se;
        q.pop();
        for(auto i:v[u]){
            if(dist[i.se] > dist[u] + i.fi){
                dist[i.se] = dist[u] + i.fi;
                q.push({-dist[i.se], i.se});
            }
        }
    }
    return;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n, k, s;
        cin>>n>>k>>s;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= k; ++j){
                int x;cin>>x;
                if(x < 0)continue;
                int aliance = a[i];
                if(aliance == j)continue;
                v[aliance].pb({x, j});
            }
        }
        int base = a[s];
        build_dijkstra(base);
        for(int i = 1; i <= n; ++i){
            int x = a[i];
            if(dist[x] == infll)dist[x] = -1;
            cout<<dist[x]<<" ";
        }

    }
    return 0;
}
