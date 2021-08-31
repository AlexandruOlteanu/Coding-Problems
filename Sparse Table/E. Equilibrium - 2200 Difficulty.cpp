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
const ll maxn = 1e5 + 2;

ll a[maxn];
ll stmin[maxn][18], stmax[maxn][18];

ll ansmin = infll, ansmax = -infll;

void find(int x, int y){
    while(x <= y){
        ll u = (y - x + 1);
        ll t = 1, sum = 0;
        while(t <= u){
            t *= 2;
            ++sum;
        }
        --sum;
        ansmin = min(ansmin, stmin[x][sum]);
        ansmax = max(ansmax, stmax[x][sum]);
        x += (1 << sum);
    }
}


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
            cin>>a[i];
        }
        for(int i = 1; i <= n; ++i){
            int x; cin>>x;
            a[i] = x - a[i];
            a[i] += a[i - 1];
        }
        for(ll j = 0; j <= 17; ++j){
            for(int i = 1; i + (1 << j) - 1 <= n; ++i){
                if(j == 0){
                    stmin[i][0] = a[i];
                    stmax[i][0] = a[i];
                    continue;
                }
                stmin[i][j] = min(stmin[i][j - 1], stmin[i + (1 << (j - 1))][j - 1]);
                stmax[i][j] = max(stmax[i][j - 1], stmax[i + (1 << (j - 1))][j - 1]);
            }
        }
        for(int i = 1; i <= m; ++i){
            int x, y;cin>>x>>y;
            if(a[y] - a[x - 1] != 0){
                cout<<"-1\n";
            }
            else{
                find(x, y);
                ansmin -= a[x - 1];
                ansmax -= a[x - 1];
                if(ansmin < 0){
                    cout<<"-1\n";
                }
                else{
                    cout<<ansmax<<'\n';
                }
                ansmin = infll;
                ansmax = -infll;
            }
        }
    }
    return 0;
}
