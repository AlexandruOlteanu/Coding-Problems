/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1548/problem/B
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

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e5 + 2;

ll a[maxn];
ll st[maxn][20];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    auto f = [&] (ll x, ll y){
        return __gcd(x, y);
    };
    auto good = [&] (int x, int y){
        ll answer = 0;
        while(x <= y){
            ll u = (y - x + 1);
            ll t = 1, sum = 0;
            while(t <= u){
                t *= 2;
                ++sum;
            }
            --sum;
            answer = f(answer, st[x][sum]);
            x += (1<<sum);
        }
        if(answer > 1)return true;
        return false;
    };

    int test = 1;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        --n;
        int logmax = 32 - __builtin_clz(n);
        for(int j = 0; j <= logmax; ++j){
            for(int i = 1; i + (1<<j) - 1 <= n; ++i){
                if(j == 0){
                    st[i][0] = f(0, abs(a[i + 1] - a[i]));
                    continue;
                }
                st[i][j] = f(st[i][j - 1], st[i + (1<<(j - 1))][j - 1]);
            }
        }
        int cnt = 0;
        int i = 1, j = 1;
        while(i <= n && j <= n){
            if(good(i, j)){
                cnt = max(cnt, j - i + 1);
                ++j;
            }
            else{
                ++i;
                j = max(j, i);
            }
        }
        cout<<cnt + 1<<'\n';

    }

    return 0;
}
