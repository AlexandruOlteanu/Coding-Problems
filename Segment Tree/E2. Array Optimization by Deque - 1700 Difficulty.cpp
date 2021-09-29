/*
    Programmer : Alexandru Olteanu
    Link To Problem : https://codeforces.com/contest/1579/problem/E2
*/
#include<bits/stdc++.h>
using namespace std;
// GCC Optimizations
// #pragma GCC optimize("Ofast");
// #pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt")
// #pragma GCC target("abm,mmx,avx,avx2,tune=native")
// #pragma GCC optimize(3)
// #pragma GCC optimize("inline")
// #pragma GCC optimize("-fgcse")
// #pragma GCC optimize("-fgcse-lm")
// #pragma GCC optimize("-fipa-sra")
// #pragma GCC optimize("-ftree-pre")
// #pragma GCC optimize("-ftree-vrp")
// #pragma GCC optimize("-fpeephole2")
// #pragma GCC optimize("-ffast-math")
// #pragma GCC optimize("-fsched-spec")
// #pragma GCC optimize("unroll-loops")
// Useful
mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());
#define FastEverything  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define HighPrecision cout<<fixed<<setprecision(17);
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll const mod=1000000007LL;
ll const mod2 = 100000000LL;
ll const md=998244353LL;
ll mypowr(ll a,ll b, ll mod1) {ll res=1;if(b<0)b=0;a%=mod1; assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a%mod1;a=a*a%mod1;}return res;}
ll mypow(ll a,ll b) {ll res=1;if(b<0)b=0;assert(b>=0);
for(;b;b>>=1){if(b&1)res=res*a;a=a*a;}return res;}
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(), x.rend()

// ifstream in("input.txt");
// ofstream out("output.txt");
// #define cin in
// #define cout out

const ll infll = 9e18;
const int inf = 2e9;
const ll maxn = 2e5 + 2;

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
        return a + b;       //Probably it needs changes
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
                lazy[node * 2] ^= 1;                    //Probably it needs changes
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

map<int, int> p;
int a[maxn], b[maxn];

int main()
{
    FastEverything
    HighPrecision
    int test = 1;
    cin>>test;
    for(int tt = 1; tt <= test; ++tt){
       int n;
       cin>>n;
       for(int i = 1; i <= n; ++i){
           cin>>a[i];
           b[i] = a[i];
       }
       sort(b + 1, b + n + 1);
       int nr = 1;
       for(int i = 1; i <= n; ++i){
           if(p[b[i]] == 0){
               p[b[i]] = nr;
               ++nr;
           }
       }
       ll cnt = 0;
       SegmentTree<int> st(n + 1);
       for(int i = 1; i <= n; ++i){
           a[i] = p[a[i]];
           ll ans1 = 0, ans2 = 0;
           if(a[i] != 1){
               ans1 = st.ask_segment(1, 1, n, 1, a[i] - 1);
           }
           if(a[i] != n){
               ans2 = st.ask_segment(1, 1, n, a[i] + 1, n);
           }
           cnt += min(ans1, ans2);
           ++st.array[a[i]];
           st.update_segment(1, 1, n, a[i], a[i]);
       }
       cout<<cnt<<'\n';
       p.clear();

    }    


    return 0;
} 
