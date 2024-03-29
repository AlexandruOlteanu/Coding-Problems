/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://www.codechef.com/CDMN21B/problems/RUMBLING
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

ll st[maxn], dr[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        ll n, x, y;
        cin>>n;
        string s;cin>>s>>x>>y;
        s = "#" + s;
        st[0] = 0, dr[n + 1] = 0;
        for(int i = 1; i <= n; ++i){
            ll sum = 0;
            if(s[i] == 'S'){
                sum = min(y, 3 * x);
            }
            if(s[i] == 'W'){
                sum = min(2 * x, 2 * y);
            }
            if(s[i] == 'N'){
                sum = min(3 * y, x);
            }
            st[i] = st[i - 1] + sum;
        }
        for(int i = n; i >= 1; --i){
            dr[i] = dr[i + 1];
            ll sum = 0;
            if(s[i] == 'S'){
                sum = min(x, 3 * y);
            }
            if(s[i] == 'E'){
                sum = min(2 * x, 2 * y);
            }
            if(s[i] == 'N'){
                sum = min(y, 3 * x);
            }
            dr[i] += sum;
        }
        ll cnt = infll;
        for(int i = 0; i <= n; ++i){
            cnt = min(cnt, st[i] + dr[i + 1]);
        }
        cout<<cnt<<'\n';


    }
    return 0;
}
