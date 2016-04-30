#include<bits/stdc++.h>

using namespace std;

int T;
string A, B;
int first;
string ans_A, ans_B;
int len;
string ta, tb;
int temp;

bool borrow(string &A, string &B, int x) {
    int p = x;
    while (p >= 0) {
        if (A[p] == '?' && B[p] == '?') {
            A[p] = '1';
            B[p] = '0';
            return 1;
        }
        if (A[p] == '?' && B[p] < '9') {
            A[p] = '0' + (B[p] - '0' + 1);
            return 1;
        }
        if (B[p] == '?' && A[p] > '0') {
            B[p] = '0' + (A[p] - '0' - 1);
            return 1;
        }
        if (A[p] == '?') A[p] = '0';
        if (B[p] == '?') B[p] = '9';
        p --;
    }
    return 0;
}

int main() {
    cin >> T;
    for(int testcase=1;testcase<=T;testcase++) {
        cin >> A >> B;
        ans_A = A;
        ans_B = B;
        first = -1;
        len = A.length();
        for (int i = 0;i < len;i ++) {
            if (A[i] != '?' && B[i] != '?' && A[i] != B[i]) {
                first = i;
                break;
            }
        }
        if (first == -1) {
            for(int i = 0;i < len;i ++) {
                if (A[i] == '?' && B[i] == '?') {
                    ans_A[i] = '0';
                    ans_B[i] = '0';
                } else {
                    if (A[i] == '?') ans_A[i] = B[i];
                    if (B[i] == '?') ans_B[i] = A[i];
                }
            }
        } else {
            if (A[first] < B[first]) {
                for(int i = 0;i < first;i ++) {
                    if (A[i] == '?' && B[i] == '?') {
                        ans_A[i] = '0';
                        ans_B[i] = '0';
                    } else {
                        if (A[i] == '?') ans_A[i] = B[i];
                        if (B[i] == '?') ans_B[i] = A[i];
                    }
                }
                for(int i = first + 1;i < len;i ++) {
                    if (A[i] == '?') ans_A[i] = '9';
                    if (B[i] == '?') ans_B[i] = '0';
                }
                ta = ans_A;
                tb = ans_B;
                ans_A = A;ans_B = B;
                if (borrow(ans_A, ans_B, first - 1)) {
                    //cout << ans_A << " " << ans_B << endl;
                    for(int i = 0;i < first;i ++) {
                        if (ans_A[i] == '?' && ans_B[i] == '?') {
                            ans_A[i] = '0';
                            ans_B[i] = '0';
                        } else {
                            if (ans_A[i] == '?') ans_A[i] = B[i];
                            if (ans_B[i] == '?') ans_B[i] = A[i];
                        }
                    }
                    for(int i = first + 1;i < len;i ++) {
                        if (A[i] == '?') ans_A[i] = '0';
                        if (B[i] == '?') ans_B[i] = '9';
                    }
                    //cout << "fuck4" << ans_A << ", " << ans_B << ", "<< ta << ", "<< tb << endl;
                    if ((abs(stoll(ans_A)-stoll(ans_B)) > abs(stoll(ta)-stoll(tb)))
                            || ( (abs(stoll(ans_A)-stoll(ans_B)) == abs(stoll(ta)-stoll(tb))) && 
                                (ta < ans_A || (ta == ans_A && tb < ans_B)) )) {
                        ans_A = ta;
                        ans_B = tb;
                    }
                } else {
                    ans_A = ta;
                    ans_B = tb;
                }
            } else {
                for(int i = 0;i < first;i ++) {
                    if (A[i] == '?' && B[i] == '?') {
                        ans_A[i] = '0';
                        ans_B[i] = '0';
                    } else {
                        if (A[i] == '?') ans_A[i] = B[i];
                        if (B[i] == '?') ans_B[i] = A[i];
                    }
                }
                for(int i = first + 1;i < len;i ++) {
                    if (A[i] == '?') ans_A[i] = '0';
                    if (B[i] == '?') ans_B[i] = '9';
                }
                ta = ans_A;
                tb = ans_B;
                ans_A = A;ans_B = B;
                if (borrow(ans_B, ans_A, first - 1)) {
                    for(int i = 0;i < first;i ++) {
                        if (ans_A[i] == '?' && ans_B[i] == '?') {
                            ans_A[i] = '0';
                            ans_B[i] = '0';
                        } else {
                            if (ans_A[i] == '?') ans_A[i] = B[i];
                            if (ans_B[i] == '?') ans_B[i] = A[i];
                        }
                    }
                    for(int i = first + 1;i < len;i ++) {
                        if (A[i] == '?') ans_A[i] = '9';
                        if (B[i] == '?') ans_B[i] = '0';
                    }
//                    cout << "fuck3" << ans_A << ", " << ans_B << ", "<< ta << ", "<< tb << endl;
                     if ((abs(stoll(ans_A)-stoll(ans_B)) > abs(stoll(ta)-stoll(tb)))
                            || ( (abs(stoll(ans_A)-stoll(ans_B)) == abs(stoll(ta)-stoll(tb))) && 
                                (ta < ans_A || (ta == ans_A && tb < ans_B)) )) {
                        ans_A = ta;
                        ans_B = tb;
                    }
                } else {
                    ans_A = ta;
                    ans_B = tb;
                }
 
            }
        }
        cout << "Case #" << testcase << ": " << ans_A << " " << ans_B << endl;
    }
    return 0;
}
