/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/375/problem/B
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
const ll maxn = 5e3 + 2;

char a[maxn][maxn];

vector<int> v[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);

    int test = 1;
    //cin>>test;
    while(test--){
        int n, m;
        cin>>n>>m;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= m; ++j){
                cin>>a[i][j];
            }  
        }
        for(int i = 1; i <= n; ++i){
            int j = 1, sum = 0;
            while(j <= m + 1){
                if(a[i][j] == '1' && j <= m)++sum;
                else{
                    if(sum > 0){
                        for(int u = sum; u >= 1;--u){
                            v[j - u].pb(u);
                        }
                    }
                    sum = 0;
                }
                ++j;
            }
        }
        for(int i = 1; i <= m; ++i){
            sort(rall(v[i]));
        }
        int cnt = 0;
        for(int i = 1; i <= m; ++i){
            int sum = 0;
            int u = v[i].size();
            for(int j = 0; j < u; ++j){
                sum = max(sum, v[i][j] * (j + 1));
            }
            cnt = max(cnt, sum);
        }
        cout<<cnt<<'\n';

    }
    


    return 0;
}
