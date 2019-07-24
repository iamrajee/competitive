#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define next Next
//============================
typedef long long ll;
typedef long double ld;
typedef complex<ld> cd;
// typedef pair<int, int> pi;
typedef pair<ll,ll> pl;
typedef pair<ld,ld> pd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef vector<ll> vl;
// typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<cd> vcd;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;


#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define shandom_ruffle random_shuffle
const int MOD = 1000000007;
const ll INF = 1e18;
const int MX = 100001; //check the limits, dummy

//=======================================================
#define re return
#define fi first
#define se second
#define mp make_pair
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) ((int)(x).size())
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define y0 y32479
#define y1 y95874
#define next next239
#define prev prev239
#define fill(x, y) memset(x, y, sizeof(x))
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt(abs(x))
#define unq(x) (x.resize(unique(all(x)) - x.begin()))
#define ba back()
#define popcount __builtin_popcountll
#define fastIO() {ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}
#define in(x) int x; cin >> x;
#define in1(x) int x; cin >> x; x--;
#define inll(x) ll x; cin >> x;
#define ins(x) string x; cin >> x;

template<class T> void print(T v) { cout << sz(v) << endl; for (auto x : v) cout << x << ' '; cout << endl; };
template<class T> void print1(T v) { cout << sz(v) << endl; for (auto x : v) cout << x + 1 << ' '; cout << endl; };
template<class T1, class T2> ostream& operator << (ostream &o, pair<T1, T2> x) {re o << x.fi << ' ' << x.se;}
template<class T1, class T2> istream& operator >> (istream &o, pair<T1, T2> &x) {re o >> x.fi >> x.se;}
template<class T1, class T2> pair<T1, T2> operator + (pair<T1, T2> a, pair<T1, T2> b) {a.fi += b.fi; a.se += b.se; re a;}
template<class T1, class T2> pair<T1, T2> operator - (pair<T1, T2> a, pair<T1, T2> b) {a.fi -= b.fi; a.se -= b.se; re a;}
template<class T1, class T2> void operator += (pair<T1, T2> &a, pair<T1, T2> b) {a.fi += b.fi; a.se += b.se;}
template<class T1, class T2> void operator -= (pair<T1, T2> &a, pair<T1, T2> b) {a.fi -= b.fi; a.se -= b.se;}

int n,m;
int i,j,k,flag,sum,count;
int a,b,t;
char c;
string s;
int main(){
    cin>>n;
    for(i=0;i<n;i++){
        cin>>t;
    }
    return 0;
}