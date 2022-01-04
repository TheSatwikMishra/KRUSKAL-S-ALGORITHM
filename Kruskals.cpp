/* Author - Satwik Mishra */
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define INF               923456789987654322
typedef tree<pair<ll, ll>, null_type, less<pair<ll, ll>>, rb_tree_tag, tree_order_statistics_node_update > pbds; // find_by_order, order_of_key
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}
ll msb(ll N) {return (64 - __builtin_clzll(N) - 1);}
template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fr); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
ll mod_sub(ll a, ll b, ll m) {return (((a % m - b % m + m) % m));}
vector<vector<ll>> adj(5e5 + 100);
vector<ll> dis(10, INF);
ll lcm(ll a, ll b) {
    ll val = __gcd(a, b);
    return ((a * b) / val);
}
vector<ll> par(5e5 + 10, 0);
vector<ll> ran(5e5 + 10, 0);
int findpar(ll u) {
    if (par[u] == u) return (u);
    return (par[u] = findpar(par[u]));
}
void unioun(ll u, ll v) {
    u = findpar(u);
    v = findpar(v);
    if (ran[v] < ran[u]) par[v] = u;
    else if (ran[v] > ran[u]) par[u] = v;
    else {
        par[v] = u;
        ran[u]++;
    }
}
void Jai_shree_ganesh(ll N, ll M) {
//cout<<"never give up"<<endl;
//cout << "play to win" << endl;
//cout<<"Case #"<<tt<<": ";
    for (ll i = 0; i <= M; i++) {
        par[i] = i;
    }
    ll sumh = 0, sumf = 0;
    vector<pair<ll, pair<ll, ll>>> v(M), fin;
    for (ll i = 0; i < M; i++) {
        ll a, b, c;
        cin >> a >> b >> c;
        pair<ll, pair<ll, ll>> p = {c, {a, b}};
        v[i] = p;
        sumh += c;
    }
    sort(all(v));
    for (ll i = 0; i < M; i++) {
        ll a = v[i].sc.fr;
        ll b = v[i].sc.sc;
        ll c = v[i].fr;
        if (findpar(a) != findpar(b)) {
            unioun(a, b);
            fin.pb(v[i]);
         //   sumf += c;
        }
    }
    //cout << sumh - sumf << "\n";
    // jo bhi edges vector fin me hai wo MST bna rhi hai and thisis the code for kruskals algorithm
}
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("Input.txt", "r", stdin);
    freopen("Output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    //cin >> t;
    for (ll i = 1; i >= 0; i++)
    {
        ll N, M;
        cin >> N >> M;
        if (N == 0 && M == 0) break;
        Jai_shree_ganesh(N, M);
    }
    return (0);
}
