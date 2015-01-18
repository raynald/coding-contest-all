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

int T;
int N;
int M;
char ch;
int move[4][2] = {0,-1,-1,0,0,1,1,0};
int ans;
bool dead[4][110][110];
bool f[4][110][110];
char mat[110][110];
int sx, sy, gx, gy;

struct cmp {
    int x;
    int y;
    int d;
    cmp() {}
    cmp(int a, int b, int c): x(a), y(b), d(c) {}
};

vector<cmp> laser;

struct queue_node {
    int px;
    int py;
    int step;
    queue_node() {}
    queue_node(int x, int y, int z): px(x), py(y), step(z) {}
};

queue<queue_node> q;

bool valid(int x, int y) {
    if(x<0 || x>=N || y<0 || y>=M) return 0;
    if(mat[x][y]=='.') return 1; else return 0;
}

int main() {
    cin >> T;
    for (int t=1;t<=T;t++) {
        cin >> N >> M;
        memset(dead, 0, sizeof(dead));
        memset(f, 0, sizeof(f));
        laser.clear();
        for (int i=0;i<N;i++) {
            for (int j=0;j<M;j++) {
                cin >> ch;
                while (ch!='.' && ch!='#' && ch!='S' && ch!='G' &&
                        ch!='<' && ch!='>' && ch!='^' && ch!='v') {
                    cin >> ch;
                }
                if (ch=='S') {
                    sx = i;
                    sy = j;
                    ch = '.';
                }
                if (ch=='G') {
                    gx = i;
                    gy = j;
                    ch = '.';
                }
                if (ch == '<') {
                    laser.push_back(cmp(i,j,0));
                    ch = '#';
                }
                if (ch == '^') {
                    laser.push_back(cmp(i,j,1));
                    ch = '#';
                }
                if (ch == '>') {
                    laser.push_back(cmp(i,j,2));
                    ch = '#';
                }
                if (ch == 'v') {
                    laser.push_back(cmp(i,j,3));
                    ch = '#';
                }
                mat[i][j] = ch;
            }
        }
        for(int j=0;j<4;j++) {
            for(int i=0;i<laser.size();i++) {
                int direction = (laser[i].d+j)%4;
                int tx = laser[i].x;
                int ty = laser[i].y;
                while(1) {
                    tx += move[direction][0];
                    ty += move[direction][1];
                    if(valid(tx, ty)) {
                        dead[j][tx][ty] = 1;
                    } else break;
                }
            }
        }
        while(!q.empty()) q.pop();
        q.push(queue_node(sx,sy,0));
        f[0][sx][sy]= 1;
        ans = -1;
        while(!q.empty()) {
            queue_node tt = q.front();
            q.pop();
            if (tt.px == gx && tt.py == gy && !dead[tt.step%4][gx][gy]) {
                ans = tt.step;
                break;
            }
            for(int j = 0;j < 4;j++) {
                int erx = tt.px+move[j][0];
                int ery = tt.py+move[j][1];
                if(valid(erx, ery) && !dead[(tt.step+1)%4][erx][ery] && !f[(tt.step+1)%4][erx][ery]) {
                    f[(tt.step+1)%4][erx][ery] = 1;
                    q.push(queue_node(erx, ery, tt.step+1));
                }
            }
        }
        cout << "Case #" << t << ": ";
        if(ans > -1) cout << ans << endl;
        else cout << "impossible" << endl;
    }
    return 0;
}

