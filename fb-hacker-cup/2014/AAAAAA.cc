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

const int MAXH = int(5e2+10);

int main() {
    int T;
    int N, M;
    char mat[MAXH][MAXH];
    char ch;
    int sum[MAXH];
    int dp[MAXH][MAXH];
    int rev_dp[MAXH][MAXH];
    int ans;

    cin >> T;
    for(int t = 1; t <= T; ++t) {
        cin >> N >> M;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                cin >> ch;
                while (ch!='.' && ch!='#') cin >> ch;
                mat[i][j] = ch;
            }
        }
        ans = 0;
        for(int i=0;i<N;i++) {
            for(int j=0;j<M;j++) {
                if(mat[i][j] == '.') {
                    if(i==0 && j==0) dp[i][j] = 1;
                    else if(i==0) dp[i][j] = dp[i][j-1] + 1;
                    else if(j==0) dp[i][j] = dp[i-1][j] + 1;
                    else dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + 1;
                } else dp[i][j] = 0;
                if(dp[i][j]>ans) ans = dp[i][j];
            }
        }
        for(int i=N-1;i>=0;i--) {
            for(int j=M-1;j>=0;j--) {
                if(mat[i][j] == '.') {
                    if(i==N-1 && j==M-1) if(mat[i][j]=='.') rev_dp[i][j] = 1; else rev_dp[i][j] = 0;
                    else if(i==N-1) rev_dp[i][j] = rev_dp[i][j+1] + 1;
                    else if(j==M-1) rev_dp[i][j] = rev_dp[i+1][j] + 1;
                    else rev_dp[i][j] = max(rev_dp[i+1][j], rev_dp[i][j+1]) + 1;
                } else rev_dp[i][j] = 0;
            }
        }
        for(int i=1;i<N-1;i++) {
            sum[0] = 0;
            for(int j=0;j<M;j++) {
                if(mat[i][j]=='.') sum[j+1]=sum[j]+1; else sum[j+1]=0;
            }
            for(int j=0;j<M;j++) {
                for(int k=j;j<M;j++) {
                    if(sum[k+1]-sum[j] == k - j + 1 && mat[i][j] == '.' && mat[i][k]=='.') {
                        if(dp[i-1][k]>0 && dp[i-1][k] + rev_dp[i+1][j] + k - j + 1 > ans) 
                            ans = dp[i-1][k] + rev_dp[i+1][j] + k - j + 1;
                    }
                }
            }
        }
        for(int j=1;j<M-1;j++) {
            sum[0] = 0;
            for(int i=0;i<N;i++) {
                if(mat[i][j]=='.') sum[i+1]=sum[i]+1; else sum[i+1]=0;
            }
            for(int i=0;i<N;i++) {
                for(int k=i;k<N;k++) {
                    if(sum[k+1]-sum[i] == k - i + 1 && mat[i][j] == '.' && mat[k][j]=='.') {
                        if(dp[k][j-1]>0 && dp[k][j-1] + rev_dp[i][j+1] + k - i + 1 > ans)  {
                            ans = dp[k][j-1] + rev_dp[i][j+1] + k - i + 1;
                        }
                    }
                }
            }
        }
        cout << "Case #" << t << ": " << ans << endl;
    }

    return 0;
}
