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
const ll maxn = 2e5 + 2;

int a[maxn];
pii b[maxn];
unordered_set<int> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n, k;
        cin>>n>>k;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
            b[i].fi = a[i];
            b[i].se = i;
        }
        sort(b + 1, b + n + 1, greater<pii>());
        for(int i = 1; i <= k; ++i){
            s.insert(b[i].se);
        }
        cout<<b[(k + 2) / 2].fi<<'\n';
        for(int i = 1; i <= n; ++i){
            if(!s.count(i))continue;
            cout<<a[i]<<" ";
        }
        cout<<'\n';
        s.clear();


    }
    return 0;
}
