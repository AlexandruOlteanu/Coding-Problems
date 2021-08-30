/*
    Programmer : Alexandru_Olteanu
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
const ll maxn = 1e3 + 2;

ll a[maxn];
ll sum[maxn];
ll dp[maxn][maxn], dp1[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    //cin>>test;
    while(test--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        ll ans = 0;
        for(int i = 1; i <= n; ++i){
            ans = 0;
            for(int j = i; j <= n; ++j){
                if(j & 1)ans += a[j];
                else {
                    ans -= a[j];
                }
                if(j == i)dp[i][j] = 0;
                else dp[i][j] = dp[i][j - 1];
                if(ans < 0)dp[i][j] += (-ans), ans = 0;
            }
        }
        for(int i = n; i >= 1; --i){
            ans = 0;
            for(int j = i; j >= 1; --j){
                if(j & 1)ans += a[j];
                else {
                    ans -= a[j];
                }
                if(j == i)dp1[i][j] = 0;
                else dp1[i][j] = dp1[i][j + 1];
                if(ans > 0)dp1[i][j] += ans, ans = 0;
            }
        }

        ll cnt = 0;
        for(int i = 1; i <= n; ++i){
            for(int j = i; j <= n; ++j){
                if(i % 2 == 0 || j % 2 == 1)continue;
                ll have1 = a[i];
                ll have2 = a[j];
                if(j - i > 1){
                    ll t = dp[i + 1][j - 1];
                    ll t1 = dp1[j - 1][i + 1];
                    have1 -= t;
                    have2 -= t1;
                    if(t > 0 && t1 > 0 && have1 >= 0 && have2 >= 0)++cnt;
                }
                if(have1 < 0 || have2 < 0)continue;
                cnt += min(have1, have2);
            }
        }
        cout<<cnt<<'\n';


    }
    return 0;
}