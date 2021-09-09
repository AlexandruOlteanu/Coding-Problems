/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1569/problem/B
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt")
#pragma GCC target("abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize(3)
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
// Useful
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define FastEverything  ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
#define HighPrecision cout<<fixed<<setprecision(17);
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

char c[100][100];
int v[100];

int main()
{
    FastEverything
    HighPrecision
    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;
        cin>>n;
        string s;cin>>s;
        int sum = 0;
        for(int i = 0; i < 100; ++i)v[i] = -1;
        for(int i = 0; i < n; ++i){
            if(s[i] == '2'){
                ++sum;
                if(sum <= 3)v[i] = sum;
            }
        }
        if(sum > 0 && sum < 3){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i = 0; i < n; ++i){
            for(int j = i; j < n; ++j){
                if(i == j){
                    c[i][j] = 'X';
                    continue;
                }
                if(s[i] == '1' && s[j] == '1'){
                    c[i][j] = c[j][i] = '=';
                    continue;
                }
                if(s[i] == '1' && s[j] == '2'){
                    c[i][j] = '+';
                    c[j][i] = '-';
                    continue;
                }
                if(s[i] == '2' && s[j] == '1'){
                    c[i][j] = '-';
                    c[j][i] = '+';
                    continue;
                }
                if(v[i] < 0 && v[j] < 0){
                    c[i][j] = c[j][i] = '=';
                    continue;
                }
                if(v[i] < 0){
                    c[i][j] = '+';
                    c[j][i] = '-';
                    continue;
                }
                if(v[j] < 0){
                    c[i][j] = '-';
                    c[j][i] = '+';
                    continue;
                }
                if(v[i] == 1 && v[j] == 2){
                    c[i][j] = '+';
                    c[j][i] = '-';
                    continue;
                }
                if(v[i] == 2 && v[j] == 1){
                    c[i][j] = '-';
                    c[j][i] = '+';
                    continue;
                }
                if(v[i] == 1 && v[j] == 3){
                    c[i][j] = '-';
                    c[j][i] = '+';
                    continue;
                }
                if(v[i] == 3 && v[j] == 1){
                    c[i][j] = '+';
                    c[j][i] = '-';
                    continue;
                }
                if(v[i] == 2 && v[j] == 3){
                    c[i][j] = '+';
                    c[j][i] = '-';
                    continue;
                }
                if(v[i] == 3 && v[j] == 3){
                    c[i][j] = '-';
                    c[j][i] = '+';
                    continue;
                }

            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                cout<<c[i][j];
            }
            cout<<'\n';
        }

    }   
    return 0;
}
