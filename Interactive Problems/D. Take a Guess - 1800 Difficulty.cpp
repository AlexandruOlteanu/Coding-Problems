/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1556/problem/D
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

vector<ll> v;

ll And(int x, int y){
    cout<<"and "<<x<<" "<<y<<endl;
    int a;
    cin>>a;
    return a;
}
ll Or(int x, int y){
    cout<<"or "<<x<<" "<<y<<endl;
    int a;
    cin>>a;
    return a;
}
void finish(ll x){
    cout<<"finish "<<x<<endl;
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
        int n, k;
        cin>>n>>k;
        ll a = And(1, 2) + Or(1, 2);
        ll b = And(2, 3) + Or(2, 3);  
        ll c = And(1, 3) + Or(1, 3);
        ll x = 0, y = 0, z = 0;
        x = ((a - b) + c) / 2;
        y = a - x;
        z = c - x;
        v.pb(x);v.pb(y);v.pb(z);
        for(int i = 4; i <= n; ++i){
            ll p = And(1, i) + Or(1, i);
            v.pb(p - x);
        }
        sort(all(v));
        finish(v[k - 1]);


    }



    return 0;
}
