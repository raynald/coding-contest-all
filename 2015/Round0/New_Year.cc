#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<list>
#include<set>
#include<deque>
#include<stack>
/*
 * bitset
 * functional
 * numeric
 * utility
 * ctime
 * memory.h
 * cassert
 */

#define EPS (1e-9)
#define INF ((int)2e9)
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i=0;i<(int)(n);++i)
#define ford(i, n) for (int i= (int)(n)-1; i>=0;--i)
#define fore(i, a, b) for(int i= (int)(a);i<=(int)(b);++i)

#ifdef LOCAL
#define debug(x) {cerr <<#x <<" = " <<x <<"\n"; }
#define debug2(x, y) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<"\n";}
#define debug3(x, y, z) {cerr <<#x <<" = " <<x <<", "<<#y <<" = " <<y <<", "<<#z<<" = "<<z<<"\n";}
#define debugv(x) {{cerr <<#x <<" = "; FORE(itt, (x)) cerr <<*itt <<", "; cerr <<"\n"; }}
using std::cerr;
#else
#define debug(x)
#define debug2(x, y)
#define debug3(x, y, z)
#define debugv(x)
#define cerr if(0)cout
#endif

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vill;
typedef vector<vill> vvill;

const int MAXH = int(1e7);

int T, N, GP, GC, GF;
int p,c,f;
int P[21];
int C[21];
int F[21];

bool search(int x) {
    bool flag=0;
    if(x==N) return 0;
    if(P[x]<=p && C[x] <= c && F[x] <= f) {
        p -= P[x];
        c -= C[x];
        f -= F[x];
        if(p+c+f==0) return 1; 
        if(search(x+1)) return 1;
        p += P[x];
        c += C[x];
        f += F[x];
    }
    return search(x+1);
}

int main() {
    cin >> T;
    for(int t=1;t<=T;t++) {
        cin >> GP >> GC >> GF;
        cin >> N;
        for(int i=0;i<N;i++) {
            cin >> P[i] >> C[i] >> F[i];
        }
        cout << "Case #" << t << ": ";
        p = GP; c = GC; f = GF;
        if(search(0)) cout << "yes" << endl; else cout << "no" << endl;
    }
    return 0;
}
