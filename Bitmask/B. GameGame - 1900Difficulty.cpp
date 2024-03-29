/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1383/problem/B
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

int a[maxn];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    int test = 1;
    cin>>test;
    while(test--){
    	int n; cin>>n;
    	short ok = 0;
    	a[0] = 0;
    	for(int i = 1; i <= n; ++i){
    		cin>>a[i];
    		a[0] ^= a[i];
    	}
    	for(int i = 30; i >= 0; --i){
    		if(a[0] & (1<<i)){
    			int sum = 0, sum2 = 0;
    			for(int j = 1; j <= n; ++j){
    				if((a[j] & (1<<i)) == 0)++sum;
    				if((a[j] & (1<<i)) > 0)++sum2;
    			}
    				sum %= 2;
    				int need = sum2 % 4;
    				if(need == 3){
    					if(sum) ok = 1;
    					else ok = -1;
    				}
    				else{
    					ok = 1;
    				}
    			
    			i = -1;
    		}
    	}
    	if(ok < 0) cout<<"LOSE\n";
    	else if(ok > 0) cout<<"WIN\n";
    	else cout<<"DRAW\n";
    }

    return 0;
}
