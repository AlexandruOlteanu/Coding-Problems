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
const ll maxn = 1e3 + 2;

int a[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;cin>>n;
        int nr = 0;
        for(int i = 1; i <= n / 2; ++i){
            for(int j = 1; j <= n / 2; ++j){
                a[i][j] = nr;
                nr += 4;
            }
        }
        for(int i = 1; i <= n / 2; ++i){
            for(int j = n / 2 + 1; j <= n; ++j){
                a[i][j] = a[i][j - n / 2] + 1;
            }
        }
        for(int i = n / 2 + 1; i <= n; ++i){
            for(int j = 1; j <= n / 2; ++j){
                a[i][j] = a[i - n / 2][j] + 2;
            }
        }
        for(int i = n / 2 + 1; i <= n; ++i){
            for(int j = n / 2 + 1; j <= n; ++j){
                a[i][j] = a[i - n / 2][j - n / 2] + 3;
            }
        }
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                cout<<a[i][j]<<" ";
            }
            cout<<'\n';
        }



    }
    return 0;
}
