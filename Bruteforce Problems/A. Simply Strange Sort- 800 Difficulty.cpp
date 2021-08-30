/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1561/problem/A
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

int a[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    
    int test = 1;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
        }
        int nr = 1;
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] != i){
                ++cnt, i = n + 1;
            }
        }
        bool ok = 1;
        while(ok){
            ok = 0;
            if(nr & 1){
                for(int i = 1; i < n; i += 2){
                    if(a[i + 1] < a[i]){
                        swap(a[i], a[i + 1]);
                    }
                }
            }
            else{
                for(int i = 2; i < n; i += 2){
                    if(a[i + 1] < a[i]){
                        swap(a[i], a[i + 1]);
                    }
                }
            }
            for(int i = 1; i <= n; ++i){
                if(a[i] != i){
                    ok = 1, ++cnt;
                    i = n + 1;
                }
            }
            ++nr;   
        }
        cout<<cnt<<'\n';    
    }


    return 0;
}
