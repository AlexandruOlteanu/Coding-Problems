/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1556/problem/E
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

ll a[maxn];
ll node[3 * maxn + 5];
ll node1[3 * maxn + 5];


void segmentmin(int x){
    if(x == 0)return;
    if(node[(x - 1) / 2] = min(node[(x - 1) / 2], node[x]));
    segmentmin((x - 1) / 2);
    return;
}

void segmentmax(int x){
    if(x == 0)return;
    if(node1[(x - 1) / 2] = max(node1[(x - 1) / 2], node1[x]));
    segmentmax((x - 1) / 2);
    return;
}
ll ans = infll, ans1 = -infll;

void find(int nd, int x, int y, int st, int dr){
    if(x > y || y < st || x > dr)return;
    if(x >= st && y <= dr){
        ans = min(ans, node[nd]);
        ans1 = max(ans1, node1[nd]);
        return;
    }
    find(nd * 2 + 1, x, (y - x) / 2 + x, st, dr);
    find(nd * 2 + 2, x + (y - x) / 2 + 1, y, st, dr);
    return;
}



int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    

    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n, m;
        cin>>n>>m;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        for(int i = 1; i <= n; ++i){
            int x; cin>>x;
            a[i] = x - a[i];
            a[i] += a[i - 1];
        }
        ll power = 1;
        while(power < n){
            power <<= 1LL;
        }
        --power;
        for(int i = 0; i <= power + n - 1; ++i){
            node[i] = infll;
            node1[i] = -infll;
        }
        for(int i = 1; i <= n; ++i){
            node[power + i - 1] = a[i];
            node1[power + i - 1] = a[i];
            segmentmin(power + i - 1);
            segmentmax(power + i - 1);
        }
        for(int i = 1; i <= m; ++i){
            int x, y;cin>>x>>y;
            if(a[y] != a[x - 1]){
                cout<<"-1\n";
                continue;
            }
            find(0, 1, power + 1, x, y);
            ans -= a[x - 1];
            ans1 -= a[x - 1];
            if(ans < 0){
                cout<<"-1\n";
                ans = infll;
                ans1 = -infll;
                continue;
            }
            cout<<ans1<<'\n';
            ans = infll;
            ans1 = -infll;
        }
    }
    return 0;
}
