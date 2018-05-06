#include<bits/stdc++.h>

using namespace std;

map<string, int> mmap;

int T;
int N, L;
vector<string> v;
set<string> s, t, w;
string a;

string find() {
    for (int i = 0;i < L;i ++) {
        t = w;
        w.clear();
        for (int j = 0 ;j < N;j ++) {
            w.insert(v[j].substr(0, i + 1));
        }
        for (auto item: t) {
            for (int k = 0;k < N;k ++) {
                string temp = (item + v[k][i]);
                if (w.find(temp) == w.end()) {
                    return temp + v[k].substr(i + 1);
                }
            }
        }
    }
    return "-";
}

int main() {
    cin >> T;
    for (int test = 1;test <= T;test ++) {
        cin >> N;
        cin >> L;
        s.clear();
        v.clear();
        w.clear();
        for (int i = 0;i < N;i ++) {
            cin >> a;
            s.insert(a);
            v.push_back(a);
        }
        cout << "Case #" << test << ": " << find() << endl;
    }
    return 0;
}

