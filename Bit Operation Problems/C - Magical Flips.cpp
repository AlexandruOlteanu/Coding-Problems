/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://www.codechef.com/START10B/problems/CRDFLP
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
const ll maxn = 1e5 + 2;

int a[maxn], b[maxn];
bool taken1[maxn], taken2[maxn];

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
            taken1[i] = 0;
        }
        for(int i = 1; i <= n; ++i){
            cin>>b[i];
            taken2[i] = 0;
        }
        int cnt = 0;
        for(int i = 30; i >= 0; --i){
            bool ok = 1;
            for(int j = 1; j <= n && ok; ++j){
                bool ok2 = 0;
                if(taken1[j]){
                    if((a[j] & (1 << i)) > 0)ok2 = 1;
                    else ok = 0;
                    continue;
                }
                if(taken2[j]){
                    if((b[j] & (1 << i)) > 0)ok2 = 1;
                    else ok = 0;
                    continue;
                }
                if((a[j] & (1 << i)) > 0)ok2 = 1;
                if((b[j] & (1 << i)) > 0)ok2 = 1;
                if(!ok2)ok = 0;
            }
            if(!ok)continue;
            for(int j = 1; j <= n; ++j){
                if(!taken1[j] && !taken2[j]){
                    int sum = ((a[j] & (1 << i)) > 0) + ((b[j] & (1 << i)) > 0);
                    if(sum == 2)continue;
                    if((a[j] & (1 << i)) > 0){
                        taken1[j] = 1;
                    }
                    else{
                        taken2[j] = 1;
                    }
                }
            }
        }
        cnt = (taken1[1] ? a[1] : b[1]);
        int ans = 0;
        for(int i = 1; i <= n; ++i){
            if(taken1[i]){
                cnt &= a[i];
            }
            else{
                if(taken2[i])++ans;
                cnt &= b[i];
            }
        }
        cout<<cnt<<" "<<ans<<'\n';
    }
    return 0;
}
