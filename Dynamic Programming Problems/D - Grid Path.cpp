/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://www.codechef.com/START10B/problems/GRIDPA
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
const ll maxn = 3e2 + 2;

char c[maxn][maxn];
ll a[maxn][maxn];
ll dp[maxn][maxn][maxn][3];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    cin>>test;
    while(test--){
        int n, k;
        cin>>n>>k;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin>>c[i][j];
            }
        }
        for(int i = 0; i <= n; ++i){
            for(int j = 0; j <= n; ++j){
                for(int t = 0; t <= k; ++t){
                    dp[i][j][t][0] = dp[i][j][t][1] = dp[i][j][t][2] = -1; 
                }
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cin>>a[i][j];
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                ll mx = -1;
                for(int t = 0; t <= k; ++t){
                    if(t == 0){
                        if(c[i][j] == '.'){
                            if(i == 1 && j == 1)dp[i][j][0][0] = 0, dp[i][j][0][2] = 0;
                                dp[i][j][0][0] = max(dp[i][j][0][0], dp[i][j - 1][0][0]);
                                dp[i][j][0][2] = max(dp[i][j][0][2], dp[i][j - 1][0][2]);
                                dp[i][j][0][2] = max(dp[i][j][0][2], dp[i][j - 1][k][1]);
                                dp[i][j][0][0] = max(dp[i][j][0][0], dp[i - 1][j][0][0]);
                                dp[i][j][0][2] = max(dp[i][j][0][2], dp[i - 1][j][0][2]);
                                dp[i][j][0][2] = max(dp[i][j][0][2], dp[i - 1][j][k][1]);
                                if(dp[i][j][0][0] >= 0){
                                    dp[i][j][0][0] += a[i][j];
                                }
                                if(dp[i][j][0][2] >= 0){
                                    dp[i][j][0][2] += a[i][j];
                                }

                        }
                        continue;
                    }
                    dp[i][j][t][1] = max(dp[i][j][t][1], dp[i][j - 1][t - 1][1]);
                    dp[i][j][t][1] = max(dp[i][j][t][1], dp[i - 1][j][t - 1][1]);
                    if(t == 1){
                        dp[i][j][t][1] = max(dp[i][j][t][1], dp[i][j - 1][t - 1][0]);
                        dp[i][j][t][1] = max(dp[i][j][t][1], dp[i - 1][j][t - 1][0]);
                    }
                    if(dp[i][j][t][1] >= 0){
                        dp[i][j][t][1] += a[i][j];
                    }
                    mx = max(mx, dp[i][j][t][1]);
                }
                dp[i][j][k][1] = mx;
            }
        }
        ll cnt = -1;
        cnt = max(cnt, dp[n][n][0][2]);
        cnt = max(cnt, dp[n][n][0][0]);
        cnt = max(cnt, dp[n][n][k][1]);
        cout<<cnt<<'\n';

    }
    return 0;
}
