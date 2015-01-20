#include<iostream>
#include<cstdio>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>

using namespace std;

long long gcd(long long x, long long y) {
    if(x>y) return gcd(y, x);
    if(y%x==0) return x; else return gcd(x, y%x);
}

int main() {
    int T;
    int j;
    long long P, Q, Q2;
    long long t;
    string s;
    bool flag;

    cin >> T;
    for(int k=1;k<=T;k++) {
        cin >> s;
        j = 0;
        P = 0;
        Q = 0;
        for(;j<s.length();j++) {
            if(s[j]=='/') break;
            P = P * 10 + (s[j]-'0');
        }
        for(j++;j<s.length();j++) {
            Q = Q * 10 + (s[j]-'0');
        }
        t = gcd(P, Q);
        Q /= t;
        P /= t;
        cout << "Case #" << k << ": ";
        j = 0;
        flag = 1;
        Q2 = Q;
        while(Q2>1) {
            if(Q2 % 2) {
                cout << "impossible" << endl;
                flag = 0;
                break;
            }
            Q2 /= 2;
        }
        if(flag) {
            while(P<Q) {
                P *= 2;
                j ++;
            }
            if(j>40) cout << "impossible" << endl; else cout << j << endl;
        }
    }

    return 0;
}

