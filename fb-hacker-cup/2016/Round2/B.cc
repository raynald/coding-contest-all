#include<bits/stdc++.h>

using namespace std;

int T;
int N, K;
long double p, tmp, c, tt;
long double f[3010];

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> N;
        cin >> K;
        cin >> p;
        memset(f, 0, sizeof(f));
        if (p > 0 && p < 1) {
            for (int i = K;i <= N;i ++) {
                tmp = 1; c = 1;
                for (int j = 0;j < i;j ++) {
                    tmp *= 1 - p;
                }
                tt = 1 - c * tmp;
                for (int j = 1;j < K;j ++) {
                    c = c * (i + 1 - j) / j;
                    tmp *= p / (1 - p);
                    tt -= c * tmp;
                }
                f[i] = tt;
                for (int j = i - K;j >= K;j --) {
                    if (f[j] + f[i - j] > f[i]) {
                        f[i] = f[j] + f[i - j];
                    }
                }
            }
        } else {
            if (p == 1) {
                f[N] = N / K;
            }
        }
        if (f[N] < 0) f[N] = - f[N];
        cout << fixed;
        cout << "Case #" << testcase << ": " << setprecision(10) << f[N] << endl;
    }

    return 0;
}
