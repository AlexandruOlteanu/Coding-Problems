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
const ll maxn = 1e5 + 2;

int a[maxn], b[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        for(int i = 1; i < n; ++i){
            cin>>b[i];
        }
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n);
        int cnt = inf;
        bool ok = 1;
        for(int i = 2; i < n; ++i){
            if(b[i] - a[i + 1] != b[i - 1] - a[i])ok = 0;
        }
        if(ok){
            cnt = b[1] - a[2]; 
        }
        if(cnt <= 0)cnt = inf;
        cnt = min(cnt, b[1] - a[1]);

        cout<<cnt<<'\n';
    }
    return 0;
}