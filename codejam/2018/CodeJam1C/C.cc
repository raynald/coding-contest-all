#include<bits/stdc++.h>

using namespace std;

int T, N;
int a;
vector<int> w;
vector<int> f1, f2, v1, v2;
bool cont;
int ans;

int main() {
    cin >> T;
    for(int test=1;test<=T;test++) {
        cin >> N;
        w.clear();
        for(int i = 0;i < N;i ++) {
            cin >> a;
            w.push_back(a);
        }
        f1.clear();
        v1.clear();
        for(int i = 0;i < N;i ++) {
            f1.push_back(1);
            v1.push_back(w[i]);
            ans = 1;
        }
        for(int k = 2;k <= N;k ++) {
            f2 = f1;
            v2 = v1;
            cont = false;
            for(int i = 0;i < k - 1;i ++) {
                f1[i] = 0;
                v1[i] = 0;
            }
            for(int i = k - 1;i < N;i ++) {
                f1[i] = 0;
                for(int j = 0;j < i;j ++) {
                    if ((f2[j] + 1 > f1[i] && v2[j] <= w[i] * 6) || (f2[j] + 1 == f1[i] && v2[j] + w[i] < v1[i])) {
                        f1[i] = f2[j] + 1;
                        v1[i] = v2[j] + w[i];
                        // cout << j << " " << i << " " << f1[i] << " " << v1[i] << endl;
                        cont = true;
                        if (f1[i] > ans) ans = f1[i];
                    }
                }
            }
            if (!cont) break;
        }
        cout << "Case #" << test << ": " << ans << endl;
    }
    return 0;
}


// f[i][k] = max(f[j][k - 1] + 1) (j < i and v[j][k - 1] * 6 < w[i])

