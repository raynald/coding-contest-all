#include<iostream>
#include<queue>

using namespace std;

const int MAXL = 1e6 + 10;

struct cmp {
    long long f;
    int s;
};

int T;
int L, N, M, D;
int W;
long long o[MAXL];
priority_queue<cmp> laundry;
priority_queue<cmp> dry;
long long ans;
cmp now;

inline bool operator<(const cmp &x, const cmp &y) {
    return !((x.f < y.f) || (x.f == y.f && x.s < y.s));
}

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> L >> N >> M >> D;
        while(laundry.size() > 0) laundry.pop();
        for (int i = 0;i < N;i ++) {
            cin >> W;
            laundry.push({W, W});
        }
        for (int i = 0;i < L;i ++) {
            now = laundry.top();
            laundry.pop();
            laundry.push({now.f + now.s, now.s});
            o[i] = now.f;
        }
        if (M >= L) {
            ans = o[L - 1] + D;
        } else {
            while (dry.size() > 0) dry.pop();
            for (int i = 0;i < M;i ++) {
                dry.push({0, 0});
            }
            for (int i = 0;i < L;i ++) {
                now = dry.top();
                dry.pop();
                if (o[i] >= now.f) {
                    dry.push({o[i] + D, 0});
                } else {
                    dry.push({now.f + D, 0});
                }
            }
            for (int i = 1;i < M;i ++) dry.pop();
            ans = dry.top().f;
        }
        cout << "Case #" << testcase << ": " << ans << endl;
    }

    return 0;
}

