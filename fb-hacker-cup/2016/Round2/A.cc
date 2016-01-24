#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 10;

int T;
int N;
string str_a, str_b;
int lft[MAXN];
int rgt[MAXN];
int change;
int ans;

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> N;
        cin >> str_a;
        cin >> str_b;
        change = 0;
        for (int i = 0;i < N;i ++) {
            if (i == 0 || str_b[i] != str_b[i - 1]) change ++;
            if (str_a[i] == str_b[i]) {
                if (i == 0) lft[i] = 0; else lft[i] = lft[i - 1];
            } else {
                lft[i] = change;
            }
            // cerr << i << " " << lft[i] << endl;
        }
        change = 0;
        for (int i = N - 1;i >= 0;i --) {
            if (i == N - 1 || str_b[i] != str_b[i + 1]) change ++;
            if (str_a[i] == str_b[i]) {
                if (i == N - 1) rgt[i] = 0; else rgt[i] = rgt[i + 1];
            } else {
                rgt[i] = change;
            }
            // cerr << i << " " << rgt[i] << endl;
        }
        ans = rgt[0];
        for (int i = 0;i < N - 1;i ++) {
            if (max(lft[i], rgt[i + 1]) < ans) {
                ans = max(lft[i], rgt[i + 1]);
            }
        }
        if (lft[N - 1] < ans) ans = lft[N - 1];
        cout << "Case #" << testcase << ": " << ans << endl;
    }

    return 0;
}
