#include<iostream>
#include<map>

using namespace std;

const int MAXN = 100010;

int T, N;
long long P;
long long B[MAXN];
long long ans;
long long sum;
int k;

int main() {
    cin >> T;
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> N >> P;
        for (int i = 0;i < N;i ++) {
            cin >> B[i];
        }
        sum = 0;
        k = 0;
        ans = 0;
        for (int i = 0;i < N;i ++) {
            if (k < i) k = i;
            while(k < N && B[k] + sum <= P) {
                sum += B[k];
                k ++;
            }
            ans += k - i;
            if (k != i ) sum -= B[i];
        }
        cout << "Case #" << testcase << ": " << ans << endl;
    }
    return 0;
}
