/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1538/problem/D
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll const mod=1000000007LL;
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

const ll maxn = 1e7 + 5;

bool solve(int a, int b, int k){
    if(k == 0){
        if(a == b)return 1;
        else return 0;
    }
    if(k == 1){
        if((a % b == 0 || b % a == 0) && a != b)return 1;
        else return 0;
    }
    ll d = 2;
    ll cnt = 0;
    
    for (int i = 2; i * i <= a; i++) {
        while (a % i == 0) {
            a /= i;
            ++cnt;
        }
    }
    if(a > 1)++cnt;
    ll cnt2 = 0;
    d = 2;
    for (int i = 2; i * i <= b; i++) {
        while (b % i == 0) {
            b /= i;
            ++cnt2;
        }
    }
    if(b > 1)++cnt2;
    if(cnt + cnt2 >= k)return 1;
    
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    int t = 1;
    cin>>t;
    while(t--){
        ll a, b, k;
        cin>>a>>b>>k;
        bool cnt = solve(a, b, k);
        cout<<(cnt?"YES\n":"NO\n");
    }

    return 0;
}
