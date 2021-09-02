/*
    Programmer : Alexandru_Olteanu
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
const ll maxn = 3e5 + 2;

int a[maxn][10];
vector<pii> v;
int c[1 << 10];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n, m;
        cin>>n>>m;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin>>a[i][j];
            }
        }
        int lo = 0, hi = 1e9;
        int x = 0, y = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            int have = 0;
            for(int i = 0; i <= (1 << m); ++i){
                c[i] = 0;
            }
            for(int i = 1; i <= n; ++i){
                int x = 0;
                for(int j = 0; j < m; ++j){
                    if(a[i][j + 1] >= mid){
                        x |= (1 << j);
                    }
                }
                if(c[x] > 1)continue;
                v.pb({x, i});
                ++c[x];
            }
            int u = v.size();
            bool ok2 = 0;
            for(int i = 0; i < u && !ok2; ++i){
                for(int j = i; j < u && !ok2; ++j){
                    bool ok = 1;
                    for(int t = 0; t < m && ok; ++t){
                        if(((v[i].fi & (1 << t)) > 0) || ((v[j].fi & (1 << t)) > 0))continue;
                        ok = 0;
                    }
                    if(ok){
                        ok2 = 1;
                        x = v[i].se, y = v[j].se;
                    }
                }
            }
            if(ok2){
                lo = mid + 1;    
            }
            else{
                hi = mid - 1;
            }
            v.clear();
        }
        cout<<x<<" "<<y<<'\n';
        
        


    }
    return 0;
}
