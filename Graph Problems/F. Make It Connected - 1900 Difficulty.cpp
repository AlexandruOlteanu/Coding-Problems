/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1095/problem/F
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll const mod=1000000007LL;
ll const mod2=998244353LL;
ll mypowr(ll a,ll b) {ll res=1;if(b<0)b=0;a%=mod; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
ifstream in("input.txt");
ofstream out("output.txt");
#define mp make_pair
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()


//#define cin in
//#define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e5 + 2;

ll a[maxn];
vector<tuple<ll, int, int>> e;
tuple<ll, int, int> l;
int p[maxn];

int find(int x){
    return (x == p[x] ? x : (p[x] = find(p[x])));
}
void merge(int x, int y){
    p[x] = y;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    //cin>>test;
    while(test--){
        int n, m;
        cin>>n>>m;
        ll mini = infll;
        int pos = -1;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
            if(a[i] < mini){
                mini = a[i];
                pos = i;
            }
            p[i] = i;
        }
        for(int i = 1; i <= n; ++i){
            if(i == pos)continue;
            l = {a[i] + a[pos], i, pos};
            e.pb(l);
        }
        for(int i = 1; i <= m; ++i){
            int x, y;ll w;
            cin>>x>>y>>w;
            l = {w, x, y};
            e.pb(l);
        }
        ll cnt = 0;
        sort(all(e));
        for(auto u:e){
            ll w; int x, y;
            w = get<0>(u);x = get<1>(u);y = get<2>(u);
            int x1 = find(x), y1 = find(y);
            if(x1 == y1)continue;
            cnt += w;
            merge(x1, y1);
        }
        cout<<cnt<<'\n';
        
        
    }
    return 0;
}
