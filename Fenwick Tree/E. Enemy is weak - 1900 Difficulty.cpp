/*
    Programmer : Alexandru_Olteanu
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
const ll maxn = 1e6 + 2;

/*
    Template created by Alexandru Olteanu
*/
template<typename A>
struct FenwickTree{
    vector<A> array;
    int n;
    FenwickTree(int length){
        array.resize(length);
        n = length - 1;
    }

    void modify_fenwick(int x, ll val){
        for(; x <= n; x += x & -x){
            array[x] += val;
        }
        return;
    }

    ll get_fenwick(int x){
        ll val = 0;
        for(; x > 0; x -= x & -x){
            val += array[x];
        }
        return val;
    }
};

int a[maxn], b[maxn];
unordered_map<int, int> m;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cout<<fixed<<setprecision(15);
    
    
    int test = 1;
    //cin>>test;
    for(int tt = 1; tt <= test; ++tt){
        int n;cin>>n;
        for(int i = 1; i <= n; ++i){
            cin>>a[i];
            b[i] = a[i];
        }
        sort(a + 1, a + n + 1);
        int nr = 1;
        for(int i = 1; i <= n; ++i){
            m[a[i]] = nr++;
        }
        --nr;
        FenwickTree<int> st(nr + 1), dr(nr + 1);
        st.modify_fenwick(m[b[1]], 1);
        for(int i = 3; i <= n; ++i){
            dr.modify_fenwick(m[b[i]], 1);
        }
        ll cnt = 0;
        for(int i = 2; i < n; ++i){
            ll have1 = st.get_fenwick(nr) - st.get_fenwick(m[b[i]]);
            ll have2 = dr.get_fenwick(m[b[i]]);
            cnt += have1 * have2;
            st.modify_fenwick(m[b[i]], 1);
            dr.modify_fenwick(m[b[i + 1]], -1);
        }
        cout<<cnt<<'\n';

    }
    return 0;
}
