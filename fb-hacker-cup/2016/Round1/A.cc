#include <iostream>
#include <vector>

using namespace std;

int T;
int N;
vector<int> D;
int tmp;
int item;
int cnt, ans, ins, old;

int main() {
    ios::sync_with_stdio(false);
    
    cin >> T;
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> N;
        D.clear();
        for (int i = 0;i < N;i ++) {
            cin >> item;
            D.push_back(item);
        }
        cnt = 0;
        old = -1;
        ins = 0;
        ans = 0;
        while (D.size() > 0) {
            tmp = D.back();
            D.pop_back();
            // cout << tmp << " " << ans << " " << cnt << " " << ins << endl;
            if (old == -1 || (old > tmp && old - tmp <= 10)) {
                old = tmp;
                cnt ++;
            } else {
                if (old <= tmp || tmp + (4 - cnt - ins) * 10 < old) {
                    D.push_back(tmp);
                    ins = 4 - cnt;
                } else {
                    cnt ++;
                    ins += (old - tmp - 1) / 10;
                    old = tmp;
                }
            }
            if (ins + cnt == 4) {
                ans += ins;
                ins = 0;
                cnt = 0;
                old = -1;
            }
        }
        if (cnt != 0) ans += 4 - cnt;
        cout << "Case #" << testcase << ": " << ans << endl;
    }

    return 0;
}

