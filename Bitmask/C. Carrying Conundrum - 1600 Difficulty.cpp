/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1567/problem/C
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
// Usefull
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

int p[50];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        string s;
        cin>>s;
        int n = s.size();
        s = "#" + s;
        int u = n - 2;
        if(u < 0)u = 0;
        u = (1 << u);
        ll cnt = 0;
        for(int i = 0; i < u; ++i){
            int nr = 1;
            int x = i;
            for(int j = 1; j <= n; ++j)p[j] = 0;
            while(x){
                if(x & 1)p[nr] = 1;
                x /= 2;
                ++nr;
            }
            ll cnt2 = 1;
            for(int j = n; j >= 1; --j){
                int sum = 0;
                for(int t = 0; t <= 9; ++t){
                    for(int t1 = 0; t1 <= 9; ++t1){
                        if((t + t1 + p[j]) % 10 != int(s[j] - '0'))continue;
                        if(j <= 2 && (t + t1 + p[j]) / 10 > 0)continue;
                        if((t + t1 + p[j]) / 10 != p[j - 2])continue;
                        ++sum;
                    }
                }
                cnt2 *= sum;
            }
            cnt += cnt2;
        }
        cout<<cnt - 2<<'\n';

    }
    return 0;
}
