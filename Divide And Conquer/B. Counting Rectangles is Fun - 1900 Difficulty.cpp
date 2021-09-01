/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/372/problem/B
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
const ll maxn = 4e1 + 2;

char c[maxn][maxn];
ll dp[maxn][maxn][maxn][maxn];
int was[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n, m, k;
        cin>>n>>m>>k;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin>>c[i][j];
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                was[i][j] = was[i][j - 1];
                was[i][j] += was[i - 1][j];
                was[i][j] -= was[i - 1][j - 1];
                was[i][j] += (c[i][j] == '1');
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                for(int x = i; x <= n; ++x){
                    for(int y = j; y <= m; ++y){
                        dp[x][y][i][j] = dp[x][y - 1][i][j];
                        dp[x][y][i][j] += dp[x - 1][y][i][j];
                        dp[x][y][i][j] -= dp[x - 1][y - 1][i][j];
                        int mx = 0;
                        for(int t = x; t >= i; --t){
                            int lo = 1, hi = (y - j + 1);
                            mx = 0;
                            while(lo <= hi){
                                int mid = lo + (hi - lo) / 2;
                                int mid2 = y - mid + 1;
                                int ans = 0;
                                ans += was[x][y];
                                ans -= was[x][mid2 - 1];
                                ans -= was[t - 1][y];
                                ans += was[t - 1][mid2 - 1];
                                if(ans == 0){
                                    mx = max(mx, mid);
                                    lo = mid + 1;
                                }
                                else{
                                    hi = mid - 1;
                                }
                            }
                            dp[x][y][i][j] += mx;
                        }
                    }
                }
            }
        }

        for(int q = 1; q <= k; ++q){
            int a, b, c, d;cin>>a>>b>>c>>d;
            cout<<dp[c][d][a][b]<<'\n';
        }

    }
    return 0;
}
