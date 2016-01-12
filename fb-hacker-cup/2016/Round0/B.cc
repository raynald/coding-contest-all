#include<iostream>
#include<map>
#include<string>

using namespace std;

const int MAXN = 1010;

int T, N;
string x, y;
int dp[2][MAXN], f[MAXN];
int ans;
int c;
map<int, int> mmap;
bool flag;
bool v[MAXN];

int main() {
    cin >> T;
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> N;
        cin >> x;
        cin >> y;
        memset(dp, -1, sizeof(dp));
        memset(f, 0, sizeof(f));
        memset(v, 0, sizeof(v));
        mmap.clear();
        c = 0;
        flag = 0;
        for (int i = 0;i < N;i ++) {
            if (x[i] == '.') {
                if (!flag) {
                    flag = 1;
                    c ++;
                }
                dp[0][i] = c;
                f[c] ++;
                mmap[c] = i;
            } else flag = 0;
        }
        flag = 0;
        for (int i = 0;i < N;i ++) {
            if (y[i] == '.') {
                if (!flag) {
                    flag = 1;
                    c ++;
                }
                dp[1][i] = c;
                f[c] ++;
                mmap[c] = i;
            } else flag = 0;
        }
        ans = c;
        for(int i = 1;i <= c;i ++) {
            if (!v[i] && f[i] == 1) {
                int t = mmap[i];
                if (dp[0][t] == i) {
                    if (dp[1][t] > -1 && !v[dp[1][t]]) {
                        v[dp[1][t]] = 1;
                        v[i] = 1;
                        ans --;
                    }
                } else {
                    if (dp[0][t] > -1 && !v[dp[0][t]]) {
                        v[dp[0][t]] = 1;
                        v[i] = 1;
                        ans --;
                    }
                }
            }
        }
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}
