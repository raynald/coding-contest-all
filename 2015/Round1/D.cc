#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

const int MAXN = 200010;

struct _edge {
    int to;
    int next;
};

int dp[MAXN];
_edge Edge[MAXN];
int start[MAXN];
int f[MAXN][4];

int minh(int x, int y) {
    if(x<y) return x; else return y;
}

stack<int> st;
bool v[MAXN];

void dfs() {
    int ans;
    int point;
    int x;

    memset(v, 0, sizeof(v));
    st.push(1);
    while(st.size()>0) {
        x = st.top();
        if (v[x] || start[x]==-1) {
            st.pop();
            for(int i = 1;i <= 3; ++i) {
                ans = i;
                for(int j=start[x];j!=-1;j = Edge[j].next) {
                    point = Edge[j].to;
                    if(i==1) ans += minh(f[point][2], f[point][3]);
                    if(i==2) ans += minh(f[point][1], f[point][3]);
                    if(i==3) ans += minh(f[point][2], f[point][1]);
                }
                f[x][i] = ans;
            }
        } else {
            for(int i = start[x];i != -1;i = Edge[i].next) {
                st.push(Edge[i].to);
            }
            v[x] = 1;
       }
    }
}

int main() {
    int T;
    int N;
    int node;
    int edge_count;

    cin >> T;
    for(int testcase=1;testcase<=T;++testcase) {
        cin >> N;
        edge_count = 0;
        memset(start, -1, sizeof(start));
        memset(f, 0, sizeof(f));
        cin >> node;
        for(int i=2;i<=N;i++) {
            cin >> node;
            edge_count ++;
            Edge[edge_count].to = i;
            Edge[edge_count].next = start[node];
            start[node] = edge_count;
        }
        dfs();
        cout << "Case #" << testcase << ": " << minh(f[1][1], minh(f[1][2], f[1][3])) << endl;
    }

    return 0;
}
