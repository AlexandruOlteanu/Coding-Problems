/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1567/problem/B
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

char c[105];

int v[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    for(int i = 1; i <= 3e5; ++i){
        v[i] = (v[i - 1] ^ i);
    }
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int a, b;
        cin>>a>>b;
        ll x = v[a - 1];
        if(x == b){
            cout<<a<<'\n';
            continue;
        }
        ll y = (x ^ b);
        if(y != a){
            cout<<a + 1<<'\n';
            continue;
        }
        cout<<a + 2<<'\n';




    }
    return 0;
}
