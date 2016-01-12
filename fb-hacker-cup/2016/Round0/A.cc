#include<iostream>
#include<map>

using namespace std;

const int MAXN = 2010;

map<int, int> M[MAXN];
int T, N;
int x[MAXN], y[MAXN];
int ans;

int main() {
    cin >> T;
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> N;
        for (int i = 0;i < N;i ++) {
            cin >> x[i] >> y[i];
            M[i].clear();
        }
        for (int i = 0;i < N;i ++) {
            for (int j = i + 1;j < N;j ++) {
                int tmp = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
                M[i][tmp] ++;
                M[j][tmp] ++;
            }
        }
        ans = 0;
        for (int i = 0;i < N;i ++) {
            for (auto x = M[i].begin();x != M[i].end();x ++) {
                if (x -> second > 1) 
                    ans += x -> second * (x -> second - 1) / 2;
            }
        }
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}
