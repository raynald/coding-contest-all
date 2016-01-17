#include<iostream>
#include<iomanip>

using namespace std;

const int MAXN = 1e5 + 10;

int T;
long long A, B;
int N;
long long C[MAXN];
long long sum;
long double ans, tmp;
int rA, rB, dA, dB;
long double answer;

int main() {
    ios::sync_with_stdio(false);

    cin >> T;
    for (int testcase = 1;testcase <= T;testcase ++) {
        cin >> N >> A >> B;
        sum = 0;
        ans = 0;
        tmp = 0;
        for (int i = 0;i < N;i ++) {
            cin >> C[i];
            sum += C[i];
        }
        dA = A; dB = B;
        A = A % sum;
        rA = sum - A;
        answer = (dB - dA) * 2;
        for (int i = 0;i < N;i ++) {
            if (A < C[i]) {
                ans += (C[i] + A) / answer * (C[i] - A);
                for (int j = i + 1;j < N;j ++) {
                    ans += C[j] / answer * C[j];
                }
                break;
            } else {
                A -= C[i];
            }
        }
        for (int i = 0;i < N;i ++) {
            tmp += C[i] / answer * C[i];
        }
        B = B % sum;
        rB = sum - B;
        for (int i = 0;i < N;i ++) {
            if (B < C[i]) {
                ans += B / answer * B;
                break;
            } else {
                ans += C[i] / answer * C[i]; 
                B -= C[i];
            }
        }
        ans += (((dB - (sum - rB)) - (dA + rA)) / sum) * tmp;
        cout << "Case #" << testcase << ": " << fixed << setprecision(10) << ans << endl;
    }

    return 0;
}

// pay attentin to overflow
