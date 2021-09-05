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

int a[maxn];
unordered_map<int, int> m;

/*
    Template created by Alexandru Olteanu
*/
template<typename A>
struct SegmentTree{
    vector<A> array;
    vector<A> tree;
    vector<A> lazy;

    SegmentTree(int n){
        array.resize(n);
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    A function(A a, A b){
        return a + b;
    }

    void build_segment(int node, int l, int r){
        if(l == r){
            tree[node] = array[l];
            return;
        }
        int mid = l + (r - l) / 2;
        build_segment(node * 2, l, mid);
        build_segment(node * 2 + 1, mid + 1, r);
        tree[node] = function(tree[node * 2], tree[node * 2 + 1]);
        return;
    }

    void push_segment(int node, int l, int r){
        if(lazy[node] != 0){
            if(l != r){
                tree[node] = function(tree[node * 2], tree[node * 2 + 1]);
                lazy[node * 2] ^= 1;
                lazy[node * 2 + 1] ^= 1;
            }
            else{
                tree[node] = array[l];   
            }
            lazy[node] = 0;
        }
        return;
    }

    void update_segment(int node, int l, int r, int L, int R){
        push_segment(node, l, r);
        if(r < L || l > R)return;
        if(l >= L && r <= R){
            lazy[node] ^= 1;
            push_segment(node, l, r);
            return;
        }
        int mid = l + (r - l) / 2;
        update_segment(node * 2, l, mid, L, R);
        update_segment(node * 2 + 1, mid + 1, r, L, R);
        tree[node] = function(tree[node * 2], tree[node * 2 + 1]);
        return;
    }

    A ask_segment(int node, int l, int r, int L, int R){
        push_segment(node, l, r);
        if(r < L || l > R) return 0;
        if(l >= L && r <= R){
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        A ask1 = ask_segment(node * 2, l, mid, L, R);
        A ask2 = ask_segment(node * 2 + 1, mid + 1, r, L, R);
        return function(ask1, ask2);
    }
};

int b[maxn];

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
        SegmentTree<int> st(nr + 1), dr(nr + 1);
        st.array[m[b[1]]] = 1;
        for(int i = 3; i <= n; ++i){
            dr.array[m[b[i]]] = 1;
        }
        st.build_segment(1, 1, n);
        dr.build_segment(1, 1, n);
        ll cnt = 0;
        for(int i = 2; i < n; ++i){
            ll have1 = st.ask_segment(1, 1, n, m[b[i]], nr);
            ll have2 = dr.ask_segment(1, 1, n, 1, m[b[i]]);
            cnt += have1 * have2;
            st.array[m[b[i]]] = 1;
            dr.array[m[b[i + 1]]] = 0;
            st.update_segment(1, 1, n, m[b[i]], m[b[i]]);
            dr.update_segment(1, 1, n, m[b[i + 1]], m[b[i + 1]]);
        }
        cout<<cnt<<'\n';
        


    }
    return 0;
}
