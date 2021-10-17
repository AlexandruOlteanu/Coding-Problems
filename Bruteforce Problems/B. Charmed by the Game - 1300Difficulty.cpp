/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1561/problem/B
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
const ll maxn = 1e3 + 2;

vector<int> v;
unordered_set<int> s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    cin>>test;
    while(test--){
        int a, b;
        cin>>a>>b;
        int n = a + b;
        int c1 = (n + 1) / 2;
        int c2 = n / 2;
        int br1 = 0, br2 = 0;
        int a1 = c1, b1 = c2;
        if(c1 > a)br1 += (c1 - a), a1 -= br1, b1 += br1;
        else{
            if(c2 > b)br2 += (c2 - b), b1 -= br2, a1 += br2;
        }
        int need = br1 + br2;        
        v.pb(need);
        s.insert(need);
        b1 = min(a1, b1);
        for(int i = 1; i <= b1; ++i){
            need += 2;
            v.pb(need);
            s.insert(need);
        }
        c1 = n / 2;
        c2 = (n + 1) / 2;
        br1 = 0, br2 = 0;
        a1 = c1, b1 = c2;
        if(c1 > a)br1 += (c1 - a), a1 -= br1, b1 += br1;
        else{
            if(c2 > b)br2 += (c2 - b), b1 -= br2, a1 += br2;
        }
        need = br1 + br2;
        if(!s.count(need)){
            v.pb(need);
        }
        b1 = min(a1, b1);
        for(int i = 1; i <= b1; ++i){
            need += 2;
            if(!s.count(need))v.pb(need);
        }
        sort(all(v));
        cout<<v.size()<<'\n';
        for(auto u:v){
            cout<<u<<" ";
        }
        cout<<'\n';
        v.clear();
        s.clear();

    }


    return 0;
}
