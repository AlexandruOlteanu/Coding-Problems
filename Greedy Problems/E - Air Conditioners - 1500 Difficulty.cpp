/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1547/problem/E
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

const ll maxn = 3e5 + 2;
int cnt[maxn];
int a[maxn], t[maxn];

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
        for(int i = 0; i <= n + 1; ++i)cnt[i] = 2e9;
        for(int i = 1; i <= k; ++i){
            cin>>a[i];
        }
        for(int i = 1; i <= k; ++i){
            cin>>t[i];
            cnt[a[i]] = t[i];
        }
        for(int i = 1; i <= n; ++i){
            cnt[i] = min(cnt[i], cnt[i - 1] + 1);
        }
        for(int i = n; i >= 1; --i){
            cnt[i] = min(cnt[i], cnt[i + 1] + 1);
        }
        for(int i = 1; i <= n; ++i){
            cout<<cnt[i]<<" ";
        }
        cout<<'\n';
    }
    

    return 0;
}
