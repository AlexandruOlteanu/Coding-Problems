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
const ll maxn = 15e4 + 2;

ll dp[maxn];
int a[305], b[305], t[305];


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        ll n, m, d;
        cin>>n>>m>>d;
        for(int i = 1; i <= m; ++i){
            cin>>a[i]>>b[i]>>t[i];
        }
        deque<pair<ll, ll>> window;
        for(int i = 1; i <= n; ++i){
            dp[i] = b[1] - abs(a[1] - i);
        }
        for(int i = 2; i <= m; ++i){
            ll time = t[i] - t[i - 1];
            ll k = time * d;

            for(int j = 1; j <= min(k + 1, n); ++j){
                while(!window.empty() && window.back().fi <= dp[j])window.pop_back();
                window.push_back({dp[j], j});
            }
            ll p = k + 2;
            dp[1] = window.front().fi + b[i] - abs(a[i] - 1); 
            for(int j = 2; j <= n; ++j){
                if(p <= n){
                        while(!window.empty() && window.back().fi <= dp[p])window.pop_back();       
                    window.push_back({dp[p], p});
                }
                while(window.front().se < j - k)window.pop_front();
                dp[j] = window.front().fi + b[i] - abs(a[i] - j);
                ++p;
            }
            window.clear();
        }
        ll cnt = -infll;
        for(int i = 1; i <= n; ++i){
            cnt = max(cnt, dp[i]);
        }
        cout<<cnt<<'\n';

    }
    return 0;
}
