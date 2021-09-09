/*
    Programmer : Alexandru_Olteanu
    Link To Problem : https://codeforces.com/contest/1567/problem/E
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
//#pragma GCC optimize("Ofast")
//#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
// Usefull
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
const ll maxn = 3e5 + 2;

/*
    Template created by Alexandru Olteanu
*/
template<typename A>
struct SegmentTree{
    vector<A> array;
    
    struct P {
        ll total = 0;
        ll start = 0;
        ll finish = 0;
        ll finish_start = 0;
        ll start_finish = 0;
        int first_val = 0;
        int last_val = 0;
    };

    vector<P> tree;
    vector<A> lazy;

    SegmentTree(int n){
        array.resize(n);
        tree.resize(4 * n + 1);
        lazy.resize(4 * n + 1);
    }

    P function(P a, P b){
        P c;
        c.total = c.start = c.finish = c.finish_start = 0;
        c.first_val = c.last_val = c.start_finish = 0;
        c.total = a.total + b.total;
        if(a.last_val <= b.first_val){
            c.total += a.finish * b.start;
            c.start_finish = (a.start_finish && b.finish_start);
            c.start = a.start + a.start_finish * b.start;
            c.first_val = a.first_val;
            c.last_val = b.last_val;
            c.finish = b.finish + b.finish_start * a.finish;
            c.finish_start = (b.finish_start && a.start_finish);
        }
        else{
            c.start_finish = 0;
            c.start = a.start;
            c.first_val = a.first_val;
            c.last_val = b.last_val;
            c.finish = b.finish;
            c.finish_start = 0;
        }

        return c;
    }

    void build_segment(int node, int l, int r){
        if(l == r){
            tree[node].total = 1;
            tree[node].start = 1;
            tree[node].finish = 1;
            tree[node].finish_start = 1;
            tree[node].start_finish = 1;
            tree[node].first_val = array[l];
            tree[node].last_val = array[l]; 
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
                tree[node].total = 1;
                tree[node].start = 1;
                tree[node].finish = 1;
                tree[node].finish_start = 1;
                tree[node].start_finish = 1;
                tree[node].first_val = array[l];
                tree[node].last_val = array[l];    
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

    P ask_segment(int node, int l, int r, int L, int R){
        push_segment(node, l, r);
        if(l >= L && r <= R){
            return tree[node];
        }
        int mid = l + (r - l) / 2;
        if(mid < L){
            return ask_segment(node * 2 + 1, mid + 1, r, L, R);
        }
        if(mid >= R){
            return ask_segment(node * 2, l, mid, L, R);
        }
        return function(ask_segment(node * 2, l, mid, L, R), ask_segment(node * 2 + 1, mid + 1, r, L, R));
    }
};




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
          SegmentTree<ll> st(n + 1);
          for(int i = 1; i <= n; ++i){
              cin>>st.array[i];
          }
          st.build_segment(1, 1, n);
          for(int i = 1; i <= k; ++i){
              int p, x, y;
              cin>>p>>x>>y;
              if(p == 1){
                  st.array[x] = y;
                  st.update_segment(1, 1, n, x, x);
                  continue;
              }
              cout<<st.ask_segment(1, 1, n, x, y).total<<'\n';
          }

    }
    return 0;
}
