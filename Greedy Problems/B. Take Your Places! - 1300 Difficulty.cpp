/*
    Programmer : Alexandru_Olteanu
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

int a[maxn];
int v[2];

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
        v[0] = v[1] = 0;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
            a[i] %= 2;
            ++v[a[i]];
        }
        if(abs(v[0] - v[1]) > 1){
            cout<<"-1\n";
            continue;
        }
        int cnt = 0;
        if(v[0] > v[1]){
            int nr = 1;
            for(int i = 1; i <= n; ++i){
                if(a[i] == 0){
                    cnt += abs(i - nr);
                    nr += 2;
                }
            }
            cout<<cnt<<'\n';
            continue;
        }
        if(v[1] > v[0]){
            int nr = 1;
            for(int i = 1; i <= n; ++i){
                if(a[i] == 1){
                    cnt += abs(i - nr);
                    nr += 2;
                }
            }
            cout<<cnt<<'\n';
            continue;
        }
        int nr = 1;
        for(int i = 1; i <= n; ++i){
                if(a[i] == 0){
                    cnt += abs(i - nr);
                    nr += 2;
                }
        }
        nr = 1;
        int sum = 0;
        for(int i = 1; i <= n; ++i){
            if(a[i] == 1){
                sum += abs(i - nr);
                nr += 2;
            }
        }
        cnt = min(cnt, sum);
        cout<<cnt<<'\n';


    }
    return 0;
}