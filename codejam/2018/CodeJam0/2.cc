#include<bits/stdc++.h>

using namespace std;

int T, N, a;
vector<int> v1, v2;
int ans;
int ansj;

int main() {
    cin >> T;
    for(int iter = 1;iter <= T;iter ++) {
        cin >> N;
        v1.clear();
        v2.clear();
        for(int i = 0;i < N;i ++) {
            cin >> a;
            if (i % 2 == 0) {
                v1.push_back(a);
            } else {
                v2.push_back(a);
            }
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        ans = -1;
        for(int i = 0;i < v2.size();i ++) {
           if (v1[i] > v2[i]) {
               ans = v1[i];
               ansj = i * 2;
               break;
           }
           if (i > 0 && v2[i - 1] > v1[i]) {
               ans = v2[i - 1];
               ansj = i * 2 - 1;
               break;
           }
        }
        if (ans == -1 && v1.size() > v2.size() ) {
            if (v2[v2.size() - 1] > v1[v2.size()]) {
                ans = v2[v2.size() - 1];
                ansj = v2.size() * 2 - 1;
            }
        }
        cout << "Case #" << iter << ": ";
        if (ans > -1) {
            cout << ansj << endl;
        } else {
            cout << "OK" << endl;
        }
    }
    return 0;
}
