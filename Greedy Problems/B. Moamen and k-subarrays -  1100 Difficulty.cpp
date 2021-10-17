/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1557/problem/B
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
const ll maxn = 1e5 + 2;

int a[maxn], c[maxn];
unordered_map<int, int> m;

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
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
            c[i] = a[i];
        }
        sort(c + 1, c + n + 1);
        for(int i = 1; i <= n; ++i){
            m[c[i]] = i;
        }
        int need = 1;
        for(int i = 2; i <= n; ++i){
            int pos = m[a[i - 1]];
            int pos2 = m[a[i]];
            if(pos2 == pos + 1)continue;
            ++need;
        }
        if(need > k){
            cout<<"No\n";
            continue;
        }
        cout<<"Yes\n";

    }


    return 0;
}
