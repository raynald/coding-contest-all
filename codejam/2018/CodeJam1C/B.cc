#include<bits/stdc++.h>

using namespace std;

int T, N;
set<int> s;
int a, b;
int pick;
vector<int> c;
map<int, int> m;

int main() {
    cin >> T;
    for (int test = 1;test <= T;test ++) {
        cin >> N;
        s.clear();
        m.clear();
        for(int j = 0;j < N;j ++) {
            s.insert(j);
            m[j] = 0;
        }
        for (int i = 0;i < N;i ++) {
            cin >> a;
            if (a != -1) {
                pick = -1;
                for(int j = 0;j < a;j ++) {
                    cin >> b;
                    if (s.find(b) != s.end()) {
                        if (pick == -1 || m[b] < m[pick]) {
                            pick = b;
                            c.clear();
                        }
                        c.push_back(b);
                    }
                    m[b] ++;
                }
                if (pick > -1) {
                    pick = c[rand() % c.size()];
                    s.erase(pick);
                }
                cout << pick << endl;
            } else {
                return 0;
            }
        }
    }
    return 0;
}
